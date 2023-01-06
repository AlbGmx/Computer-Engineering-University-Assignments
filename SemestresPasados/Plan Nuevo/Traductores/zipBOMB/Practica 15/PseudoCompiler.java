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

        ArrayList<PseudoLexer.Token> tokens = pLexer.getTokens(input);

        pParser = new PseudoParser();
       
        pParser.parse(tokens);
        
        tuple = pParser.getTuple();

        table = pParser.getSymbolTable();

        Interpreter interpreter = new Interpreter(tuple, table);
        interpreter.start();


    }

    public static void main(String[] args) {
        if(args.length < 0) {
            System.out.println("Por favor pasar el archivo por argumento");
        } else {
            //new PseudoCompiler(args[0]);
            new PseudoCompiler("fibonacci.txt");
        }
        //new PseudoCompiler();
    }


}
