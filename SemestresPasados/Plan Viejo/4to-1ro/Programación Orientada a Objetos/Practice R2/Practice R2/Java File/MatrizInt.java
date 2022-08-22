import java.text.DecimalFormat;
import java.util.*;
import javax.swing.JOptionPane;

public class MatrizInt extends Matriz{
    int array[][];
    public MatrizInt(int rows, int columns){
        super(rows, columns);
        array = new int[rows][columns];
    }
    public void fillMatInt(boolean flag){
        Random gen = new Random();
        for(int i = 0; i < this.rows; i++)
            for(int j = 0; j < this.columns; j++)
                if(flag){
                    this.array[i][j] = (int)(gen.nextInt(10));
                }
                else{
                    this.array[i][j] = GetInput.getInt("Introduza el valor [" + i + "][" + j +"]");
                }    
    }
    //imprimir en consola
    public void printMatInt(String str){
        System.out.println(str);
        for(int i = 0; i < this.rows; i++){
            for(int j = 0; j < this.columns; j++)
                System.out.format("%10d", this.array[i][j]);
            System.out.println();
      }
    }
    //imprimir en grafico
    public void printMatIntG(){
        DecimalFormat df = new DecimalFormat("#00");

        String str = "";
        for(int i = 0; i < this.rows; i++){
            for (int j = 0; j < this.columns; j++) {
                str += df.format(array[i][j]) + "\t\t";
            }
            str += "\n";
        }
        JOptionPane.showMessageDialog(null, str);
    }
}