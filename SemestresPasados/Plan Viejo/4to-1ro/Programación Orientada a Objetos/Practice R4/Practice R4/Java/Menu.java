public class Menu {
  public static void main(int show) {
    System.out.println("\n\ta) Get Full Name");
    if(show > 0){
      System.out.println("\tb) Count the number of characters of each part of your name");
     System.out.println("\tc) Append the three parts in a big string");
    }
    if(show > 1){
      System.out.println("\td) Count the total number of characters of the big string");
      System.out.println("\te) Count the number of times that each (different) characters  appears in the big string");
      System.out.println("\tf) Print how many times each substring \"al\" or \"acr\" or \"sum\" appear in the big string");
      System.out.println("\tg) Count the number of times the blank space \" \" ocurres in the big string");
    }
    System.out.println("\t0) Exit the program");
  }
}