import java.util.ArrayList;

public class PseudoParser {
    ArrayList<PseudoLexer.Token> tokens;
    ArrayList<Tuple> tuples = new ArrayList<>();
    int tokenIndex = 0;
    int currentTuple = 1;
    SymbolTable symbolTable;

    public boolean parse(ArrayList<PseudoLexer.Token> tokens) {
        this.tokens = tokens;
        symbolTable = new SymbolTable();
        symbolTable.initTypeSystem();
        return programa();
    }

    private boolean token(String name) {
        if (tokens.get(tokenIndex).type.name().equals(name)) {
            tokenIndex++;
            return true;
        }
        return false;
    }

    private String tokenName(int index) {
        return tokens.get(index).data.toString();
    }

    public ArrayList<Tuple> getTuple() {
        return tuples;
    }

    public SymbolTable getSymbolTable() {
        return symbolTable;
    }

    private boolean programa() {
        if (token("INICIOPROGRAMA")
                && declaraciones()
                && enunciados()
                && token("FINPROGRAMA")) {
            String params[] = new String[] { null };
            Tuple t = new Tuple(currentTuple, "fin", params, -1, -1);
            tuples.add(t);

            if (tokenIndex == tokens.size())
                return true;
        }
        return false;
    }

    private boolean declaraciones() {
        int tokenIndexAux = tokenIndex;

        if (!tokens.get(tokenIndex).type.name().equals("ENTERO")
                && !tokens.get(tokenIndex).type.name().equals("FLOTANTE")) {
            return true;
        }

        if (declaracion() && declaraciones())
            return true;

        tokenIndex = tokenIndexAux;

        if (declaracion())
            return true;

        return false;
    }

    private boolean declaracion() {
        int beginIndex = tokenIndex;
        int tokenIndexAux;

        String type = tokenName(tokenIndex);
        BuiltInTypeSymbol bit = (BuiltInTypeSymbol) symbolTable.resolve(type);

        if (bit == null)
            return false;

        tokenIndex++;
        String vsName = tokenName(tokenIndex);

        if (token("VARIABLE")) {
            VariableSymbol vs = new VariableSymbol(vsName, bit);
            symbolTable.define(vs);

            tokenIndexAux = tokenIndex;

            if (token("IGUAL") && token("NUMERO")) {
                String params[] = new String[tokenIndex - beginIndex - 1];
                params[0] = tokens.get(beginIndex + 1).data;
                int i = beginIndex + 2;

                while (i < tokenIndex) {
                    params[i - beginIndex - 1] = tokens.get(i).data;
                    i++;
                }

                Tuple t = new Tuple(currentTuple, "declaracion", params, currentTuple + 1, currentTuple + 1);
                tuples.add(t);
                currentTuple++;

                return true;
            }

            tokenIndex = tokenIndexAux;
            // Si este es asignado por otra variable
            if (token("IGUAL")) {
                String vs2Name = tokenName(tokenIndex);
                if (token("VARIABLE")) {
                    VariableSymbol vs2 = (VariableSymbol) symbolTable.resolve(vs2Name);

                    if (vs2 == null)
                        return false;

                    String params[] = new String[tokenIndex - beginIndex - 1];
                    params[0] = tokens.get(beginIndex + 1).data;
                    int i = beginIndex + 2;

                    while (i < tokenIndex) {
                        params[i - beginIndex - 1] = tokens.get(i).data;
                        i++;
                    }

                    Tuple t = new Tuple(currentTuple, "declaracion", params, currentTuple + 1, currentTuple + 1);
                    tuples.add(t);
                    currentTuple++;
                }
            }
            return true;
        }
        return false;
    }

    private boolean enunciados() {
        int tokenIndexAux = tokenIndex;

        if (tokens.get(tokenIndex).type.name().equals("FINPROGRAMA")
                || tokens.get(tokenIndex).type.name().equals("FINSI")
                || tokens.get(tokenIndex).type.name().equals("FINSINO")
                || tokens.get(tokenIndex).type.name().equals("FINENTONCES")
                || tokens.get(tokenIndex).type.name().equals("FINMIENTRAS")
                || tokens.get(tokenIndex).type.name().equals("FINREPITE")) {
            return true;
        }

        if (enunciado() && enunciados())
            return true;

        tokenIndex = tokenIndexAux;

        return enunciado();
    }

    private boolean enunciado() {
        return (enunciadoAsignacion()
                || enunciadoLeer()
                || enunciadoEscribir()
                || enunciadoSi()
                || enunciadoMientras()
                || enunciadoRepite());
    }

