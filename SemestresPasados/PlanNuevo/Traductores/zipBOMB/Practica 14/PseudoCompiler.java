import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class PseudoCompiler {
    PseudoLexer pLexer;
    PseudoParser pParser;

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

        pParser = new PseudoParser();
        System.out.println("\nSintaxis Correcta: " + pParser.parse(tokens));

        System.out.println("********    Tuplas    ********\n");
        ArrayList<Tuple> tuple = pParser.getTuple();
        for(Tuple t : tuple) {
            System.err.println(t);
        }

    }

    public static void main(String[] args) {
        new PseudoCompiler();
    }


}
