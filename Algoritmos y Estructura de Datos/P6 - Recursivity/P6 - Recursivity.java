import java.util.Random;

/*
    Algoritmos y Estructura de Datos
    Práctica 6. Recursividad
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
    Fecha de Entrega: 1 de noviembre a las 13:00

    Desarrollar un programa basado en un algoritmo recursivo 
    cuya funcion sea devolver el numero de #'s alrededor de 
    una celda de una matriz 5x9.
 
*/
public class practica6_GomezEmmanuel_01261509{
    public static void main(String args[]){
        String matrix[5][9];
        int intMtx[5][9];
        initializeMtx(matrix);
        instertInMtx(matrix);
        checkSorrounds(matrix, intMtx, 0, 0);
    }

    public static void initializeMtx(String matrix[5][9]){
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 9; j++)
                matrix[i][j] = " ";
    }
    public static void instertInMtx(String matrix[5][9]){
        int remaining = 15;
        int i = 0;
        Random rnd = new Random();
        while(remaining>0){
            if(rnd.nextBoolean()) {
                matrix[0][i] = "#";
                i++;
                remaining--;
            }
            if(i>=45) i = 0;
        }
    }
    public static int checkSorrounds(String matrix[5][9], int intMtx[5][9], int ren, int col){
        if(col > 9 ) ren++;
        if(ren > 5 ) return 0; //Caso Base

        return 0;
    }
}