public class Parser {
    
    Lexer input;        //from where do we get tokens?
    Token[] lookahead;  //circular lookahed buffer
    int k;              //how many lookaheads symbols
    int p = 1;          //circular index of next token position to fill


    public Parser(Lexer input, int k) {
        this.input = input;
        this.k = k;
        lookahead = new Token[k];
        for (int i=1; i<=k; i++) {
            consume();
        }
    }

    // If lookahead token type matches x, consume & return else error
    public void match(int x) {
        if (LA(1) == x) {
            consume();
        }
        else throw new Error("expecting " + input.getTokenName(x) + "; found " + LT(1));
    }
    
    public void consume() {
        lookahead[p] = input.nextToken();
        p = (p+1) % k;
    }

    public Token LT(int i) {
        return lookahead[(p+i-1) % k];
    }

    public int LA(int i) {
        return LT(i).type;
    }

}
