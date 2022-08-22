
public class Menu{
    
    public static void mainMenu(){
        System.out.print("\n----------Seleccione el tipo de Matriz a Manipular----------\n\t");
        System.out.print("1) Matriz de Enteros\t");
        System.out.print("2) Matriz de Flotantes\n\t");
        System.out.print("3) Matriz de Doubles\t");
        System.out.print("0) Salir del Programa\n");
    }
    
    public static void printingMenu(){
        
        System.out.print("\n-------------Seleccione la operacion a realizar-------------\n\t");
        System.out.print("1) Generar matriz con valores aleatorios\n\t");       
        System.out.print("2) Generar matriz e introducir valores\n\t");
        System.out.print("3) Realizar Operaciones con Matrices\n\t");
        System.out.print("4) Imprimir Todas las Matrices Guardadas\n\t");
        System.out.print("5) Imprimir solo una Matriz\n\t");
        System.out.print("0) Regresar\n\n");
       
    }

    public static void matOperations(){
        
        System.out.print("\n-------------Seleccione la operacion a realizar-------------\n\t");
        System.out.print("-----------------Operaciones unarias-----------------\n\t");       
        System.out.print("1) Transpuesta\t\t\t");
        System.out.print("2) Inversa\n\n\t");
        System.out.print("-----------------Operaciones binarias-----------------\n\t");
        System.out.print("3) Suma\t\t\t\t");
        System.out.print("4) Resta\n\t");
        System.out.print("5) Multiplicacion\t\t");
        System.out.print("0) Regresar\n\n");
       
    }

}