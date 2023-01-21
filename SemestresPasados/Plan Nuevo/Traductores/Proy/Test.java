public class Test {
   public static void main(String[] args) {
      ListLexer lexer = new ListLexer("++++++++++[>+++++++>++++++++++>+++++++++++>+++>+<<<<<-]>++.>>+.---.<---.>>++.<+.++++++++.-------.<+++.>+.>+.>.");
      ListParser parser = new ListParser(lexer);
      parser.elements();


   }
}
