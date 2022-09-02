public class Main { 

    public static void main(String args[]) {

        String test = "[a, ]";

        //ListLexer lexer = new ListLexer(args[0]);
        ListLexer lexer = new ListLexer(test);
        ListParser parser = new ListParser(lexer);
        parser.list();
        System.out.println("Correct input, no errors found.");
    }
}