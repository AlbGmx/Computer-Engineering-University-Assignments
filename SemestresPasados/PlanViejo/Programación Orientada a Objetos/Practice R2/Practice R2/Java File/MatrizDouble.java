import java.text.DecimalFormat;
import java.util.*;
import javax.swing.JOptionPane;

public class MatrizDouble extends Matriz{
    double array[][];
    public MatrizDouble(int rows, int columns){
        super(rows, columns);
        array = new double[rows][columns];
    }
    public void fillMatDouble(boolean flag){
        Random gen = new Random();
        for(int i = 0; i < this.rows; i++)
            for(int j = 0; j < this.columns; j++)
                if(flag){
                    this.array[i][j] = 100*gen.nextDouble();
                }
                else{
                    this.array[i][j] = GetInput.getDouble("\nIntroduza el valor [" + i + "][" + j + "]");
                }    
    
    }
    //imprimir en consola
    public void printMatDouble(String str){
      System.out.println(str);
      for(int i = 0; i < this.rows; i++){
        for(int j = 0; j < this.columns; j++)
          System.out.format("%15.4f",this.array[i][j]);
      System.out.println();
      }
    }
    //imprimir en grafico
    public void printMatIntG(){
        DecimalFormat df = new DecimalFormat("#00");
        String cadena = "";
        for(int i = 0; i < this.rows; i++){
            for (int j = 0; j < this.columns; j++) {
                cadena += df.format(array[i][j]) + "\t\t";
            }
            cadena += "\n";
        }
        JOptionPane.showMessageDialog(null, cadena);
    }
}