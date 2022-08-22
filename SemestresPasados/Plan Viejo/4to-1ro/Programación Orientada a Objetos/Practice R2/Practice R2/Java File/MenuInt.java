import java.util.*;

public class MenuInt{ 
  
  private static final boolean random = true;
  private static final boolean typed = false;

  public static void showMenu(){
    List<MatrizInt> listMatInt = new ArrayList<MatrizInt>();
    Boolean[] menu = new Boolean[2];
    String[] opc = new String[3];
    menu[0] = true;
    int i;
    int j;
    while(menu[0]){
      Menu.printingMenu();
      opc[1] = GetInput.getLine("\nSeleccione la operacion a realizar");
      switch(opc[1]){
        case "1":
          listMatInt.add( new MatrizInt(GetInput.getInt("Numero de renglones"), GetInput.getInt("Numero de columnas")));//Genera la matriz
          listMatInt.get(listMatInt.size()-1).fillMatInt(random);                                                        //Llena la matriz con valores aleatorios         
          GetInput.getLine("\nMatriz generada, presione cualquier tecla para volver al menu de seleccion");
        break;
        case "2":
          listMatInt.add( new MatrizInt(GetInput.getInt("Numero de renglones"), GetInput.getInt("Numero de columnas")));//Genera la matriz
          listMatInt.get(listMatInt.size()-1).fillMatInt(typed);                                                        //Llena la matriz con valores introducidos por el usuario
          GetInput.getLine("\nMatriz generada, presione cualquier tecla para volver al menu de seleccion");
        break;
        case "3": 
          if (listMatInt.size() > 0) {
            Menu.matOperations();
            opc[2] = GetInput.getLine("\nSeleccione la operacion a realizar");
            switch (opc[2]) {
              case "1":
                if (listMatInt.size() == 0) {
                  System.out.println("\n\tNo se encontraron datos");
                  GetInput.getLine("\nPresione ENTER para volver al menu de seleccion");
                } else {
                  i = GetInput.getInt("Selecciona una matriz (0 a " + (listMatInt.size() - 1) + ")");
                  if (i >= listMatInt.size() | i < 0) {
                    System.out.println("\nPor favor, selecciona una matriz existente");
                    GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                  } else {
                    listMatInt.add(MatOperations.transposeMat(listMatInt.get(i))); // Agrega la matriz transpuesta al
                                                                                   // array de Matrices
                    listMatInt.get(i).printMatInt("\tMatriz " + i);
                    listMatInt.get(listMatInt.size() - 1).printMatInt(
                        "\n\tMatriz " + i + " transpuesta, ahora guardada en matriz " + (listMatInt.size() - 1));
                    GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                  }
                }
                break;
              case "2":
                if (listMatInt.size() == 0) {
                  System.out.println("\n\tNo se encontraron datos");
                  GetInput.getLine("\nPresione ENTER para volver al menu de seleccion");
                } else {
                  i = GetInput.getInt("Selecciona una matriz (0-" + (listMatInt.size() - 1) + ")");
                  if (i >= listMatInt.size() | i < 0 | !(Validations.validarInversa(listMatInt.get(i)))) {
                    System.out.println("\n Matriz no compatible para el tipo de operacion");
                  } else if ((MatOperations.detMat(listMatInt.get(i)) == 0)
                      | (listMatInt.get(i).getColumns() != listMatInt.get(i).getRows())) {
                    System.out.println("\nMatriz no compatible para el tipo de operacion");
                    GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                  } else {
                    if (Validations.validarInversa(listMatInt.get(i))) {
                      listMatInt.get(i).printMatInt("\tMatriz " + i);
                      MatOperations.inverseMat(listMatInt.get(i)).printMatFloat("\tMatriz inversa");
                      GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                    }
                  }
                }
                break;
              case "3":
                if (listMatInt.size() >= 2) {
                  j = GetInput.getInt("Selecciona la matriz #1 (0-" + (listMatInt.size() - 1) + ")");
                  i = GetInput.getInt("Selecciona la matriz #2 (0-" + (listMatInt.size() - 1) + ")");
                  if (i >= 0 & i < listMatInt.size() & j >= 0 & j < listMatInt.size()) {
                    if (Validations.validarCuadratura(listMatInt.get(i), listMatInt.get(j))) {
                      listMatInt.add(MatOperations.addMat(listMatInt.get(i), listMatInt.get(j)));
                      listMatInt.get(i).printMatInt("\n\tMatriz " + i);
                      listMatInt.get(i).printMatInt("\n\tMatriz " + j);
                      listMatInt.get(listMatInt.size() - 1).printMatInt("\n\tMatriz " + i + " + Matriz " + j
                          + " ahora guardada en matriz " + (listMatInt.size() - 1));
                      GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                    } else {
                      System.out.println("\nMatrices no compatibles para el tipo de operacion");
                      GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                    }
                  } else {
                    System.out.println("\nPor favor, selecciona una matriz existente");
                    GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                  }
                } else {
                  System.out.println("\nSe necesitan al menos dos matrices para realizar esta operacion");
                  GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                }
                break;
              case "4":
                if (listMatInt.size() >= 2) {
                  i = GetInput.getInt("Selecciona la matriz #1 (0-" + (listMatInt.size() - 1) + ")");
                  j = GetInput.getInt("Selecciona la matriz #2 (0-" + (listMatInt.size() - 1) + ")");
                  if (i >= 0 & i < listMatInt.size() & j >= 0 & j < listMatInt.size()) {
                    if (Validations.validarCuadratura(listMatInt.get(i), listMatInt.get(j))) {
                      listMatInt.add(MatOperations.substractMat(listMatInt.get(i), listMatInt.get(j)));
                      listMatInt.get(i).printMatInt("\n\tMatriz " + i);
                      listMatInt.get(i).printMatInt("\n\tMatriz " + j);
                      listMatInt.get(listMatInt.size() - 1).printMatInt("\n\tMatriz " + i + " - Matriz " + j
                          + " ahora guardada en matriz " + (listMatInt.size() - 1));
                      GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                    } else {
                      System.out.println("\nMatrices no compatibles para el tipo de operacion");
                      GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                    }
                  }
                } else {
                  System.out.println("\nSe necesitan al menos dos matrices para realizar esta operacion");
                  GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                }
                break;
              case "5":
                if (listMatInt.size() >= 2) {
                  i = GetInput.getInt("Selecciona la matriz #1 (0-" + (listMatInt.size() - 1) + ")");
                  j = GetInput.getInt("Selecciona la matriz #2 (0-" + (listMatInt.size() - 1) + ")");
                  if (i >= 0 & i < listMatInt.size() & j >= 0 & j < listMatInt.size()) {
                    if (Validations.validarMultiplicabilidad(listMatInt.get(i), listMatInt.get(j))) {
                      listMatInt.add(MatOperations.multiplyMat(listMatInt.get(i), listMatInt.get(j)));
                      listMatInt.get(i).printMatInt("\n\tMatriz " + i);
                      listMatInt.get(j).printMatInt("\n\tMatriz " + j);
                      listMatInt.get(listMatInt.size() - 1).printMatInt("\n\tMatriz " + i + " * Matriz " + j
                          + " ahora guardada en matriz " + (listMatInt.size() - 1));
                      GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                    } else {
                      System.out.println("\nMatrices no compatibles para el tipo de operacion");
                      GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                    }
                  }
                } else {
                  System.out.println("\nSe necesitan al menos dos matrices para realizar esta operacion");
                  GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                }
                break;
              case "0":
                menu[1] = false;
                break;
            }
          }
          else {
            System.out.println("\n\tNo se encontraron datos");
            GetInput.getLine("\nPresione ENTER para volver al menu de seleccion");
          }
        break;
        case "4":
          if(listMatInt.size() > 0 ){
            for(i=0; i<listMatInt.size(); i++){
              System.out.print("\n\tMatriz " + i);
              listMatInt.get(i).printMatInt("");
            }
          }
          else {
            System.out.println("\n\tNo se encontraron datos");
            GetInput.getLine("\nPresione ENTER para volver al menu de seleccion");
          }
        break;
        case "5":
          i = GetInput.getInt("Selecciona una matriz (0 a " + (listMatInt.size()-1) + ")");
          if(i >= listMatInt.size() | i <0){
            System.out.println("\nPor favor, selecciona una matriz existente");
            GetInput.getLine("\nPresione ENTER para volver al menu de seleccion");
          }
          else{
            listMatInt.get(i).printMatInt("\tMatriz " + i);
          }     
        break;
        case "0":
          menu[0] = false;
        break;
      }     
    }
  }
}
    
