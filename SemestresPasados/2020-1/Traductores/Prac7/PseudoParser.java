import java.util.ArrayList;

public class PseudoParser {
   ArrayList<PseudoLexer.Token> tokens;
   int tokenIndex = 0;
   SymbolTable table;

   public boolean parse(ArrayList<PseudoLexer.Token> tokens) {
      this.tokens = tokens;
      table = new SymbolTable();
      table.initTypeSystem();

      System.out.println("\n\n********** REGLAS DE PRODUCCION **********\n");
      return programa();
   }

   private boolean token(String name) {
      if (tokens.get(tokenIndex).type.name().equals(name)) {
         System.out.println(tokens.get(tokenIndex).type.name() + " " + tokens.get(tokenIndex).data);
         tokenIndex++;
         return true;
      }
      return false;
   }

   private String tokenName(int index) {
      return tokens.get(index).data.toString();
   }

   // <Programa> ::= inicio-programa <Enunciados> fin-programa
   private boolean programa() {
      System.out.println("<Programa> --> inicio-programa <Declaracion> <Enunciados> fin-programa");

      if (token("INICIOPROGRAMA"))
         if (declaraciones())
            if (enunciados())
               if (token("FINPROGRAMA"))
                  if (tokenIndex == tokens.size())
                     return true;

      return false;
   }

   // <Declaraciones> ::= <Declaraciones> <Declaracion> | Vacio
   private boolean declaraciones() {
      System.out.println("<Declaraciones> --> <Declaracion> <Declaraciones> | <Declaracion>");

      int tokenIndexAux = tokenIndex;

      if (declaracion())
         if (declaraciones())
            return true;

      tokenIndex = tokenIndexAux;

      if (declaracion())
         return true;

      return false;
   }

   // <Declaracion> ::= <Tipo>
   private boolean declaracion() {
      System.out.println("<Declaracion> --> <Tipo> <Variable>");

      if (variable()) {
         System.out.println("<Declaracon> --> <Tipo> <Variable>");
         return true;
      }

      return false;

   }

   // <Variables> ::= <Entero> <Varibles> | <Flotante> <Variables>
   private boolean variable() {

      String type = tokenName(tokenIndex);
      BuiltInTypeSymbol bit = (BuiltInTypeSymbol) table.resolve(type);

      if (bit == null) {
         System.out.println("Tipo de Variable no declarada");
         return false;
      }

      tokenIndex++;
      String vsName = tokenName(tokenIndex);

      if (token("VARIABLE")) {
         VariableSymbol vs = new VariableSymbol(vsName, bit);
         table.define(vs);
         return true;
      }

      return false;
   }

   // <Enunciados> ::= <Enunciado> <Enunciado> | Vacio
   private boolean enunciados() {
      System.out.println("<Enunciados> --> <Enunciado> <Enunciado> | <Enunciado>");

      int tokenIndexAux = tokenIndex;

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
      System.out.println("<Enunciado> --> <Asignacion> | <Leer> | <Escribir> | <Si> | <Mientras> | <Repite>");

      if (enunciadoAsignacion()) {
         System.out.println("<Enunciado> --> <Asignacion>");
         return true;
      }

      if (enunciadoLeer()) {
         System.out.println("<Enunciado> --> <Leer>");
         return true;
      }

      if (enunciadoEscribir()) {
         System.out.println("<Enunciado> --> <Escribir>");
         return true;
      }

      if (enunciadoSi()) {
         System.out.println("<Enunciado> --> <Si>");
         return true;
      }

      if (enunciadoMientras()) {
         System.out.println("<Enunciado> --> <Mientras>");
         return true;
      }

      if (enunciadoRepite()) {
         System.out.println("<Enunciado> --> <Repite>");
         return true;
      }

      return false;
   }

   // <Asignacion> ::= <Variable = <Expresion>
   private boolean enunciadoAsignacion() {
      System.out.println("<Asignacion> --> <Variable> = <Expresion>");
      String vsName = tokenName(tokenIndex);
      System.out.println(vsName);

      if (token("VARIABLE")) {
         VariableSymbol vs = (VariableSymbol) table.resolve(vsName);
         if (vs == null) {
            System.out.println("Variable no declarada");
            return false;
         }

         if (token("IGUAL"))
            if (expresion())
               return true;
      }

      return false;
   }

