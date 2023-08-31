/*
    Algortimos y Estructura de Datos
    Práctica 3. Análisis de Algortimos Empirico (Metodos de Ordenamiento)
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
    Fecha de Entrega: 11 de octubre a las 13:00

    Diseñe e implemente el algoritmo de ordenamiento burbuja en lenguaje C.
    Utilizando inicialmente un arreglo de 10 cadenas.

*/
#include <stdio.h>
#include <time.h>

//Se ha definido una constante para facilitar el cambio de la cadena a una sola palabra y no cambiar el array entero :)
#define ALLSAMECASE "Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion","Avion"
#define ALLDIFFERENTCASE "Cebra","Wrap","Palabra","casa","Comer","Abeja","Perro","Conejo","Burro","Gato","Computadora","Avion","Mouse","teclado","pantalla","Tierra","mundo","planetas","consola","xbox","PS4","Nintendo","plato","Grecia","Mexico","USA","Dell","Intel","HP","frutas","fresa","Naranja","manzana","Platano","Garrafon","Agua","Soda","Coca","Chescos","Refresco","Primer","Ministro","presidente","Amarillo","Rojo","azul","gris","blanco","negro","africa","Risk","dominio","Total","Del","Mundo","Monopoly","palabra","persona","Vaso","Sangre","vena","Vicio","Cuchara","Amigos","Ingenieria","Universidad","Escuela","Materia","Apriobadas","y","reprobadas","Gatos","Perros","Sudadera","Camisa","Zapatos","Tenis","Sandalias","retroceder","abandonar","encontrar","perder","destruir","observar","esta","es","una","palabra","google","chrome","firefox","word","powerpoint","VScode","notepad++","Zoom","Discord","excel","publisher","fin"
#define BESTCASE "Avion","Computadora","conosola","Mouse","mundo","pantalla","planetas","teclado","Tierra","xbox" 
#define OTHERCASE "Mouse","teclado","pantalla","Tierra","mundo","planetas","consola","xbox","PS4","Nintendo"
#define WORSTCASE "xbox","Tierra","teclado","planetas","pantalla","mundo","Mouse","consola","Computadora","Avion" 
#define EVENMOREWORDS "Cebra","Wrap","Palabra","casa","Comer","Abeja","Perro","Conejo","Burro","Gato","Computadora","Avion","Mouse","teclado","pantalla","Tierra","mundo","planetas","consola","xbox", "PS4","Nintendo","plato","Grecia","Mexico","USA","Dell","Intel","HP","frutas","fresa","Naranja","manzana","Platano","Garrafon","Agua","Soda","Coca","Chescos","Refresco", "Primer","Ministro","presidente","Amarillo","Rojo","azul","gris","blanco","negro","africa", "Risk","dominio","Total","Del","Mundo","Monopoly","palabra","persona","Vaso","Sangre","vena","Vicio","Cuchara","Amigos","Ingenieria","Universidad","Escuela","Materia","Apriobadas","y", "reprobadas","Gatos","Perros","Sudadera","Camisa","Zapatos","Tenis","Sandalias","retroceder","abandonar","encontrar","perder","destruir","observar","esta","es","una","palabra","google","chrome", "firefox","word","powerpoint","VScode","notepad++","Zoom","Discord","excel","publisher","fin","Cebra","Wrap","Palabra","casa","Comer","Abeja","Perro","Conejo","Burro","Gato","Computadora","Avion","Mouse","teclado","pantalla","Tierra","mundo","planetas","consola","xbox", "PS4","Nintendo","plato","Grecia","Mexico","USA","Dell","Intel","HP","frutas","fresa","Naranja","manzana","Platano","Garrafon","Agua","Soda","Coca","Chescos","Refresco", "Primer","Ministro","presidente","Amarillo","Rojo","azul","gris","blanco","negro","africa", "Risk","dominio","Total","Del","Mundo","Monopoly","palabra","persona","Vaso","Sangre","vena","Vicio","Cuchara","Amigos","Ingenieria","Universidad","Escuela","Materia","Apriobadas","y", "reprobadas","Gatos","Perros","Sudadera","Camisa","Zapatos","Tenis","Sandalias","retroceder","abandonar","encontrar","perder","destruir","observar","esta","es","una","palabra","google","chrome", "firefox","word","powerpoint","VScode","notepad++","Zoom","Discord","excel","publisher","fin","Cebra","Wrap","Palabra","casa","Comer","Abeja","Perro","Conejo","Burro","Gato","Computadora","Avion","Mouse","teclado","pantalla","Tierra","mundo","planetas","consola","xbox", "PS4","Nintendo","plato","Grecia","Mexico","USA","Dell","Intel","HP","frutas","fresa","Naranja","manzana","Platano","Garrafon","Agua","Soda","Coca","Chescos","Refresco", "Primer","Ministro","presidente","Amarillo","Rojo","azul","gris","blanco","negro","africa", "Risk","dominio","Total","Del","Mundo","Monopoly","palabra","persona","Vaso","Sangre","vena","Vicio","Cuchara","Amigos","Ingenieria","Universidad","Escuela","Materia","Apriobadas","y", "reprobadas","Gatos","Perros","Sudadera","Camisa","Zapatos","Tenis","Sandalias","retroceder","abandonar","encontrar","perder","destruir","observar","esta","es","una","palabra","google","chrome", "firefox","word","powerpoint","VScode","notepad++","Zoom","Discord","excel","publisher","fin","Cebra","Wrap","Palabra","casa","Comer","Abeja","Perro","Conejo","Burro","Gato","Computadora","Avion","Mouse","teclado","pantalla","Tierra","mundo","planetas","consola","xbox", "PS4","Nintendo","plato","Grecia","Mexico","USA","Dell","Intel","HP","frutas","fresa","Naranja","manzana","Platano","Garrafon","Agua","Soda","Coca","Chescos","Refresco", "Primer","Ministro","presidente","Amarillo","Rojo","azul","gris","blanco","negro","africa", "Risk","dominio","Total","Del","Mundo","Monopoly","palabra","persona","Vaso","Sangre","vena","Vicio","Cuchara","Amigos","Ingenieria","Universidad","Escuela","Materia","Apriobadas","y", "reprobadas","Gatos","Perros","Sudadera","Camisa","Zapatos","Tenis","Sandalias","retroceder","abandonar","encontrar","perder","destruir","observar","esta","es","una","palabra","google","chrome", "firefox","word","powerpoint","VScode","notepad++","Zoom","Discord","excel","publisher","fin","Cebra","Wrap","Palabra","casa","Comer","Abeja","Perro","Conejo","Burro","Gato","Computadora","Avion","Mouse","teclado","pantalla","Tierra","mundo","planetas","consola","xbox", "PS4","Nintendo","plato","Grecia","Mexico","USA","Dell","Intel","HP","frutas","fresa","Naranja","manzana","Platano","Garrafon","Agua","Soda","Coca","Chescos","Refresco", "Primer","Ministro","presidente","Amarillo","Rojo","azul","gris","blanco","negro","africa", "Risk","dominio","Total","Del","Mundo","Monopoly","palabra","persona","Vaso","Sangre","vena","Vicio","Cuchara","Amigos","Ingenieria","Universidad","Escuela","Materia","Apriobadas","y", "reprobadas","Gatos","Perros","Sudadera","Camisa","Zapatos","Tenis","Sandalias","retroceder","abandonar","encontrar","perder","destruir","observar","esta","es","una","palabra","google","chrome", "firefox","word","powerpoint","VScode","notepad++","Zoom","Discord","excel","publisher","fin","Cebra","Wrap","Palabra","casa","Comer","Abeja","Perro","Conejo","Burro","Gato","Computadora","Avion","Mouse","teclado","pantalla","Tierra","mundo","planetas","consola","xbox", "PS4","Nintendo","plato","Grecia","Mexico","USA","Dell","Intel","HP","frutas","fresa","Naranja","manzana","Platano","Garrafon","Agua","Soda","Coca","Chescos","Refresco", "Primer","Ministro","presidente","Amarillo","Rojo","azul","gris","blanco","negro","africa", "Risk","dominio","Total","Del","Mundo","Monopoly","palabra","persona","Vaso","Sangre","vena","Vicio","Cuchara","Amigos","Ingenieria","Universidad","Escuela","Materia","Apriobadas","y", "reprobadas","Gatos","Perros","Sudadera","Camisa","Zapatos","Tenis","Sandalias","retroceder","abandonar","encontrar","perder","destruir","observar","esta","es","una","palabra","google","chrome", "firefox","word","powerpoint","VScode","notepad++","Zoom","Discord","excel","publisher","fin","Cebra","Wrap","Palabra","casa","Comer","Abeja","Perro","Conejo","Burro","Gato","Computadora","Avion","Mouse","teclado","pantalla","Tierra","mundo","planetas","consola","xbox", "PS4","Nintendo","plato","Grecia","Mexico","USA","Dell","Intel","HP","frutas","fresa","Naranja","manzana","Platano","Garrafon","Agua","Soda","Coca","Chescos","Refresco", "Primer","Ministro","presidente","Amarillo","Rojo","azul","gris","blanco","negro","africa", "Risk","dominio","Total","Del","Mundo","Monopoly","palabra","persona","Vaso","Sangre","vena","Vicio","Cuchara","Amigos","Ingenieria","Universidad","Escuela","Materia","Apriobadas","y", "reprobadas","Gatos","Perros","Sudadera","Camisa","Zapatos","Tenis","Sandalias","retroceder","abandonar","encontrar","perder","destruir","observar","esta","es","una","palabra","google","chrome", "firefox","word","powerpoint","VScode","notepad++","Zoom","Discord","excel","publisher","fin","Cebra","Wrap","Palabra","casa","Comer","Abeja","Perro","Conejo","Burro","Gato","Computadora","Avion","Mouse","teclado","pantalla","Tierra","mundo","planetas","consola","xbox", "PS4","Nintendo","plato","Grecia","Mexico","USA","Dell","Intel","HP","frutas","fresa","Naranja","manzana","Platano","Garrafon","Agua","Soda","Coca","Chescos","Refresco", "Primer","Ministro","presidente","Amarillo","Rojo","azul","gris","blanco","negro","africa", "Risk","dominio","Total","Del","Mundo","Monopoly","palabra","persona","Vaso","Sangre","vena","Vicio","Cuchara","Amigos","Ingenieria","Universidad","Escuela","Materia","Apriobadas","y", "reprobadas","Gatos","Perros","Sudadera","Camisa","Zapatos","Tenis","Sandalias","retroceder","abandonar","encontrar","perder","destruir","observar","esta","es","una","palabra","google","chrome", "firefox","word","powerpoint","VScode","notepad++","Zoom","Discord","excel","publisher","fin","Cebra","Wrap","Palabra","casa","Comer","Abeja","Perro","Conejo","Burro","Gato","Computadora","Avion","Mouse","teclado","pantalla","Tierra","mundo","planetas","consola","xbox", "PS4","Nintendo","plato","Grecia","Mexico","USA","Dell","Intel","HP","frutas","fresa","Naranja","manzana","Platano","Garrafon","Agua","Soda","Coca","Chescos","Refresco", "Primer","Ministro","presidente","Amarillo","Rojo","azul","gris","blanco","negro","africa", "Risk","dominio","Total","Del","Mundo","Monopoly","palabra","persona","Vaso","Sangre","vena","Vicio","Cuchara","Amigos","Ingenieria","Universidad","Escuela","Materia","Apriobadas","y", "reprobadas","Gatos","Perros","Sudadera","Camisa","Zapatos","Tenis","Sandalias","retroceder","abandonar","encontrar","perder","destruir","observar","esta","es","una","palabra","google","chrome", "firefox","word","powerpoint","VScode","notepad++","Zoom","Discord","excel","publisher","fin","Cebra","Wrap","Palabra","casa","Comer","Abeja","Perro","Conejo","Burro","Gato","Computadora","Avion","Mouse","teclado","pantalla","Tierra","mundo","planetas","consola","xbox", "PS4","Nintendo","plato","Grecia","Mexico","USA","Dell","Intel","HP","frutas","fresa","Naranja","manzana","Platano","Garrafon","Agua","Soda","Coca","Chescos","Refresco", "Primer","Ministro","presidente","Amarillo","Rojo","azul","gris","blanco","negro","africa", "Risk","dominio","Total","Del","Mundo","Monopoly","palabra","persona","Vaso","Sangre","vena","Vicio","Cuchara","Amigos","Ingenieria","Universidad","Escuela","Materia","Apriobadas","y", "reprobadas","Gatos","Perros","Sudadera","Camisa","Zapatos","Tenis","Sandalias","retroceder","abandonar","encontrar","perder","destruir","observar","esta","es","una","palabra","google","chrome", "firefox","word","powerpoint","VScode","notepad++","Zoom","Discord","excel","publisher","fin",
#define SIZE 100

