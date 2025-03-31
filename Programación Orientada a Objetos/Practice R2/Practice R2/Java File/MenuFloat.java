import java.util.*;

public class MenuFloat{ 
  
  private static final boolean random = true;
  private static final boolean typed = false;

  public static void showMenu(){
    List<MatrizFloat> listMatFloat = new ArrayList<MatrizFloat>();
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
          listMatFloat.add( new MatrizFloat(GetInput.getInt("Numero de renglones"), GetInput.getInt("Numero de columnas")));//Genera la matriz
          listMatFloat.get(listMatFloat.size()-1).fillMatFloat(random);                                                        //Llena la matriz con valores aleatorios         
          GetInput.getLine("\nMatriz generada, presione Enter para volver al menu de seleccion");
        break;
        case "2":
          listMatFloat.add( new MatrizFloat(GetInput.getInt("Numero de renglones"), GetInput.getInt("Numero de columnas")));//Genera la matriz
          listMatFloat.get(listMatFloat.size()-1).fillMatFloat(typed);                                                        //Llena la matriz con valores introducidos por el usuario
          GetInput.getLine("\nMatriz generada, presione Enter para volver al menu de seleccion");
        break;
        case "3": 
          if(listMatFloat.size() > 0){
            Menu.matOperations();
            opc[2] = GetInput.getLine("\nSeleccione la operacion a realizar");
            switch (opc[2]) {
              case "1":
                i = GetInput.getInt("Selecciona una matriz (0 a " + (listMatFloat.size() - 1) + ")");
                if (i >= listMatFloat.size() | i < 0) {
                  System.out.println("\nPor favor, selecciona una matriz existente");
                  GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                } else {
                  listMatFloat.add(MatOperations.transposeMat(listMatFloat.get(i))); //Agrega la matriz transpuesta al array de Matrices
                  listMatFloat.get(i).printMatFloat("\tMatriz " + i);
                  listMatFloat.get(listMatFloat.size() - 1).printMatFloat(
                      "\n\tMatriz " + i + " transpuesta, ahora guardada en matriz " + (listMatFloat.size() - 1));
                  GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                }
                break;
              case "2":
                if (listMatFloat.size() == 0) {
                  System.out.println("\n\tNo se encontraron datos");
                  GetInput.getLine("\nPresione ENTER para volver al menu de seleccion");
                } else {
                  i = GetInput.getInt("Selecciona una matriz (0-" + (listMatFloat.size() - 1) + ")");
                  if (i >= listMatFloat.size() | i < 0) {
                    System.out.println("\nPor favor, selecciona una matriz existente");
                  } else if ((MatOperations.detMat(listMatFloat.get(i)) == 0)
                      | (listMatFloat.get(i).getColumns() != listMatFloat.get(i).getRows())) {
                    System.out.println("\nMatriz no compatible para el tipo de operacion");
                    GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                  } else {
                    listMatFloat.add(MatOperations.inverseMat(listMatFloat.get(i)));
                    listMatFloat.get(i).printMatFloat("\tMatriz " + i);
                    listMatFloat.get(listMatFloat.size() - 1).printMatFloat(
                        "\n\tMatriz " + i + " inversa, ahora guardada en matriz " + (listMatFloat.size() - 1));
                    GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                  }
                }
                break;
              case "3":
                if (listMatFloat.size() >= 2) {
                  j = GetInput.getInt("Selecciona la matriz #1 (0-" + (listMatFloat.size() - 1) + ")");
                  i = GetInput.getInt("Selecciona la matriz #2 (0-" + (listMatFloat.size() - 1) + ")");
                  if (i >= 0 & i < listMatFloat.size() & j >= 0 & j < listMatFloat.size()) {
                    if (Validations.validarCuadratura(listMatFloat.get(i), listMatFloat.get(j))) {
                      listMatFloat.add(MatOperations.addMat(listMatFloat.get(i), listMatFloat.get(j)));
                      listMatFloat.get(i).printMatFloat("\n\tMatriz " + i);
                      listMatFloat.get(i).printMatFloat("\n\tMatriz " + j);
                      listMatFloat.get(listMatFloat.size() - 1).printMatFloat("\n\tMatriz " + i + " + Matriz " + j
                          + " ahora guardada en matriz " + (listMatFloat.size() - 1));
                      GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                    } else {
                      System.out.println("\nMatrices no compatibles para el tipo de operacion");
                      GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                    }
                  } else {
                    System.out.println("\nPor favor, selecciona una matriz existente");
                    GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                  }
                } else {
                  System.out.println("\nSe necesitan al menos dos matrices para realizar esta operacion");
                  GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                }
                break;
              case "4":
                if (listMatFloat.size() >= 2) {
                  i = GetInput.getInt("Selecciona la matriz #1 (0-" + (listMatFloat.size() - 1) + ")");
                  j = GetInput.getInt("Selecciona la matriz #2 (0-" + (listMatFloat.size() - 1) + ")");
                  if (i >= 0 & i < listMatFloat.size() & j >= 0 & j < listMatFloat.size()) {
                    if (Validations.validarCuadratura(listMatFloat.get(i), listMatFloat.get(j))) {
                      listMatFloat.add(MatOperations.substractMat(listMatFloat.get(i), listMatFloat.get(j)));
                      listMatFloat.get(i).printMatFloat("\n\tMatriz " + i);
                      listMatFloat.get(i).printMatFloat("\n\tMatriz " + j);
                      listMatFloat.get(listMatFloat.size() - 1).printMatFloat("\n\tMatriz " + i + " - Matriz " + j
                          + " ahora guardada en matriz " + (listMatFloat.size() - 1));
                      GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                    } else {
                      System.out.println("\nMatrices no compatibles para el tipo de operacion");
                      GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                    }
                  }
                } else {
                  System.out.println("\nSe necesitan al menos dos matrices para realizar esta operacion");
                  GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                }
                break;
              case "5":
                if (listMatFloat.size() >= 2) {
                  i = GetInput.getInt("Selecciona la matriz #1 (0-" + (listMatFloat.size() - 1) + ")");
                  j = GetInput.getInt("Selecciona la matriz #2 (0-" + (listMatFloat.size() - 1) + ")");
                  if (i >= 0 & i < listMatFloat.size() & j >= 0 & j < listMatFloat.size()) {
                    if (Validations.validarMultiplicabilidad(listMatFloat.get(i), listMatFloat.get(j))) {
                      listMatFloat.add(MatOperations.multiplyMat(listMatFloat.get(i), listMatFloat.get(j)));
                      listMatFloat.get(i).printMatFloat("\n\tMatriz " + i);
                      listMatFloat.get(j).printMatFloat("\n\tMatriz " + j);
                      listMatFloat.get(listMatFloat.size() - 1).printMatFloat("\n\tMatriz " + i + " * Matriz " + j
                          + " ahora guardada en matriz " + (listMatFloat.size() - 1));
                      GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                    } else {
                      System.out.println("\nMatrices no compatibles para el tipo de operacion");
                      GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                    }
                  }
                } else {
                  System.out.println("\nSe necesitan al menos dos matrices para realizar esta operacion");
                  GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
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
          if (listMatFloat.size() > 0) {
            for(i=0; i<listMatFloat.size(); i++){
              System.out.print("\n\tMatriz " + i);
              listMatFloat.get(i).printMatFloat("");
            }
          }
        break;
        case "5":
          i = GetInput.getInt("Selecciona una matriz (0 a " + (listMatFloat.size()-1) + ")");
          if(i >= listMatFloat.size() | i <0){
            System.out.println("\nPor favor, selecciona una matriz existente");
          }
          else{
            listMatFloat.get(i).printMatFloat("\tMatriz " + i);
          }     
        break;
        case "0":
          menu[0] = false;
        break;
      }     
    }
  }
}
    
