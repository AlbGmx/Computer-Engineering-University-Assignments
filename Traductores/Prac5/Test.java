public class Test { 

    public static void main(String args[]) {

        String test = "[a, b=c,, [d, e]]";

        //ListLexer lexer = new ListLexer(args[0]);
        LookaheadLexer lexer = new LookaheadLexer(test);
        ListParser parser = new ListParser(lexer, 2);
        parser.list();
        System.out.println("OK, no problems found");

    }
}