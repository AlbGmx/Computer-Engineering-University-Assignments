public class ListLexer extends Lexer {
   public static int PLUS = 2;
   public static int MINUS = 3;
   public static int DOT = 4;
   public static int COMMA = 5;
   public static int LBRACK = 6;
   public static int RBRACK = 7;
   public static int LTHAN = 8;
   public static int GTHAN = 9;
   public static String[] tokenNames = { "n/a", "<EOF>", "PLUS", "MINUS", "DOT", "COMMA", "LBRACK", "RBRACK", "LTHAN",
         "GTHAN" };

   public String getTokenName(int x) {
      return tokenNames[x];
   }

   public ListLexer(String input) {
      super(input);
   }

   public Token nextToken() {
      while (c != EOF) {
         switch (c) {
            case ' ':
            case '\t':
            case '\n':
            case '\r':
               WS();
               continue;
            case '+':
               consume();
               return new Token(PLUS, "+");
            case '-':
               consume();
               return new Token(MINUS, "-");
            case '.':
               consume();
               return new Token(DOT, ".");
            case ',':
               consume();
               return new Token(COMMA, ",");
            case '[':
               consume();
               return new Token(LBRACK, "[");
            case ']':
               consume();
               return new Token(RBRACK, "]");
            case '<':
               consume();
               return new Token(LTHAN, "<");
            case '>':
               consume();
               return new Token(GTHAN, ">");
            default:
               throw new Error("invalid character: " + c);
         }
      }
      return new Token(EOF_TYPE, "<EOF>");
   }

   void WS() {
      while (c == ' ' || c == '\t' || c == '\n' || c == '\r')
         consume();
   }

}
