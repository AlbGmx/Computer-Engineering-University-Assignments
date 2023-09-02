import java.io.*;

public class FileManipulation {
  
  public static void writeFile(String fileName, String str) {
    FileWriter fichero = null;
    PrintWriter pw = null;
    fileName = GetInput.getLine("Nombre de archivo");
    try {
      fichero = new FileWriter(fileName);
      pw = new PrintWriter(fichero);
      pw.print(str);
    } 
    catch (Exception e) {
      e.printStackTrace();
    }
     
    finally {
      try {
        if (null != fichero)
          fichero.close();
      } 
      catch (Exception e2) {
        e2.printStackTrace();
      }
    }
  }

  public static void readFile() {
    File archivo = null;
    FileReader fr = null;
    BufferedReader br = null;
    try {
      // Apertura del fichero y creacion de BufferedReader para poder
      // hacer una lectura comoda (disponer del metodo readLine())
      String fileName = GetInput.getLine("Nombre de archivo");
      archivo = new File(fileName);
      fr = new FileReader(archivo);
      br = new BufferedReader(fr);
      // Lectura del fichero
      String linea;
      while ((linea = br.readLine()) != null)
        System.out.println(linea);
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      try {
        if (null != fr) {
          fr.close();
        }
      } catch (Exception e2) {
        e2.printStackTrace();
      }
    }
  }

  public static void save2File(String file, Alumno alum) {
    writeFile(file, ((alum.getName() + "," + String.valueOf(alum.getAvg()) + "," + alum.getID() + "," + alum.getMail() + "," + alum.getAccount() + ",\n")));
  }

}
