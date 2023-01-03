public class Main { 

    public static void main(String args[]) {

        ListLexer lexer = new ListLexer("[a,b,c]");
        Token t = lexer.nextToken();

        while(t.type != Lexer.EOF_TYPE) {
            System.out.println(t);
            t = lexer.nextToken();
        }

        System.out.println(t);
    }
}