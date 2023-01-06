public class Parser {
    
    Lexer input;
    Token lookahead;
    
    public Parser(Lexer input) {
        this.input = input;
        lookahead = input.nextToken();
    }

    // If lookahead token type matches x, consume & return else error
    public void match(int x) {
        if ( lookahead.type == x) {
            consume();
        }
        else throw new Error("expecting " + input.getTokenName(x) + "; found " + lookahead);
    }
    
    public void consume() {
        lookahead = input.nextToken();
    }
}
