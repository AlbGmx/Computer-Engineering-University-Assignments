import java.util.*;

public class GetInput{

    public static  String getLine(String msg){
        Print.printStr("Ingrese " + msg + ": ");
        Scanner sc = new Scanner(System.in);
        return (sc.nextLine());
    }

    public static int getInt(String msg){
        Print.printStr("Ingrese " + msg + ": ");
        Scanner sc = new Scanner(System.in);
        return (sc.nextInt());

    }
}