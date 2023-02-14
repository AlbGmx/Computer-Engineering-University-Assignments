import java.util.*;

public class GetInput {

  public static int getInt(String msg) {
    Scanner sc = new Scanner(System.in);
    System.out.print(msg + ": ");
    return (sc.nextInt());
  }

  public static float getFloat(String msg) {
    Scanner sc = new Scanner(System.in);
    System.out.print(msg + ": ");
    return (sc.nextFloat());
  }

  public static double getDouble(String msg) {
    Scanner sc = new Scanner(System.in);
    System.out.print(msg + ": ");
    return (sc.nextDouble());
  }

  public static String getLine(String msg) {
    Scanner sc = new Scanner(System.in);
    System.out.print(msg + ": ");
    return (sc.nextLine());
  }

  public static Boolean getBoolean(String msg) {
    Scanner sc = new Scanner(System.in);
    System.out.print(msg+ ": ");
    if(sc.nextLine().equals("y"))
      return true;
    else
      return false;
  }
}