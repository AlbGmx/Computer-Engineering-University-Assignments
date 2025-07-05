/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package estudiador.signals;
import estudiador.common.Coordenate;
import java.util.ArrayList;
import java.util.concurrent.ThreadLocalRandom;
import javax.swing.JPanel;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

/**
 *
 * @author Devas
 */
public  class Plotter{
 
    Plotter(){
     
    }
    public static ArrayList<Coordenate> createDSum(ArrayList<Coordenate> a, ArrayList<Coordenate> b){
        ArrayList<Coordenate> sum = new ArrayList();
        int i=0, j=0;
        while(i<a.size() && j<b.size()){
            if(a.get(i).getX()<b.get(j).getX()) sum.add(a.get(i++));
            else if(a.get(i).getX()>b.get(j).getX()) sum.add(b.get(j++));
            else{
                sum.add(new Coordenate(a.get(i).getX(),a.get(i).getY()+b.get(j).getY()));
                i++;
                j++;
            }
            
        }
        if(i<a.size()) sum.add(a.get(i));
        else if(j<b.size()) sum.add(b.get(j));
        return sum;
    }
    public static ArrayList<Coordenate> createDRest(ArrayList<Coordenate> a, ArrayList<Coordenate> b){
        ArrayList<Coordenate> sum = new ArrayList();
        int i=0, j=0;
        while(i<a.size() && j<b.size()){
            if(a.get(i).getX()<b.get(j).getX()) sum.add(a.get(i++));
            else if(a.get(i).getX()>b.get(j).getX()) sum.add(b.get(j++));
            else sum.add(new Coordenate(a.get(i).getX(),a.get(i++).getY()-b.get(j++).getY()));
        }
        if(i<a.size()) sum.add(a.get(i));
         else if(j<b.size()) sum.add(b.get(j));
        return sum;
    }
    public static ArrayList<Coordenate> createSum(ArrayList<Coordenate> a, ArrayList<Coordenate> b){
        ArrayList<Coordenate> sum = new ArrayList();
        for(int i=0;i<a.size();i++){
            sum.add(new Coordenate(a.get(i).getX(),a.get(i).getY()+b.get(i).getY()));
        }
        return sum;
    }
    public static ArrayList<Coordenate> createRest(ArrayList<Coordenate> a, ArrayList<Coordenate> b){
        ArrayList<Coordenate> sum = new ArrayList();
        for(int i=0;i<a.size();i++){
            sum.add(new Coordenate(a.get(i).getX(),a.get(i).getY()-b.get(i).getY()));
        }
        return sum;
    }
    public static XYSeries createSerie(ArrayList<Coordenate> serie, String title){
        XYSeries series = new XYSeries(title);
        serie.forEach((num) -> series.add(num.getX(),num.getY()));
        return series;
    }
    public static XYSeriesCollection createDataSet(ArrayList<XYSeries> series){
        final XYSeriesCollection data = new XYSeriesCollection();
        series.forEach((s)-> data.addSeries(s));
        return data;
    }
    public static XYSeriesCollection createDataSet(XYSeries series){
        final XYSeriesCollection data = new XYSeriesCollection(series);
        return data;
    }
    public static ChartPanel createChartPanel(XYSeriesCollection data, String title){
        JFreeChart chart = ChartFactory.createXYLineChart(title,"","",data);
        return new ChartPanel(chart);
    }
    public static JFreeChart createChart(XYSeriesCollection data, String title){
        return ChartFactory.createXYLineChart(title,"","",data);
    }
    public static XYSeries createSin(double amp, double a, double w,double smoothFactor, String title){
        ArrayList<Coordenate> values = new ArrayList();
        for(double i=-4*Math.PI;i<4*Math.PI;i+=smoothFactor){
            values.add(new Coordenate(i, amp*Math.sin(a*i-w)));
        }
        return createSerie(values, title);
    }
    public static XYSeries createCos(double amp, double a, double w,double smoothFactor, String title){
        ArrayList<Coordenate> values = new ArrayList();
        for(double i=-4*Math.PI;i<4*Math.PI;i+=smoothFactor){
            values.add(new Coordenate(i, amp*Math.cos(a*i-w)));
        }
        return createSerie(values, title);
    }
    public static ArrayList<Coordenate> createSinList(double amp, double a, double w,double smoothFactor){
        ArrayList<Coordenate> values = new ArrayList();
        for(double i=-4*Math.PI;i<4*Math.PI;i+=smoothFactor){
            values.add(new Coordenate(i, amp*Math.sin(a*i-w)));
        }
        return values;
    }
    public static ArrayList<Coordenate> quickSort(ArrayList<Coordenate> list) //Quicksort recursivo
    {
        if (list.isEmpty()) 
            return list; 
        ArrayList<Coordenate> sorted;  
        ArrayList<Coordenate> smaller = new ArrayList<Coordenate>(); 
        ArrayList<Coordenate> greater = new ArrayList<Coordenate>(); 
        Coordenate pivot = list.get(0); 
        Coordenate j;    
        for (int i=1;i<list.size();i++)
        {
            j=list.get(i);
            if (j.getX()<pivot.getX())   
                smaller.add(j);
            else
                greater.add(j);
        }
        smaller=quickSort(smaller);  // capitalise 's'
        greater=quickSort(greater);  // sort both halfs recursively
        smaller.add(pivot);          // add initial pivot to the end of the (now sorted) smaller Vehicles
        smaller.addAll(greater);     // add the (now sorted) greater Vehicles to the smaller ones (now smaller is essentially your sorted list)
        sorted = smaller;            // assign it to sorted; one could just as well do: return smaller

        return sorted;
    }
    public static ArrayList<Coordenate> createDiscreteRandom(){
        ArrayList<Coordenate> vector = new ArrayList();
        for(int i=0;i<6;i++){
            vector.add(new Coordenate(i-4,ThreadLocalRandom.current().nextInt(-2, 2)));
        }
        return vector;
    }
    
}