    private boolean enunciadoAsignacion() {
        int beginIndex = tokenIndex;

        String vsName = tokenName(tokenIndex);

        if (token("VARIABLE")) {
            VariableSymbol vs = (VariableSymbol) symbolTable.resolve(vsName);
            if (vs == null) {
                System.out.println("Variable no declarada");
                return false;
            }
            if (token("IGUAL"))
                if (expresion()) {
                    String params[] = new String[tokenIndex - beginIndex - 1];
                    params[0] = tokens.get(beginIndex).data;
                    int i = beginIndex + 2;

                    while (i < tokenIndex) {
                        params[i - beginIndex - 1] = tokens.get(i).data;
                        i++;
                    }

                    Tuple t = new Tuple(currentTuple, "asignacion", params, currentTuple + 1, currentTuple + 1);
                    tuples.add(t);
                    currentTuple++;

                    return true;
                }
        }
        return false;
    }

    private boolean expresion() {
        return (operacion() || valor());
    }

    private boolean valor() {

        String vsName = tokenName(tokenIndex);

        if (token("VARIABLE")) {
            VariableSymbol vs = (VariableSymbol) symbolTable.resolve(vsName);
            if (vs == null) {
                System.out.println("Variable no declarada");
                return false;
            }
            return true;
        }
        return token("NUMERO");
    }

    private boolean operacion() {
        int tokenIndexAux = tokenIndex;

        if (valor() && token("OPARITMETICO") && valor())
            return true;

        tokenIndex = tokenIndexAux;
        return false;
    }

    private boolean enunciadoLeer() {
        int beginIndex = tokenIndex;

        String vsName;

        if (token("LEER") && token("CADENA") && token("COMA")) {
            vsName = tokenName(tokenIndex);
            if (token("VARIABLE")) {
                VariableSymbol vs = (VariableSymbol) symbolTable.resolve(vsName);
                if (vs == null) {
                    System.out.println("Variable no declarada");
                    return false;
                }

                String params[] = new String[tokenIndex - beginIndex - 2];

                params[0] = tokens.get(beginIndex + 1).data;
                params[1] = tokens.get(beginIndex + 3).data;

                Tuple t = new Tuple(currentTuple, "leer", params, currentTuple + 1, currentTuple + 1);
                tuples.add(t);
                currentTuple++;

                return true;
            }
        }
        return false;
    }

    private boolean enunciadoEscribir() {
        int tokenIndexAux = tokenIndex;
        int beginIndex = tokenIndexAux;

        String vsName;

        if (token("ESCRIBIR") && token("CADENA") && token("COMA")) {
            vsName = tokenName(tokenIndex);

            if (token("VARIABLE")) {
                VariableSymbol vs = (VariableSymbol) symbolTable.resolve(vsName);
                if (vs == null) {
                    System.out.println("Variable no declarada");
                    return false;
                }

                String params[] = new String[tokenIndex - beginIndex - 2];

                params[0] = tokens.get(beginIndex + 1).data;
                params[1] = tokens.get(beginIndex + 3).data;

                Tuple t = new Tuple(currentTuple, "escribir", params, currentTuple + 1, currentTuple + 1);
                tuples.add(t);
                currentTuple++;

                return true;
            }
        }

        tokenIndex = tokenIndexAux;

        if (token("ESCRIBIR") && token("CADENA")) {
            String params[] = new String[tokenIndex - beginIndex - 1];

            params[0] = tokens.get(beginIndex + 1).data;

            Tuple t = new Tuple(currentTuple, "escribir", params, currentTuple + 1, currentTuple + 1);
            tuples.add(t);
            currentTuple++;

            return true;
        }

        tokenIndex = tokenIndexAux;

        if (token("ESCRIBIR") && token("VARIABLE")) {
            String params[] = new String[tokenIndex - beginIndex - 1];

            params[0] = tokens.get(beginIndex + 1).data;

            Tuple t = new Tuple(currentTuple, "escribir", params, currentTuple + 1, currentTuple + 1);
            tuples.add(t);
            currentTuple++;

            return true;
        }

        return false;
    }

