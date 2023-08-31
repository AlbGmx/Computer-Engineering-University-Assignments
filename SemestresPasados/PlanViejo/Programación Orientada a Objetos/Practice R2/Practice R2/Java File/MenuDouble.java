import java.util.*;

public class MenuDouble{ 
  
  private static final boolean random = true;
  private static final boolean typed = false;

  public static void showMenu(){
    List<MatrizDouble> listMatDouble = new ArrayList<MatrizDouble>();
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
          listMatDouble.add( new MatrizDouble(GetInput.getInt("Numero de renglones"), GetInput.getInt("Numero de columnas")));//Genera la matriz
          listMatDouble.get(listMatDouble.size()-1).fillMatDouble(random);                                                        //Llena la matriz con valores aleatorios         
          GetInput.getLine("\nMatriz generada, presione Enter para volver al menu de seleccion");
        break;
        case "2":
          listMatDouble.add( new MatrizDouble(GetInput.getInt("Numero de renglones"), GetInput.getInt("Numero de columnas")));//Genera la matriz
          listMatDouble.get(listMatDouble.size()-1).fillMatDouble(typed);                                                        //Llena la matriz con valores introducidos por el usuario
          GetInput.getLine("\nMatriz generada, presione Enter para volver al menu de seleccion");
        break;
        case "3": 
          if(listMatDouble.size() > 0){
            Menu.matOperations();
            opc[2] = GetInput.getLine("\nSeleccione la operacion a realizar");
            switch(opc[2]){
              case "1":
                i = GetInput.getInt("Selecciona una matriz (0 a " + (listMatDouble.size()-1) + ")");
                if(i >= listMatDouble.size() | i <0){
                  System.out.println("\nPor favor, selecciona una matriz existente");
                  GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                }
                else{
                  listMatDouble.add( MatOperations.transposeMat(listMatDouble.get(i))); //Agrega la matriz transpuesta al array de Matrices
                  listMatDouble.get(i).printMatDouble("\tMatriz " + i);
                  listMatDouble.get(listMatDouble.size()-1).printMatDouble("\n\tMatriz " + i + " transpuesta, ahora guardada en matriz " + (listMatDouble.size()-1));
                  GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                } 
              break;
              case "2":
                if (listMatDouble.size() == 0) {
                  System.out.println("\n\tNo se encontraron datos");
                  GetInput.getLine("\nPresione ENTER para volver al menu de seleccion");
                } else {
                  i = GetInput.getInt("Selecciona una matriz (0-" + (listMatDouble.size() - 1) + ")");
                  if (i >= listMatDouble.size() | i < 0) {
                    System.out.println("\nPor favor, selecciona una matriz existente");
                  } else if ((MatOperations.detMat(listMatDouble.get(i)) == 0)
                      | (listMatDouble.get(i).getColumns() != listMatDouble.get(i).getRows())) {
                    System.out.println("\nMatriz no compatible para el tipo de operacion");
                    GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                  } else {
                    listMatDouble.add(MatOperations.inverseMat(listMatDouble.get(i)));
                    listMatDouble.get(i).printMatDouble("\tMatriz " + i);
                    listMatDouble.get(listMatDouble.size() - 1).printMatDouble(
                        "\n\tMatriz " + i + " inversa, ahora guardada en matriz " + (listMatDouble.size() - 1));
                    GetInput.getLine("\nPresione cualquier tecla para volver al menu de seleccion");
                  }
                }
              break;
              case "3":
                if(listMatDouble.size() >= 2){
                  j = GetInput.getInt("Selecciona la matriz #1 (0-" + (listMatDouble.size()-1) + ")");
                  i = GetInput.getInt("Selecciona la matriz #2 (0-" + (listMatDouble.size()-1) + ")");
                  if( i >= 0 & i < listMatDouble.size() & j >= 0 & j < listMatDouble.size()){
                    if(Validations.validarCuadratura(listMatDouble.get(i), listMatDouble.get(j))){  
                      listMatDouble.add( MatOperations.addMat(listMatDouble.get(i), listMatDouble.get(j)));
                      listMatDouble.get(i).printMatDouble("\n\tMatriz " + i);
                      listMatDouble.get(i).printMatDouble("\n\tMatriz " + j);
                      listMatDouble.get(listMatDouble.size()-1).printMatDouble("\n\tMatriz " + i + " + Matriz " + j + " ahora guardada en matriz " + (listMatDouble.size()-1));
                      GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                    }
                    else{
                      System.out.println("\nMatrices no compatibles para el tipo de operacion");
                      GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                    }
                  }
                  else{
                    System.out.println("\nPor favor, selecciona una matriz existente");
                    GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                  }
                }
                else{
                  System.out.println("\nSe necesitan al menos dos matrices para realizar esta operacion");
                  GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                }
              break;
              case "4":
                if(listMatDouble.size() >= 2){
                  i = GetInput.getInt("Selecciona la matriz #1 (0-" + (listMatDouble.size()-1) + ")");
                  j = GetInput.getInt("Selecciona la matriz #2 (0-" + (listMatDouble.size()-1) + ")");
                  if( i >= 0 & i < listMatDouble.size() & j >= 0 & j < listMatDouble.size()){
                    if(Validations.validarCuadratura(listMatDouble.get(i), listMatDouble.get(j))){  
                      listMatDouble.add( MatOperations.substractMat(listMatDouble.get(i), listMatDouble.get(j)));
                      listMatDouble.get(i).printMatDouble("\n\tMatriz " + i);
                      listMatDouble.get(i).printMatDouble("\n\tMatriz " + j);
                      listMatDouble.get(listMatDouble.size()-1).printMatDouble("\n\tMatriz " + i + " - Matriz " + j + " ahora guardada en matriz " + (listMatDouble.size()-1));
                      GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                    }
                    else{
                      System.out.println("\nMatrices no compatibles para el tipo de operacion");
                      GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                    }
                  }
                }
                else{
                  System.out.println("\nSe necesitan al menos dos matrices para realizar esta operacion");
                  GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                }
              break;
              case "5":
                if(listMatDouble.size() >= 2){
                  i = GetInput.getInt("Selecciona la matriz #1 (0-" + (listMatDouble.size()-1) + ")");
                  j = GetInput.getInt("Selecciona la matriz #2 (0-" + (listMatDouble.size()-1) + ")");
                  if( i >= 0 & i < listMatDouble.size() & j >= 0 & j < listMatDouble.size()){
                    if(Validations.validarMultiplicabilidad(listMatDouble.get(i), listMatDouble.get(j))){  
                      listMatDouble.add( MatOperations.multiplyMat(listMatDouble.get(i), listMatDouble.get(j)));
                      listMatDouble.get(i).printMatDouble("\n\tMatriz " + i);
                      listMatDouble.get(j).printMatDouble("\n\tMatriz " + j);
                      listMatDouble.get(listMatDouble.size()-1).printMatDouble("\n\tMatriz " + i + " * Matriz " + j + " ahora guardada en matriz " + (listMatDouble.size()-1));
                      GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                    }
                    else{
                      System.out.println("\nMatrices no compatibles para el tipo de operacion");
                      GetInput.getLine("\nPresione Enter para volver al menu de seleccion");
                    }
                  }
                }
                else{
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
          if(listMatDouble.size() > 0 ){
            for(i=0; i<listMatDouble.size(); i++){
              System.out.print("\n\tMatriz " + i);
              listMatDouble.get(i).printMatDouble("");
            }
          }
        break;
        case "5":
          i = GetInput.getInt("Selecciona una matriz (0 a " + (listMatDouble.size()-1) + ")");
          if(i >= listMatDouble.size() | i <0){
            System.out.println("\nPor favor, selecciona una matriz existente");
          }
          else{
            listMatDouble.get(i).printMatDouble("\tMatriz " + i);
          }     
        break;
        case "0":
          menu[0] = false;
        break;
      }     
    }
  }
}
    
