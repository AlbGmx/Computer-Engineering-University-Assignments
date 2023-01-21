import java.util.ArrayList;

public class PseudoParser {
    ArrayList<PseudoLexer.Token> tokens;
    ArrayList<Tuple> tuples = new ArrayList<>();
    int tokenIndex = 0;
    int indexOfTuple = 1;

    boolean debug = true;

    public boolean parse(ArrayList<PseudoLexer.Token> tokens) {
        this.tokens = tokens;

        System.out.println("\n\n********** REGLAS DE PRODUCCION **********\n");
        return programa();
    }

    private boolean token(String name) {
        if (tokens.get(tokenIndex).type.name().equals(name)) {
            debugPrint(tokens.get(tokenIndex).type.name() + " " + tokens.get(tokenIndex).data);
            tokenIndex++;
            return true;
        }
        return false;
    }

    private void debugPrint(String text) {
        if(debug)
            System.out.println(text);
    }

    public ArrayList<Tuple> getTuple() {
        return tuples;
    }


    // <Programa> ::= inicio-programa <Enunciados> fin-programa
    private boolean programa() {
        debugPrint("<Programa> --> inicio-programa <Declaracion> <Enunciados> fin-programa");

        if (token("INICIOPROGRAMA"))
            if (declaraciones())
                if (enunciados())
                    if (token("FINPROGRAMA")) {
                        String params[] = new String[]{null};
                        
                        Tuple t = new Tuple(indexOfTuple, "fin", params, -1, -1);
                        tuples.add(t);
                
                        if (tokenIndex == tokens.size())
                            return true;
                    }
        return false;
    }

    // <Declaraciones> ::= <Declaraciones> <Declaracion> | Vacio
    private boolean declaraciones() {
        debugPrint("<Declaraciones> --> <Declaracion> <Declaraciones> | <Declaracion>");

        int tokenIndexAux = tokenIndex;

        if (declaracion())
            if (declaraciones())
                return true;

        tokenIndex = tokenIndexAux;

        if (declaracion())
            return true;

        return true;
    }

    // <Declaracion> ::= <Tipo>
    private boolean declaracion() {
        debugPrint("<Declaracion> --> <Tipo> <Variable>");


        if (variable()) {
            debugPrint("<Declaracon> --> <Tipo> <Variable>");
            return true;
        }

        return false;

    }

    // <Variables> ::= <Entero> <Varibles> | <Flotante> <Variables>
    private boolean variable() {

        if (token("ENTERO"))
            if (token("VARIABLE"))
                return true;

        if (token("FLOTANTE"))
            if (token("VARIABLE"))
                return true;
            
        return false;
    }

    // <Enunciados> ::= <Enunciado> <Enunciado> | Vacio
    private boolean enunciados() {
        debugPrint("<Enunciados> --> <Enunciado> <Enunciado> | <Enunciado>");

        int tokenIndexAux = tokenIndex;

        if(tokens.get(tokenIndex).type.name().equals("FINPROGRAMA") || tokens.get(tokenIndex).type.name().equals("FINSI") ||
            tokens.get(tokenIndex).type.name().equals("FINMIENTRAS") || tokens.get(tokenIndex).type.name().equals("FINREPITE")){
            return true;
        }

        if (enunciado())
            if (enunciados())
                return true;

        tokenIndex = tokenIndexAux;

        if (enunciado())
            return true;

        return false;
    }

    // <Enunciado ::= <Asignacion> | <Leer> | <Escrbiir> | <Si> | <Mientras>
    private boolean enunciado() {
        debugPrint("<Enunciado> --> <Asignacion> | <Leer> | <Escribir> | <Si> | <Mientras> | <Repite>");

        if (enunciadoAsignacion()) {
            debugPrint("<Enunciado> --> <Asignacion>");
            return true;
        }

        if (enunciadoLeer()) {
            debugPrint("<Enunciado> --> <Leer>");
            return true;
        }

        if (enunciadoEscribir()) {
            debugPrint("<Enunciado> --> <Escribir>");
            return true;
        }

        if (enunciadoSi()) {
            debugPrint("<Enunciado> --> <Si>");
            return true;
        }

        if (enunciadoMientras()) {
            debugPrint("<Enunciado> --> <Mientras>");
            return true;
        }

        if (enunciadoRepite()) {
            debugPrint("<Enunciado> --> <Repite>");
            return true;
        }

        return false;
    }

    // <Asignacion> ::= <Variable = <Expresion>
    private boolean enunciadoAsignacion() {
        debugPrint("<Asignacion> --> <Variable> = <Expresion>");

        int beginIndex = tokenIndex;

        if (token("VARIABLE"))
            if (token("IGUAL")) 
                if (expresion()){
                    String params[] = new String[tokenIndex-beginIndex-1];
                    params[0] = tokens.get(beginIndex).data;
                    int i = beginIndex+2;

                    while(i<tokenIndex) {
                        params[i-beginIndex-1] = tokens.get(i).data;
                        i++;
                    }

                    Tuple t = new Tuple(indexOfTuple, "asignacion", params, indexOfTuple+1, indexOfTuple+1);
                    tuples.add(t);
                    indexOfTuple++;
                    
                    return true;
            }           
        
        return false;
    }

    // <Expresion> ::= <Valor> | <Operacion>
    private boolean expresion() {
        debugPrint("<Expresion> --> <Operacion> | <Valor>");

        if (operacion())
            return true;

        if (valor())
            return true;

        return false;
    }

    // <Valor> ::= <Varialbe> | <Numero>
    private boolean valor() {
        debugPrint("<Valor> --> <Variable> | <Numero>");

        if (token("VARIABLE"))
            return true;

        if (token("NUMERO"))
            return true;

        return false;
    }

