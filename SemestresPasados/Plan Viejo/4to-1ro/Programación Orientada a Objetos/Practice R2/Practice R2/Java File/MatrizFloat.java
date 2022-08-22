import java.text.DecimalFormat;
import java.util.*;
import javax.swing.JOptionPane;

public class MatrizFloat extends Matriz{
    
    float array[][];
    
    public MatrizFloat(int rows, int columns){
        super(rows, columns);
        array = new float[rows][columns];
    }

    public void fillMatFloat(boolean flag){
        Random gen = new Random();
        for(int i = 0; i < this.rows; i++){
            for(int j = 0; j < this.columns; j++){
                if(flag){
                    this.array[i][j] = (float)(10*gen.nextFloat());
                }
                else{
                    this.array[i][j] = (GetInput.getFloat("\nIntroduza el valor [" + i + "][" + j + "]"));
                }    
            }
        }
    }
    
    //imprimir en consola
    public void printMatFloat(String str){
        System.out.println(str);
        for(int i = 0; i < this.rows; i++){
            for(int j = 0; j < this.columns; j++)
                System.out.format("%10.2f",this.array[i][j]);
        System.out.println();
        }
    }

    //imprimir en grafico
    public void printMatFloatG(){
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