import java.util.*;
  
public class Matrices{
    public static void main(String []args){
        System.out.println("\nMatriz de enteros #1");
        MatrizInt m1 = new MatrizInt(CapturaEntrada.capturarEntero("Numero de renglones"), CapturaEntrada.capturarEntero("Numero de columnas"));        

        System.out.println("\nMatriz de enteros #2");
        MatrizInt m2 = new MatrizInt(CapturaEntrada.capturarEntero("Numero de renglones"), CapturaEntrada.capturarEntero("Numero de columnas"));
                
        System.out.println("\nMatriz de flotantes #1");
        MatrizFloat mf1 = new MatrizFloat(CapturaEntrada.capturarEntero("Numero de renglones"), CapturaEntrada.capturarEntero("Numero de columnas"));


        System.out.println("\nMatriz de flotantes #2");
        MatrizFloat mf2 = new MatrizFloat(CapturaEntrada.capturarEntero("Numero de renglones"), CapturaEntrada.capturarEntero("Numero de columnas"));

        
        m1.iniciarMatInt();
        System.out.println("Matriz Int 1");
        m1.imprimirMatInt();    

        m2.iniciarMatInt();
        System.out.println("Matriz Int 2");
        m2.imprimirMatInt();
    
        mf1.iniciarMatFloat();
        System.out.println("Matriz Int 1");
        mf1.imprimirMatFloat();

        mf2.iniciarMatFloat();
        System.out.println("Matriz Int 2");
        mf2.imprimirMatFloat();
    }
}