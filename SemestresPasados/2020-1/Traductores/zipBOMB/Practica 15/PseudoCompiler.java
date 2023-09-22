import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class PseudoCompiler {
    PseudoLexer pLexer;
    PseudoParser pParser;

    ArrayList<Tuple> tuple;
    SymbolTable table;

    public PseudoCompiler(String path) {
        pLexer = new PseudoLexer();

        String input = "";

        try {
            // FileReader reader = new FileReader("fibonacci.txt");
            FileReader reader = new FileReader(path);

            int character;

            while ((character = reader.read()) != -1) {
                input += (char) character;
            }
            reader.close();
        
        } catch (IOException e) {
            e.printStackTrace();
        }

        // System.out.println("********    PROGRAMA FUENTE    ********\n");
        // System.out.println(input);

        ArrayList<PseudoLexer.Token> tokens = pLexer.getTokens(input);

        // System.out.println("\n\n********    TOKENS    ********\n");

        // for (PseudoLexer.Token token : tokens)
        //     System.out.println(token);

        pParser = new PseudoParser();
        //System.out.println("\nSintaxis Correcta: " + pParser.parse(tokens));
       
        pParser.parse(tokens);
        //System.out.println("********    Tuplas    ********\n");
        
        tuple = pParser.getTuple();
        // for(Tuple t : tuple) {
        //     System.err.println(t);
        // } 

        table = pParser.getSymbolTable();

        Interpreter interpreter = new Interpreter(tuple, table);
        interpreter.start();


    }

    public static void main(String[] args) {
        if(args.length < 0) {
            System.out.println("Por favor pasar el archivo por argumento");
        } else {
            //new PseudoCompiler(args[0]);
            new PseudoCompiler("promedioCalificaciones.txt");
        }
        //new PseudoCompiler();
    }


}
