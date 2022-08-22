package common;

import java.io.*;
import java.util.ArrayList;

import pelicula.Pelicula;

public class FileManipulation implements Serializable {
    public static void writeToFile(String filename, ArrayList<Pelicula> objeto){
        // Serialization
        try
        {
            //Saving of object in a file
            FileOutputStream archivo = new FileOutputStream(filename);
            ObjectOutputStream salida = new ObjectOutputStream(archivo);

            // Method for serialization of object
            salida.writeObject(objeto);

            salida.close();
            archivo.close();

            System.out.println("Object has been serialized");

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}
