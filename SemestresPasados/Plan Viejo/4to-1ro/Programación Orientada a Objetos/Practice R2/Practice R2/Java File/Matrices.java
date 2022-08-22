  
public class Matrices{
 public static void main(String []args){
    String opc = "";
    boolean menu = true;
    while(menu){
      Menu.mainMenu();
      opc = GetInput.getLine("\nSeleccione el tipo de matriz");
      switch(opc){
        case "1": //Operaciones con matrices de tipo flotante
          MenuInt.showMenu();     
        break;
        case "2": //Operaciones con matrices de tipo flotante
          MenuFloat.showMenu();
        break;
        case "3": //Operaciones con matrices de tipo doble
          MenuDouble.showMenu();
        break;
        case "0": menu = false; //Salir del programa
        break;
      }
    }   
  }
}