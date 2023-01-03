import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PseudoLexer {
    public enum TokenType {
        // No se puede usar el guion en el nombre
        NUMERO("-?[0-9]+(\\.([0-9]+))?"),
        CADENA("\".*\""),
        OPARITMETICO("[*|/|+|-|%]"),
        OPRELACIONAL("<=|>=|<|>|==|!=|mayorque\\b|menorque\\b|igualque\\b|distintoque\\b|mayorigualque\\b|menorigualque\\b"),
        IGUAL("="),
        INICIOPROGRAMA("inicio-programa\\b"),
        FINPROGRAMA("fin-programa\\b"),
        SI("si\\b"),
        FINSI("fin-si\\b"),
        ENTONCES("entonces\\b"),
        FINENTONCES("fin-entonces\\b"),
        SINO("sino\\b"),
        FINSINO("fin-sino\\b"),
        MIENTRAS("mientras\\b"),
        FINMIENTRAS("fin-mientras\\b"),
        REPITE("repite\\b"),
        FINREPITE("fin-repite\\b"),
        LEER("leer\\b"),
        ESCRIBIR("escribir\\b"),
        COMA(","),
        PARENTESISIZQ("\\("),
        PARENTESISDER("\\)"),
        ESPACIOS("\\s+"),
        ENTERO("entero\\b"),
        FLOTANTE("flotante\\b"),
        VARIABLE("[a-zA-Z][a-zA-Z0-9]*"),
        ERROR(".+");

        public final String pattern;

        private TokenType(String pattern) {
            this.pattern = pattern;
        }
    }

    public class Token {
        public TokenType type;
        public String data;

        public Token(TokenType type, String data) {
            this.type = type;
            this.data = data;
        }

        @Override
        public String toString() {
            return String.format("(%s   \"%s\")", type.name(), data);
        }
    }

    public ArrayList<Token> getTokens(String input) {
        ArrayList<Token> tokens = new ArrayList<Token>();

        StringBuffer tokenPatternsBuffer = new StringBuffer();

        for (TokenType tokenType : TokenType.values())
            tokenPatternsBuffer.append(String.format("|(?<%s>%s)", tokenType.name(), tokenType.pattern));

        // System.out.println(tokenPatternsBuffer);

        Pattern tokenPatterns = Pattern.compile(new String(tokenPatternsBuffer.substring(1)));

        Matcher matcher = tokenPatterns.matcher(input);

        while (matcher.find()) {
            for (TokenType t : TokenType.values()) {
                if (matcher.group(TokenType.ESPACIOS.name()) != null)
                    continue;
                else if (matcher.group(t.name()) != null) {
                    tokens.add(new Token(t, matcher.group(t.name())));
                    break;
                }
            }
        }

        return tokens;
    }
}