    private boolean enunciadoSi() {
        int beginIndex = tokenIndex;

        if (token("SI") && comparacion()) {
            String params[] = new String[3];
            Tuple temporaryTuple = null;
            int positionOfSinoTuple = 0, positionOfEntoncesTuple = 0;
            boolean isSino = false;

            int i = beginIndex + 2;
            while (i < beginIndex + 5) {
                params[i - beginIndex - 2] = tokens.get(i).data;
                i++;
            }

            temporaryTuple = new Tuple(currentTuple, "si", params, currentTuple + 1, 0);
            tuples.add(temporaryTuple);
            currentTuple++;

            positionOfEntoncesTuple = currentTuple;

            if (!enunciadoEntonces()) {
                return false;
            }

            positionOfSinoTuple = currentTuple;
            if (enunciadoSino())
                isSino = true;

            if (token("FINSI")) {
                // Set falseLine y trueLine del tuple si
                if (isSino) {
                    temporaryTuple.setNextPositionIfFalse(positionOfSinoTuple);
                    temporaryTuple.setNextPositionIfTrue(positionOfEntoncesTuple);
                    temporaryTuple = tuples.get(positionOfSinoTuple - 2);
                    temporaryTuple.setNextPositionIfTrue(currentTuple);
                }
                // Set falseLine y trueLine del tuple entonces
                temporaryTuple.setNextPositionIfFalse(currentTuple);
                return true;
            }
        }
        return false;
    }

    private boolean enunciadoSino() {
        if (token("SINO")) {
            String nullParams[] = new String[] { null };
            Tuple temp = new Tuple(currentTuple, "sino", nullParams, currentTuple + 1, currentTuple + 1);
            tuples.add(temp);
            currentTuple++;
            if (!enunciados())
                return false;
        }
        return token("FINSINO");
    }

    private boolean enunciadoEntonces() {
        if (token("ENTONCES")) {
            String nullParams[] = new String[] { null };
            Tuple temp = new Tuple(currentTuple, "entonces", nullParams, currentTuple + 1, currentTuple + 1);
            tuples.add(temp);
            currentTuple++;
            if (!enunciados())
                return false;
        }
        return token("FINENTONCES");

    }

    private boolean comparacion() {
        return (token("PARENTESISIZQ") && valor() && token("OPRELACIONAL") && valor() && token("PARENTESISDER"));
    }

    private boolean enunciadoMientras() {
        int beginIndex = tokenIndex;
        int tuplePos;
        if (token("MIENTRAS") && comparacion()) {
            String params[] = new String[3];

            int i = beginIndex + 2;
            while (i < beginIndex + 5) {
                params[i - beginIndex - 2] = tokens.get(i).data;
                i++;
            }

            Tuple t = new Tuple(currentTuple, "mientras", params, currentTuple + 1, 0);
            tuples.add(t);
            tuplePos = currentTuple;
            currentTuple++;

            if (enunciados() && token("FINMIENTRAS")) {
                t.setNextPositionIfFalse(currentTuple);
                tuples.set(tuplePos - 1, t);
                tuples.get(tuples.size() - 1).setNextPositionIfTrue(tuplePos);
                tuples.get(tuples.size() - 1).setNextPositionIfFalse(tuplePos);

                return true;
            }
        }
        return false;
    }

    private boolean enunciadoRepite() {
        String vsName;
        int beginIndex = tokenIndex;
        int tuplePos;

        if (token("REPITE") && token("PARENTESISIZQ")) {
            vsName = tokenName(tokenIndex);

            if (token("VARIABLE")) {
                VariableSymbol vs = (VariableSymbol) symbolTable.resolve(vsName);
                if (vs == null) {
                    System.out.println("Variable no declarada");
                    return false;
                }

                if (token("IGUAL") && valor() && token("COMA") && token("NUMERO") && token("PARENTESISDER")) {
                    String params[] = new String[4];
                    int i = beginIndex + 2;
                    params[0] = tokens.get(i).data;
                    params[1] = tokens.get(i + 2).data;
                    params[2] = tokens.get(i + 4).data;
                    params[3] = "notStarted";

                    Tuple t = new Tuple(currentTuple, "repite", params, currentTuple + 1, 0);
                    tuples.add(t);
                    tuplePos = currentTuple;
                    currentTuple++;

                    if (enunciados() && token("FINREPITE")) {
                        t.setNextPositionIfFalse(currentTuple);
                        tuples.set(tuplePos - 1, t);
                        tuples.get(tuples.size() - 1).setNextPositionIfTrue(tuplePos);
                        tuples.get(tuples.size() - 1).setNextPositionIfFalse(tuplePos);
                        return true;
                    }
                }
            }
        }
        return false;
    }

}
