import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class PseudoCompiler {
    PseudoLexer pLexer;

    public PseudoCompiler() {
        pLexer = new PseudoLexer();

        String input = "";

        try {
            FileReader reader = new FileReader("test.txt");
            int character;

            while ((character = reader.read()) != -1) {
                input += (char) character;
            }
            reader.close();
        
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("********    PROGRAMA FUENTE    ********\n");
        System.out.println(input);

        ArrayList<PseudoLexer.Token> tokens = pLexer.getTokens(input);

        System.out.println("\n\n********    TOKENS    ********\n");

        for (PseudoLexer.Token token : tokens)
            System.out.println(token);
    }

    public static void main(String[] args) {
        new PseudoCompiler();
    }


}
