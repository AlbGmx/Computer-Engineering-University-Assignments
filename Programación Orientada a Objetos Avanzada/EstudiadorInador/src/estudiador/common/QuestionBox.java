/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package estudiador.common;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.concurrent.ThreadLocalRandom;

/**
 *
 * @author Devas
 */
public class QuestionBox {
    ArrayList<Question> questions;
    public QuestionBox(String sourceFile){
        questions = new ArrayList();
        retrieveInfo(sourceFile);
    }
    public void retrieveInfo(String fileName){
        BufferedReader br = null;
        try {
            File file = new File(fileName);
            br = new BufferedReader(new FileReader(file));
           
            String st;
            while ((st = br.readLine()) != null){ 
                questions.add(new Question(st));
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(QuestionBox.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(QuestionBox.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                br.close();
            } catch (IOException ex) {
                Logger.getLogger(QuestionBox.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    public void printQuestions(){
        questions.forEach((q) -> q.printQuestion());
    }
    public Question getRandomQ(){
        return questions.get(ThreadLocalRandom.current().nextInt(0, questions.size()));
    }
}
