import java.util.ArrayList;
import java.util.Scanner;


public class Interpreter {
    ArrayList<Tuple> tuple;
    SymbolTable table;
    int tupleIndex = 0;
    
    int int1, int2, int3;
    float float1, float2, float3;
    String string1, string2, string3;

    Scanner sc = new Scanner(System.in);

    public Interpreter(ArrayList<Tuple> tuple, SymbolTable table) {
        this.tuple = tuple;
        this.table = table;
    }

    public void start() {
        
        do{
            switch(currentTuple().getInstruction()) {
                
                case "declaracion":
                    if(resolveType(0).equals("ENTERO")) {
                        if(isNumeric(2)){
                            tableSetInt(0, tupleGetInt(2));
                        } else {
                            tableSetInt(0, tableGetInt(2));
                        }
                    } else if(resolveType(0).equals("FLOTANTE")) {
                        if(isNumeric(2)){
                            tableSetFloat(0, tupleGetFloat(2));
                        } else {
                            tableSetFloat(0, tableGetFloat(2));
                        }
                    } else {
                        throw new RuntimeException("No se pudo capturar el valor");
                    }
                    setNextTrue();
                    break;


                case "asignacion":
                    if(isNumeric(1)) {
                        int1 = tupleGetInt(1);
                    } else {
                        int1 = tableGetInt(1);
                    }

                    if(currentTuple().getParams().length > 2) {
                        if(isNumeric(3)) {
                            int2 = tupleGetInt(3);
                        } else {
                            int2 = tableGetInt(3);
                        }

                        string1 = getString(2);
                        switch(string1) {
                            case "+":
                                tableSetInt(0, int1 + int2);
                                break;
                            
                            case "-":
                                tableSetInt(0, int1 - int2);
                                break;
                
                            case "/":
                                tableSetInt(0, int1 / int2);
                                break;
                
                            case "*":
                                tableSetInt(0, int1 * int2);
                                break;
                
                            case "%":
                                tableSetInt(0, int1 % int2);
                                break;
                        }
                        setNextTrue();
                        break;
                    }

                    tableSetInt(0, int1);
                    setNextTrue();
                    break;
                        
                
                case "leer":
                    System.out.print(getStringNoQuotes(0));
                    if(resolveType(1).equals("ENTERO")) {
                        int1 = sc.nextInt();
                        tableSetInt(1, int1);

                    } else if(resolveType(1).equals("FLOTANTE")){
                        float1 = sc.nextFloat();
                        tableSetFloat(1, float1);

                    } else {
                        throw new RuntimeException("No se pudo capturar el valor");
                    }
                    setNextTrue();
                    break;


                case "escribir":
                    if(!isVariable(0)) {
                        string1 = getStringNoQuotes(0);
                    } else {
                        string1 = String.valueOf(tableGetInt(0));
                    }
                    string2 = string1;

                    if(currentTuple().getParams().length > 1) {
                        string2 = string1.concat(String.valueOf(table.resolve(currentTuple().getParam(1)).intValue));
                    }
                    
                    System.out.println(string2);
                    setNextTrue();
                    break;


                case "si":
                case "mientras":
                    if(isNumeric(0)) {
                        int1 = Integer.parseInt(currentTuple().getParam(0));
                    } else {
                        int1 = tableGetInt(0);
                    }

                    if(isNumeric(2)) {
                        int2 = Integer.parseInt(currentTuple().getParam(2));
                    } else {
                        int2 = tableGetInt(2);
                    }

                    string1 = getStringNoQuotes(1);

                    if(condition(int1, string1, int2)) {
                        setNextTrue();
                    } else {
                        setNextFalse();
                    }
                    break;


                case "repite":
                    if(isNumeric(0)) {
                        int1 = Integer.parseInt(currentTuple().getParam(0));
                    } else {
                        int1 = tableGetInt(0);
                    }                    

                    if(isNumeric(2)) {
                        int2 = Integer.parseInt(currentTuple().getParam(2));
                    } else {
                        int2 = tableGetInt(2);
                    }

                    if(getString(3).equals("notStarted")) {
                        tableSetInt(0, int1);
                        tupleGetString(3, "started");
                    } else {
                        int3 = tableGetInt(0);
                        tableSetInt(0, int3 + 1);
                    }

                    if(int1 < int2) {
                        setNextTrue();
                    } else {
                        setNextFalse();
                    }

                    break;
                   
            }   

        }while(!currentTuple().getInstruction().equals("fin"));
    }


    //*----TUPLE MANAGMENT FUNCTION----*/
    public Tuple currentTuple() {
        return tuple.get(tupleIndex);
    }

    public void setNextTrue() {
        tupleIndex = currentTuple().getTrueLine() - 1;
    }

    public void setNextFalse() {
        tupleIndex = currentTuple().getFalseLine() - 1;
    }

    //*Tuple Data-*/
    public void tableSetInt(int index, int value) {
        table.resolve(currentTuple().getParam(index)).setInt(value);
    }

    public int tableGetInt(int index) {
        return table.resolve(currentTuple().getParam(index)).intValue;
    }

    public void tableSetFloat(int index, float value) {
        table.resolve(currentTuple().getParam(index)).setFloat(value);
    }

    public float tableGetFloat(int index) {
        return table.resolve(currentTuple().getParam(index)).floatValue;
    }

    public void tupleGetString(int index, String string) {
        currentTuple().setParam(index, string);
    }

    public int tupleGetInt(int index) {
        return Integer.parseInt(currentTuple().getParam(index));
    }

    public float tupleGetFloat(int index) {
        return Float.parseFloat(currentTuple().getParam(index));
    }


    //*----MISC----*/
    public String resolveType(int index) {
        String temp = table.resolve(currentTuple().getParam(index)).type.getName();

        if(temp.equals("entero"))
            return "ENTERO";

        if(temp.equals("flotante"))
            return "FLOTANTE";

        return "INVALID"; 
    }

    public boolean isNumeric(int index) {
        String string = currentTuple().getParam(index);
        try {
            Integer.parseInt(string);
        } catch (NumberFormatException nfe) {
            return false;
        }
        return true;
    }

    public String getString(int index) {
        return currentTuple().getParam(index);
    }

    public String getStringNoQuotes(int index) {
        return getString(index).replace((char) 34, (char) 0);
    }

    public boolean condition(int var1, String cond, int var2) {
        switch(cond){
            case "<":
                return var1 < var2;

            case ">":
                return var1 > var2;

            case "==":
                return var1 == var2;

            case "<=":
                return var1 <= var2;

            case ">=":
                return var1 >= var2;

            case "!=":
                return var1 != var2;

            default:
                return false;
        }
    }

    public boolean isVariable(int index) {
        return !currentTuple().getParam(index).contains("\"");
    }

}
