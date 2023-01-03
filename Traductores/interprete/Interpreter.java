import java.util.ArrayList;
import java.util.Scanner;

public class Interpreter {
    ArrayList<Tuple> tuplas;
    SymbolTable tablaDeSimbolos;
    int tupleIndex = 0;

    int enteroUno, enteroDos, enteroTres;
    float flotanteUno, flotanteDos, flotanteTres;
    String cadenaUno, cadenaDos, cadenaTres;

    Scanner sc = new Scanner(System.in);

    public Interpreter(ArrayList<Tuple> tuplas, SymbolTable tablaDeSimbolos) {
        this.tuplas = tuplas;
        this.tablaDeSimbolos = tablaDeSimbolos;
    }

    public void start() {
        do {
            switch (currentTuple().getInstruction()) {
                case "declaracion":
                    if (resolveType(0).equals("ENTERO")) {
                        if (isNumeric(2)) {
                            tableSetInt(0, tupleGetInt(2));
                        } else {
                            tableSetInt(0, tableGetInt(2));
                        }
                    } else if (resolveType(0).equals("FLOTANTE")) {
                        if (isNumeric(2)) {
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
                    if (isNumeric(1)) {
                        enteroUno = tupleGetInt(1);
                    } else {
                        enteroUno = tableGetInt(1);
                    }

                    if (currentTuple().getParameters().length > 2) {
                        if (isNumeric(3)) {
                            enteroDos = tupleGetInt(3);
                        } else {
                            enteroDos = tableGetInt(3);
                        }

                        cadenaUno = getString(2);
                        switch (cadenaUno) {
                            case "+":
                            case "mas":
                                tableSetInt(0, enteroUno + enteroDos);
                                break;

                            case "-":
                            case "menos":
                                tableSetInt(0, enteroUno - enteroDos);
                                break;

                            case "/":
                            case "entre":
                                tableSetInt(0, enteroUno / enteroDos);
                                break;

                            case "*":
                            case "por":
                                tableSetInt(0, enteroUno * enteroDos);
                                break;

                            case "%":
                            case "modulo":
                                tableSetInt(0, enteroUno % enteroDos);
                                break;
                        }
                        setNextTrue();
                        break;
                    }

                    tableSetInt(0, enteroUno);
                    setNextTrue();
                    break;

                case "leer":
                    System.out.print(getStringNoQuotes(0));
                    if (resolveType(1).equals("ENTERO")) {
                        enteroUno = sc.nextInt();
                        tableSetInt(1, enteroUno);

                    } else if (resolveType(1).equals("FLOTANTE")) {
                        flotanteUno = sc.nextFloat();
                        tableSetFloat(1, flotanteUno);

                    } else {
                        throw new RuntimeException("No se pudo capturar el valor");
                    }
                    setNextTrue();
                    break;

                case "escribir":
                    if (!isVariable(0)) {
                        cadenaUno = getStringNoQuotes(0);
                    } else {
                        cadenaUno = String.valueOf(tableGetInt(0));
                    }
                    cadenaDos = cadenaUno;

                    if (currentTuple().getParameters().length > 1) {
                        cadenaDos = cadenaUno.concat(String.valueOf(tablaDeSimbolos.resolve(currentTuple().getParam(1)).intValue));
                    }

                    System.out.println(cadenaDos);
                    setNextTrue();
                    break;

                case "si":
                case "mientras":
                    if (isNumeric(0)) {
                        enteroUno = Integer.parseInt(currentTuple().getParam(0));
                    } else {
                        enteroUno = tableGetInt(0);
                    }

                    if (isNumeric(2)) {
                        enteroDos = Integer.parseInt(currentTuple().getParam(2));
                    } else {
                        enteroDos = tableGetInt(2);
                    }

                    cadenaUno = getStringNoQuotes(1).toLowerCase();

                    if (condition(enteroUno, cadenaUno, enteroDos)) {
                        setNextTrue();
                    } else {
                        setNextFalse();
                    }
                    break;

                case "sino":
                case "entonces":
                    setNextTrue();
                    break;
            }

        } while (!currentTuple().getInstruction().equals("fin"));
    }

    public Tuple currentTuple() {
        return tuplas.get(tupleIndex);
    }

    public void setNextTrue() {
        tupleIndex = currentTuple().getNextPositionIfTrue() - 1;
    }

    public void setNextFalse() {
        tupleIndex = currentTuple().getNextPositionIfFalse() - 1;
    }

    public void tableSetInt(int index, int value) {
        tablaDeSimbolos.resolve(currentTuple().getParam(index)).setInt(value);
    }

    public int tableGetInt(int index) {
        return tablaDeSimbolos.resolve(currentTuple().getParam(index)).intValue;
    }

    public void tableSetFloat(int index, float value) {
        tablaDeSimbolos.resolve(currentTuple().getParam(index)).setFloat(value);
    }

    public float tableGetFloat(int index) {
        return tablaDeSimbolos.resolve(currentTuple().getParam(index)).floatValue;
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

    public String resolveType(int index) {
        String temp = tablaDeSimbolos.resolve(currentTuple().getParam(index)).type.getName();

        if (temp.equals("entero"))
            return "ENTERO";

        if (temp.equals("flotante"))
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

    public boolean condition(int variable1, String operadorCondicional, int variable2) {
        switch (operadorCondicional.toLowerCase()) {
            case "<":
            case "menorque":
                return variable1 < variable2;

            case ">":
            case "mayorque":
                return variable1 > variable2;

            case "==":
            case "igualque":
                return variable1 == variable2;

            case "!=":
            case "noigualque":
                return variable1 != variable2;

            case "<=":
            case "menorigualque":
                return variable1 <= variable2;

            case ">=":
            case "mayorigualque":
                return variable1 >= variable2;

            default:
                return false;
        }
    }

    public boolean isVariable(int index) {
        return !currentTuple().getParam(index).contains("\"");
    }

}
