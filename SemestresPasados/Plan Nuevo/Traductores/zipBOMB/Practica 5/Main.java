<<<<<<< Updated upstream:SemestresPasados/Plan Nuevo/Traductores/zipBOMB/Practica 5/Main.java
public class Main { 

    public static void main(String args[]) {

        String test = "[a, ]";

        //ListLexer lexer = new ListLexer(args[0]);
        ListLexer lexer = new ListLexer(test);
        ListParser parser = new ListParser(lexer);
        parser.list();
        System.out.println("Correct Input, all good to continue!");
    }
=======
public class Main { 

    public static void main(String args[]) {
      //ListLexer lexer = new ListLexer(args[0]);
        ListLexer lexer = new ListLexer("[a]");
        ListParser parser = new ListParser(lexer);
        parser.list();
        System.out.println("Correct input, no errors found.");
    }
>>>>>>> Stashed changes:Traductores/Prac4/Main.java
}