   // <Expresion> ::= <Valor> | <Operacion>
   private boolean expresion() {
      System.out.println("<Expresion> --> <Operacion> | <Valor>");

      if (operacion())
         return true;

      if (valor())
         return true;

      return false;
   }

   // <Valor> ::= <Varialbe> | <Numero>
   private boolean valor() {
      System.out.println("<Valor> --> <Variable> | <Numero>");
      String vsName = tokenName(tokenIndex);

      if (token("VARIABLE")) {
         VariableSymbol vs = (VariableSymbol) table.resolve(vsName);
         if (vs == null) {
            System.out.println("Variable no declarada");
            return false;
         }
         return true;
      }

      if (token("NUMERO"))
         return true;

      return false;
   }

   // <Operacion> ::= <Valor> <Operador-Aritmetico> <Valor>
   private boolean operacion() {
      System.out.println("<Operacion> --> <Valor> <Operador-Aritmetico> <Valor");

      int tokenIndexAux = tokenIndex;

      if (valor())
         if (token("OPARITMETICO"))
            if (valor())
               return true;

      tokenIndex = tokenIndexAux;
      return false;
   }

   // <Leer> ::= leer <Cadena> , <Variable>
   private boolean enunciadoLeer() {
      System.out.println("<Leer> --> leer <Cadena> , <Variable>");
      String vsName;

      if (token("LEER"))
         if (token("CADENA"))
            if (token("COMA")) {
               vsName = tokenName(tokenIndex);
               if (token("VARIABLE")) {
                  VariableSymbol vs = (VariableSymbol) table.resolve(vsName);
                  if (vs == null) {
                     System.out.println("Variable no declarada");
                     return false;
                  }
                  return true;
               }
            }
      return false;
   }

   // <Escribir> ::= escribir <Cadena> | escribir <Cadena> , <Variable>
   private boolean enunciadoEscribir() {
      System.out.println("<Escribir> --> escribir <Cadena> | escribir <Cadena> , <Varialbe>");
      String vsName;

      int tokenIndexAux = tokenIndex;

      if (token("ESCRIBIR"))
         if (token("CADENA"))
            if (token("COMA")) {
               vsName = tokenName(tokenIndex);
               if (token("VARIABLE")) {
                  VariableSymbol vs = (VariableSymbol) table.resolve(vsName);
                  if (vs == null) {
                     System.out.println("Variable no declarada");
                     return false;
                  }
                  return true;
               }
            }

      tokenIndex = tokenIndexAux;

      if (token("ESCRIBIR"))
         if (token("CADENA"))
            return true;

      return false;
   }

   // <Si> ::= si <Comparacion> entonces <Enunciados> fin-si
   private boolean enunciadoSi() {
      System.out.println("<Si> --> si <Comparacion> entonces <Enunciado> fin-si");

      if (token("SI"))
         if (comparacion())
            if (token("ENTONCES"))
               if (enunciados())
                  if (token("FINSI"))
                     return true;

      return false;
   }

   // <Comparacion> ::= ( <Valor> <Operador-relacional> <Valor> )
   private boolean comparacion() {
      System.out.println("<Comparacion> --> ( <Valor> <Operador-relacional> <Valor> )");

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
      System.out.println("<Mientras> --> mientras <Comparacion> <Enunciados> fin-mientras");

      if (token("MIENTRAS"))
         if (comparacion())
            if (enunciados())
               if (token("FINMIENTRAS"))
                  return true;

      return false;
   }

   // <Repite> ::= repite (<Variable> <IGUAL> <Valor> , <Valor>) <Enunciados>
   // fin-repite
   private boolean enunciadoRepite() {
      System.out.println("<Repite> --> repite (<Variable> <IGUAL> <Valor>) <Enunciados> fin-repite");
      String vsName;
      if (token("REPITE"))
         if (token("PARENTESISIZQ")) {
            vsName = tokenName(tokenIndex);
            if (token("VARIABLE")) {
               VariableSymbol vs = (VariableSymbol) table.resolve(vsName);
               if (vs == null) {
                  System.out.println("Variable no declarada");
                  return false;
               }
               if (token("IGUAL"))
                  if (valor())
                     if (token("COMA"))
                        if (token("NUMERO"))
                           if (token("PARENTESISDER"))
                              if (enunciados())
                                 if (token("FINREPITE"))
                                    return true;
            }
         }

      return false;
   }
}
