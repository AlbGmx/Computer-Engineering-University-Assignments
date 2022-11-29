public class Test {
   public static void main(String[] args) {
      ListLexer lexer = new ListLexer("++++++++++[>+++++++>++++++++++>+++++++++++>+++>+<<<<<-]>++.>>+.---.<---.>>++.<+.++++++++.-------.<+++.>+.>+.>.Íç");
      Token t = lexer.nextToken();
      while (t.type != ListLexer.EOF_TYPE) {
         switch (t.type) {
            case 2:
               System.out.println("++*ptr;");
               break;
            case 3:
               System.out.println("--*ptr;");
               break;
            case 4:
               System.out.println("++ptr;");
               break;
            case 5:
               System.out.println("--ptr;");
               break;
            case 6:
               System.out.println("putchar(*ptr);");
               break;
            case 7:
               System.out.println("*ptr = getchar();");
               break;
            case 8:
               System.out.println("while (*ptr) {");
               break;
            case 9:
               System.out.println("}");
               break;
            default:
               System.out.println("Invalid token: " + t);
               break;

         }
         t = lexer.nextToken();
      }
      System.out.println("Correct input, no errors found.");
   }
}
