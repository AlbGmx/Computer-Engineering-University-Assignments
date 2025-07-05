package estudiador.common;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Question {
    public String questText;
    public ArrayList <Option> opciones;
    public Question(String title, ArrayList<Option> options){
        this.questText = title;
        opciones = options;
    }
    public Question(String line){
        opciones = new ArrayList();
        fillFromString(line);
    }
    public void setTitulo(String title){ this.questText = title;}
    public void addOpcion(Option op){this.opciones.add(op);}
    public String getTitulo(){ return this.questText;}
    public ArrayList <Option> getOpciones(){return this.opciones;}
    public int getOptionsNum(){return opciones.size();}
    public Option getOpcion(int i){
        if(this.opciones.size()<=i){
            return null;
        }else{
            return this.opciones.get(i);
        }
    }
    public Option getAnswer(){ 
        for(int i=0;i<opciones.size();i++){
            if(opciones.get(i).isCorrect()){
                return opciones.get(i);
            }
        }
        return null;
    }
    public int getAnswerIndex(){ 
        for(int i=0;i<opciones.size();i++){
            if(opciones.get(i).isCorrect()){
                return i;
            }
        }
        return -1;
    }
    public void fillFromString(String st){
        List<String> fields = Arrays.asList(st.split(";"));
        questText = fields.get(0);
        for(int i=1;i<fields.size();i+=3){
            opciones.add(new Option(fields.get(i).equalsIgnoreCase("true"),fields.get(i+1),fields.get(i+2)));
        }
    }
    public void printQuestion(){
        System.out.println(questText);
        opciones.forEach(((op)-> op.printOption()));
    }
}

