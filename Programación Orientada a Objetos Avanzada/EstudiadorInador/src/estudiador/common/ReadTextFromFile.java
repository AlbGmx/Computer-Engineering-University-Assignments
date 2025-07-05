/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package estudiador.common;

import java.nio.file.*;

/**
 *
 * @author alber
 */
public class ReadTextFromFile {  
    public static String readFileAsString(String fileName)throws Exception{ 
    String data = ""; 
    data = new String(Files.readAllBytes(Paths.get(fileName))); 
    return data; 
  }    
}
