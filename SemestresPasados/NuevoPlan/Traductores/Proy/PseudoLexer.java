import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PseudoLexer {
    public enum TokenType {
        // No se puede usar el guion en el nombre
        DOWHILE("["),
        WHILE("]"),
        INCREMENTO(">"),
        DECREMENTO("<"),
        INCREMENTO_VALOR("\\+"),
        DECREMENTO_VALOR("-"),
        IMPRIMIR("\\."),
        LEER(",");

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
            return String.format("(%s,   \"%s\")", type.name(), data);
        }
    }

    public ArrayList<Token> getTokens(String input) {
        ArrayList<Token> tokens = new ArrayList<Token>();

        Pattern tokenPatterns = Pattern.compile(
                "(" + TokenType.DOWHILE.pattern + ")"
                        + "|(" + TokenType.WHILE.pattern + ")"
                        + "|(" + TokenType.INCREMENTO.pattern + ")"
                        + "|(" + TokenType.DECREMENTO.pattern + ")"
                        + "|(" + TokenType.INCREMENTO_VALOR.pattern + ")"
                        + "|(" + TokenType.DECREMENTO_VALOR.pattern + ")"
                        + "|(" + TokenType.IMPRIMIR.pattern + ")"
                        + "|(" + TokenType.LEER.pattern + ")");
        Matcher matcher = tokenPatterns.matcher(input);

        while (matcher.find()) {
            if (matcher.group(TokenType.DOWHILE.name()) != null) {
                tokens.add(new Token(TokenType.DOWHILE, matcher.group(TokenType.DOWHILE.name())));
            } else if (matcher.group(TokenType.WHILE.name()) != null) {
                tokens.add(new Token(TokenType.WHILE, matcher.group(TokenType.WHILE.name())));
            } else if (matcher.group(TokenType.INCREMENTO.name()) != null) {
                tokens.add(new Token(TokenType.INCREMENTO, matcher.group(TokenType.INCREMENTO.name())));
            } else if (matcher.group(TokenType.DECREMENTO.name()) != null) {
                tokens.add(new Token(TokenType.DECREMENTO, matcher.group(TokenType.DECREMENTO.name())));
            } else if (matcher.group(TokenType.INCREMENTO_VALOR.name()) != null) {
                tokens.add(new Token(TokenType.INCREMENTO_VALOR, matcher.group(TokenType.INCREMENTO_VALOR.name())));
            } else if (matcher.group(TokenType.DECREMENTO_VALOR.name()) != null) {
                tokens.add(new Token(TokenType.DECREMENTO_VALOR, matcher.group(TokenType.DECREMENTO_VALOR.name())));
            } else if (matcher.group(TokenType.IMPRIMIR.name()) != null) {
                tokens.add(new Token(TokenType.IMPRIMIR, matcher.group(TokenType.IMPRIMIR.name())));
            } else if (matcher.group(TokenType.LEER.name()) != null) {
                tokens.add(new Token(TokenType.LEER, matcher.group(TokenType.LEER.name())));
            }
        }

        return tokens;
    }
}
