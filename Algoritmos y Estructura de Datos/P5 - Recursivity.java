import java.util.ArrayList;
import java.util.Scanner;

/*
    Algoritmos y Estructura de Datos
    Práctica 5. Recursividad
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
    Fecha de Entrega: 25 de octubre a las 13:00

    Sea a un arreglo  de n enteros introducidos por el usuario
    se pide que presente un menu donde el usuario pueda seleccionar
    cualquiera de las siguientes operaciones implementadas en funciones
    recursivas.
    1) El elemento menor del arreglo
    2) El promedio de los elementos del arreglo
    3) Interambiar los elementos del arreglo con su vecino.

 
*/
public class practica5_GomezEmmanuel{
    public static void main(String args[]){
        Scanner readIn = new Scanner(System.in);
        ArrayList<Integer> array = new ArrayList<Integer>();
        int size;
        char flag ='y';
        System.out.print("¿Cuantos datos desea capturar? ");
        size = readIn.nextInt();
        getArray(array, size, readIn);
        System.out.println();

        while(flag != 'n' & flag != 'n'){
            if(menu(array, readIn)==1) flag = 'n';
            else{
                System.out.println("Desea realizar otra operacion? (y/n)");
                flag = readIn.next().charAt(0);
            }
        }
        readIn.close();

    }

    public static int menu(ArrayList<Integer> array, Scanner readIn){
        int smaller, opc = 0;
        System.out.println("\n¿Que operacion desea ejecutar?");
        System.out.println("(1) Elemento menor del arreglo");
        System.out.println("(2) Promedio de los elementos");
        System.out.println("(3) Intercambiar elementos con su vecino");
        System.out.println("(0) Salir");
        System.out.println("Seleccione una opcion: ");
        opc = readIn.nextInt();
        
        if(opc==1) {
            smaller = smallerValueIndex(array, 0, 0);
            System.out.println("\nValor mas pequeño: [" + smaller + "] = " + array.get(smaller));
        }else if(opc==2){
            System.out.println("\nEl promedio es: " +  averageOfArray(array, array.size(), 0));
        }else if(opc==3){
            System.out.println("\nElementos originales: ");
            printArray(array);
            changeWithNeighbor(array, 0);
            System.out.println("\nElementos intercambiados: ");
            printArray(array);
        }else if(opc==0) return 1;
        return 0;
    }

    public static void getArray(ArrayList<Integer> array, int size, Scanner readIn) {
        for(int i=0; i<size; i++){
            System.out.print("Introduzca el valor [" + i + "]: ");
            array.add(readIn.nextInt());
        }
    }

    public static void printArray(ArrayList<Integer> array) {
        for(int i=0; i<array.size(); i++)
            System.out.println("valor[" + i + "]: " + array.get(i));
    }

    public static int smallerValueIndex(ArrayList<Integer> array, int start, int smaller) {
        if(start+1>=array.size()) return smaller; //Caso Base
        if(array.get(smaller) <= array.get(start+1));
        else smaller = start+1;
        start++;
        return (smallerValueIndex(array, start, smaller));
    }

    public static float averageOfArray(ArrayList<Integer> array, int size, float sum) {
        if(size-1== -1) return (float) sum/array.size(); //Caso Base
        sum += array.get(size-1);
        size--;
        return (averageOfArray(array, size, sum));
    }

    public static int changeWithNeighbor(ArrayList<Integer> array, int start){
        if(start+2 > array.size()) return 0; //caso base
        int aux = array.get(start);
        array.set(start, array.get(start+1));
        array.set(start+1, aux);        
        start += 2;
        return changeWithNeighbor(array, start);
    }
}