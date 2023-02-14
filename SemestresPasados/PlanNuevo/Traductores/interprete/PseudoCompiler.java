import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

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
        Scanner sc = new Scanner(System.in); // Creamos un nuevo objeto Scanner
        System.out.println("Por favor, ingresa el nombre del archivo:"); // Mostramos un mensaje al usuario
        String nombreArchivo = sc.nextLine(); // Leemos el nombre del archivo ingresado por el usuario
        new PseudoCompiler(nombreArchivo);
        sc.close();
    }

}