void printArray(char*[SIZE], int);  //imprime el array sin saltos de linea
void printlnArray(char*[SIZE], int);//imprime el array con saltos de linea
int compareWords(char[], char[]);   //Compara cadenas ignorando mayusculas y tomando en cuenta el tamaño en caso de ser parecidas. Ej: Ojo y Ojos
int sortByWords(char*[SIZE]);      //Metodo de Ordenamiento Burbuja

void main(){
    double executionTime = 0;
    //Atencion: Si se va a cambiar el numero de palabras es necesario cambiar la constante SIZE para que concuerde :)
    char *array[SIZE]={
        "cyclotrimethylenetrinitramine","pseudophilanthropical","hexamethylenetetramine","chlorotrifluoromethane","dicyclopentadienyliron","disestablishmentarian","microspectrophotometric","hyperpolysyllabically","hdmezovï¾¡sï¾¡rhely","poliencephalomyelitis","electroencephalographically","magnetothermoelectricity","misapprehensiveranged","dichlorodifluoromethane","interdenominationalism","bioelectrogenetically","pseudoanthropological","anatomicopathological","overcommercialization","establishmentarianism","hexachlorocyclohexane","overindividualization","dichlorodiphenyltrichloroethane","superincomprehensible","antisupernaturalistic","nitrotrichloromethane","electroencephalography","trifluorochloromethane","nondistinguishableness","succinylsulphathiazole","noninterchangeableness","aerobacteriologically","representationalistic","pseudoanachronistical","demethylchlortetracycline","diaminopropyltetramethylenediamine","transubstantiationalist","isopropylideneacetone","antimaterialistically","intertransformability","chlorprophenpyridamine","noncharacteristically","trinitrophenylmethylnitramine","electrocardiographically","triacetyloleandomycin","parathyroidectomizing","electromyographically","anticonstitutionalist","counterrevolutionaries","temperameperamentally","antidisestablishmentarianism","spectrophotometrically","chlorotrifluoroethylene","electrodiagnostically","methyltrinitrobenzene","psychotherapeutically","disproportionableness","pseudoenthusiastically","overimpressionability","microspectrophotometry","hydrodesulphurization","indistinguishableness","hexahydroxycyclohexane","overimpressionableness","antinationalistically","psychophysiologically","ballistocardiographic","electroencephalographic","diphenylaminechlorarsine","noninterchangeability","pentamethylenediamine","overindividualistically","ultranationalistically","overintellectualizing","phenylethylmalonylurea","dichlorodifluoromethane","hyperenthusiastically","overindustrialization","deoxyribonucleoprotein","dendrochronologically","pseudointernationalistic","magnetohydrodynamically","misapprehensiveranging","supercalifragilisticexpialidocious","electroencephalograph","superincomprehensibleness","intellectualistically","pseudohermaphroditism","dichlorodiphenyltrichloroethane","trichloroacetaldehyde","trichloronitromethane","succinylsulfathiazole","thermophosphorescence","hyperconstitutionalism","humuhumunukunukuapuaa","disestablishmentarianism","overintellectualization","desoxyribonucleoprotein","electrophysiologically","anticonstitutionalism"
   };
    printf("\nArray a ordenar: ");
    printArray(array, SIZE);
    int iterations = 0;
    
    //Comienzo del algoritmo y toma del tiempo
    clock_t begin = clock();
    iterations = sortByWords(array);
    clock_t end = clock();
    executionTime = (double)(end - begin) / CLOCKS_PER_SEC;
    //Final del algoritmo y recuento del tiempo de ejecucion

    printf("\n\nArray ordenado:");
    printlnArray(array, SIZE);
    printf("\n\nTiempo de ejecuci%cn: %fs\nIteraciones: %d", 162, executionTime, iterations);
    printf("\nPresione cualquier tecla para salir: ");
    getchar();
}
void printArray(char *array[SIZE], int size){
    int i;
    for (i=0; i<size-1; i++) printf("%s, ", array[i]);
    printf("%s.",  array[i]);
}
void printlnArray(char *array[SIZE], int size){
    int i;
    for (i=0; i<size; i++) printf("\n%s", array[i]);
}
int sortByWords(char *array[SIZE]){ //Regresa el numero de iteraciones realizadas
    int i, j, iterations=0;
    char *aux=NULL;
    for(i=0; i<SIZE; i++){
        for(j=i+1; j<SIZE; j++){
            iterations++; 
            if(compareWords(array[i], array[j])){
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
    return iterations;
}
int compareWords(char wordA[SIZE], char wordB[SIZE]){
    int i=0;
    char auxA = '\0',  auxB = '\0';
    while(wordA[i] & wordB[i]){
        if (wordA[i]>='A' & wordA[i]<='Z') auxA = wordA[i] + ' '; //Si el caracter actual de A se encuentra entre A -> Z convierte a minusculas
        else auxA = wordA[i];
        if (wordB[i]>='A' & wordB[i]<='Z') auxB = wordB[i] + ' '; //Si el caracter actual de B se encuentra entre A -> Z convierte a minusculas
        else auxB = wordB[i];      
        if ( !(auxA == auxB)) return (auxA > auxB) ? 1 : 0;
        i++;
    }
    return (wordA[i]) ? 1 : 0; //Si la palabra wordA sigue teniendo caracteres y wordB no, entonces regresa 1
}