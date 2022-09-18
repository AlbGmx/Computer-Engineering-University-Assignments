import java.util.ArrayList;

public class PseudoParser {
   ArrayList<PseudoLexer.Token> tokens;
   int tokenIndex = 0;

   public boolean parse(ArrayList<PseudoLexer.Token> tokens) {
      this.tokens = tokens;

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

   // <Programa> ::= inicio-programa <Enunciados> fin-programa
   private boolean programa() {
      System.out.println("<Programa> --> inicio-programa <Enunciados> fin-programa");

      if (token("INICIOPROGRAMA"))
         if (enunciados())
            if (token("FINPROGRAMA"))
               if (tokenIndex == tokens.size())
                  return true;

      return false;
   }

   // <Enunciados> ::= <Enunciado> <Enunciados> | Vacio
   private boolean enunciados() {
      System.out.println("<Enunciados> --> <Enunciado> <Enunciados> | <Enunciado>");

      if (token("FINPROGRAMA")) {
         tokenIndex--;
         return true;
      }

      if (token("FINSI")) {
         tokenIndex--;
         return true;
      }

      if (token("FINMIENTRAS")) {
         tokenIndex--;
         return true;
      }

      if (token("FINREPITE")) {
         tokenIndex--;
         return true;
      }

      if (enunciado())
         if (enunciados())
            return true;

      return false;
   }

   // <Enunciado ::= <Asignacion> | <Leer> | <Escribir> | <Si> | <Mientras> |
   // <Repite>
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

      if (token("VARENTERA") || token("VARFLOTANTE"))
         if (token("IGUAL"))
            if (expresion())
               return true;

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

   // <Valor> ::= <VarEntera> | <VarFlotante> | <Numero>
   private boolean valor() {
      System.out.println("<Valor> --> <VarEntera> | <VarFlotante> | <Numero>");

      if (token("VARENTERA") || token("VARFLOTANTE") || token("NUMERO"))
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

   // <Leer> ::= leer <Cadena> , <VarEntera> | <VarFlotante>
   private boolean enunciadoLeer() {
      System.out.println("<Leer> --> leer <Cadena> , <VarEntera> | <VarFlotante>");

      if (token("LEER"))
         if (token("CADENA"))
            if (token("COMA"))
               if (token("VARENTERA") || token("VARFLOTANTE"))
                  return true;

      return false;
   }

   // <Escribir> ::= escribir <Cadena> | escribir <Cadena> , <VarEntera> |
   // <VarFlotante>
   private boolean enunciadoEscribir() {
      System.out.println("<Escribir> --> escribir <Cadena> | escribir <Cadena> , <VarEntera> | <VarFlotante>");

      int tokenIndexAux = tokenIndex;

      if (token("ESCRIBIR"))
         if (token("CADENA"))
            if (token("COMA"))
               if (token("VARENTERA") || token("VARFLOTANTE"))
                  return true;

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

   // <Repite> ::= repite <Enunciado> <Valor> fin-repite
   private boolean enunciadoRepite() {
      System.out.println("<Repite> --> repite <Enunciado> <Valor> fin-repite");

      if (token("REPITE"))
         if (token("PARENTESISIZQ"))
            if (enunciadoAsignacion())
               if (token("COMA"))
                  if (valor())
                     if (token("PARENTESISDER"))
                        if (enunciados())
                           if (token("FINREPITE"))
                              return true;
      return false;
   }

}
