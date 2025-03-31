import java.text.DecimalFormat;
/*
    Algortimos y Estructura de Datos
    Práctica 3. Análisis de Algortimos Empirico (Metodos de Ordenamiento)
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
    Fecha de Entrega: 11 de octubre a las 13:00

    Diseñe e implemente el algoritmo de ordenamiento burbuja en lenguaje C.
    Utilizando inicialmente un arreglo de 10 cadenas.

*/
class practica3_GomezEmmanuel{
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("#.##########s");
        String[] words = {"Mouse","teclado","pantalla","Tierra","mundo","planetas","consola","xbox","PS4","Nintendo"};
        int iterations = 0;
        System.out.print("\nPalabras a ordenar: ");
        printWords(words);

        long begin = System.nanoTime();
        iterations = sortByWords(words);
        double executionTime = ((System.nanoTime() - begin) / 1000000000.0);
        System.out.println("\nPalabras ordenadas: ");
        printWords(words);
        String seconds = df.format(executionTime);
        System.out.println("\nTiempo de Ejecucion: " + seconds);
        System.out.print("Iteraciones: " +  iterations);
        
    }

    public static void printWords(String[] words){
        int i=0;
        for(i=0; i<words.length-1; i++){
            System.out.print(words[i] + ", ");
        }
        System.out.print(words[i] + ".\n");
    }    
    public static void printlnWords(String[] words){
        for(int i=0; i<words.length; i++){
            System.out.println(words[i]);
        }
    }

    public static int sortByWords(String[] words){
        String aux;
        int iterations = 0;
        for(int i=0; i<words.length; i++) {
            for(int j=i+1; j<words.length; j++) {
                iterations++;
                if(words[i].compareToIgnoreCase(words[j]) > 0){
                    aux = words[i];
                    words[i] = words[j];
                    words[j] = aux;
                }
            }
        }
        return iterations;
    }
}
