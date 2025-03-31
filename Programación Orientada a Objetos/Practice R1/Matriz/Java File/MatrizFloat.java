import java.util.*;

import java.text.DecimalFormat;
import java.util.*;
import javax.swing.JOptionPane;

public class MatrizFloat extends Matrix{
    
    float array[][];
    
    public MatrizFloat(int renglones, int columnas){
        super(renglones, columnas);
        array = new float[renglones][columnas];
    }

    public void iniciarMatFloat(){
        Random gen = new Random();
        for(int i = 0; i < this.renglones; i++)
            for(int j = 0; j < this.columnas; j++)
                this.array[i][j] = (float)(gen.nextFloat());
        
    }
    
    //imprimir en consola
    public void imprimirMatFloat(){
        for(int i = 0; i < this.renglones; i++){
            for(int j = 0; j < this.columnas; j++)
                System.out.print(this.array[i][j] + "\t");
        System.out.println();
        }
    }

    //imprimir en grafico
    public void imprimirMatFloatG(){
        DecimalFormat df = new DecimalFormat("#00");
        String cadena = "";
        for(int i = 0; i < this.renglones; i++){
            for (int j = 0; j < this.columnas; j++) {
                cadena += df.format(array[i][j]) + "\t\t";
            }
            cadena += "\n";
        }
        JOptionPane.showMessageDialog(null, cadena);
    }

}