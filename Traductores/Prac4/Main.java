public class Main { 

    public static void main(String args[]) {
      //ListLexer lexer = new ListLexer(args[0]);
        ListLexer lexer = new ListLexer("[a]");
        ListParser parser = new ListParser(lexer);
        parser.list();
        System.out.println("Correct input, no errors found.");
    }
}