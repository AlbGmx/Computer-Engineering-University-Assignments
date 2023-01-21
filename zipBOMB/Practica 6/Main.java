public class Main { 

    public static void main(String args[]) {

        String test = "[a,b=c,[d,e]]";

        //ListLexer lexer = new ListLexer(args[0]);
        ListLexer lexer = new ListLexer(test);
        ListParser parser = new ListParser(lexer, 2);
        parser.list();
        System.out.println("Correct Input, all good to continue!");
    }
}