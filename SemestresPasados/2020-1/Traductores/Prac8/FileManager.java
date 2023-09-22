import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class FileManager {
   
   public static File createFile(String filename) {
      File file = new File(filename);
      try {
         file.createNewFile();
         return file;
      } catch (IOException e) {
         e.printStackTrace();
      }
      return null;
   }

   public static void closeFile(File file) {
      closeFile(file);
   }
}
