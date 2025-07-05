/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package estudiador.common;

/**
 *
 * @author Devas
 */
public class Option {
    public boolean correct;
    public String text;
    public String image;
    public Option(boolean ans, String image, String text){
        this.correct = ans;
        this.image = image;
        this.text = text;
    }
    public boolean isCorrect(){return this.correct;}
    public String getText(){return this.text;}
    public String getImage(){return this.image;}
    void setCorrect(boolean i){ this.correct = i;}
    void setText(String text){ this.text = text;}
    void setImage(String route){ this.image = route;}
    public void printOption(){
        System.out.println(text+" in "+image+" -> "+ (correct?"1":"0"));
    }
}
