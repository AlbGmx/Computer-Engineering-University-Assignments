public class Test {
   public static void main(String[] args) {
      Listlexer lexer = new Listlexer("[a,b,c,d]");
      Token t = lexer.nextToken();
      while (t.type != Listlexer.EOF_TYPE) {
         System.out.println(t);
         t = lexer.nextToken();
      }
      System.out.println(t);
   }
}