    // <Operacion> ::= <Valor> <Operador-Aritmetico> <Valor>
    private boolean operacion() {
        debugPrint("<Operacion> --> <Valor> <Operador-Aritmetico> <Valor");

        int tokenIndexAux = tokenIndex;

        if (valor())
            if (token("OPARITMETICO"))
                if(valor())
                    return true;

        tokenIndex = tokenIndexAux;
        return false;
    }

    // <Leer> ::= leer <Cadena> , <Variable>
    private boolean enunciadoLeer() {
        debugPrint("<Leer> --> leer <Cadena> , <Variable>");

        int beginIndex = tokenIndex;

        if (token("LEER"))
            if (token("CADENA"))
                if (token("COMA"))
                    if (token("VARIABLE")) {
                        String params[] = new String[tokenIndex-beginIndex-2];

                        params[0] = tokens.get(beginIndex+1).data;
                        params[1] = tokens.get(beginIndex+3).data;

                        Tuple t = new Tuple(indexOfTuple, "leer", params, indexOfTuple+1, indexOfTuple+1);
                        tuples.add(t);
                        indexOfTuple++;
                        
                        return true;
                    }

        return false;
    }

    // <Escribir> ::= escribir <Cadena> | escribir <Cadena> , <Variable>
    private boolean enunciadoEscribir() {
        debugPrint("<Escribir> --> escribir <Cadena> | escribir <Cadena> , <Varialbe>");

        int tokenIndexAux = tokenIndex;
        int beginIndex = tokenIndexAux;

        if (token("ESCRIBIR"))
            if (token("CADENA"))
                if (token("COMA"))
                    if (token("VARIABLE")) {
                        String params[] = new String[tokenIndex-beginIndex-2];

                        params[0] = tokens.get(beginIndex+1).data;
                        params[1] = tokens.get(beginIndex+3).data;

                        Tuple t = new Tuple(indexOfTuple, "escribir", params, indexOfTuple+1, indexOfTuple+1);
                        tuples.add(t);
                        indexOfTuple++;
                        
                        return true;
                    }

        tokenIndex = tokenIndexAux;

        if (token("ESCRIBIR"))
            if (token("CADENA")) {
                String params[] = new String[tokenIndex-beginIndex-1];

                params[0] = tokens.get(beginIndex+1).data;

                Tuple t = new Tuple(indexOfTuple, "escribir", params, indexOfTuple+1, indexOfTuple+1);
                tuples.add(t);
                indexOfTuple++;
                
                return true;
            }

        return false;
    }

    // <Si> ::= si <Comparacion> entonces <Enunciados> fin-si
    private boolean enunciadoSi() {
        debugPrint("<Si> --> si <Comparacion> entonces <Enunciado> fin-si");
        int beginIndex = tokenIndex;
        int tuplePos;

        if (token("SI"))
            if (comparacion()) {
                String params[] = new String[3];

                int i = beginIndex + 2;
                while(i < beginIndex + 5){
                    params[i - beginIndex - 2] = tokens.get(i).data;
                    i++;
                }

                Tuple t = new Tuple(indexOfTuple, "comparacion", params, indexOfTuple+1, 0);
                tuples.add(t);
                tuplePos = indexOfTuple;
                indexOfTuple++;
                
                if (token("ENTONCES"))
                    if (enunciados())
                        if (token("FINSI")) {
                            t.setFalseLine(indexOfTuple);
                            tuples.set(tuplePos-1, t);

                            return true;
                        }
            }
                

        return false;
    }

    // <Comparacion> ::= ( <Valor> <Operador-relacional> <Valor> )
    private boolean comparacion() {
        debugPrint("<Comparacion> --> ( <Valor> <Operador-relacional> <Valor> )");

        if (token("PARENTESISIZQ"))
            if (valor())
                if (token("OPRELACIONAL"))
                    if (valor())
                        if (token("PARENTESISDER"))
                            return true;

        return false;
    }

    // <Mientras> ::= mientras <Comparacion> <Enunciados> fin-mientras
    private boolean enunciadoMientras() {
        debugPrint("<Mientras> --> mientras <Comparacion> <Enunciados> fin-mientras");

        int beginIndex = tokenIndex;
        int tuplePos;
        if (token("MIENTRAS"))
            if (comparacion()) {
                String params[] = new String[3];

                int i = beginIndex + 2;
                while(i < beginIndex + 5){
                    params[i - beginIndex - 2] = tokens.get(i).data;
                    i++;
                }

                Tuple t = new Tuple(indexOfTuple, "comparacion", params, indexOfTuple+1, 0);
                tuples.add(t);
                tuplePos = indexOfTuple;
                indexOfTuple++;

                if (enunciados())
                    if (token("FINMIENTRAS")) {
                        t.setFalseLine(indexOfTuple);
                        tuples.set(tuplePos-1, t);
                        tuples.get(tuples.size()-1).setTrueLine(tuplePos);
                        tuples.get(tuples.size()-1).setFalseLine(tuplePos);

                        return true;
                    }   
            }

        return false;
    }

    // <Repite> ::= repite (<Variable> <IGUAL> <Valor> , <Valor>) <Enunciados> fin-repite
    private boolean enunciadoRepite() {
        debugPrint("<Repite> --> repite (<Variable> <IGUAL> <Valor>) <Enunciados> fin-repite");

        if (token("REPITE"))
            if(token("PARENTESISIZQ"))
                if (token("VARIABLE"))
                    if(token("IGUAL"))
                        if(valor())
                            if(token("COMA"))
                                if(token("NUMERO"))
                                    if(token("PARENTESISDER"))
                                        if (enunciados())
                                            if (token("FINREPITE"))
                                                return true;

        return false;
    }

    
}
