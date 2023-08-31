import pelicula.*;
import java.util.ArrayList;
import FileManipulation;
public class Main extends JFrame{
    public static void main(String args[]){
        Director dirAdamsonA = new Director("Andrew", "Adamson",13, 4);
        Director dirMillerC = new Director("Christopher", "Miller", 8, 9);
        Director dirRaimiS = new Director("Samuel", "Raimi",14, 1);
        Director dirStahelskiC = new Director("Chad", "Stahelski", 5, 0);

        Genero gnrAccion = new Genero("Accion");
        Genero gnrComedia = new Genero("Comedia");
        Genero gnrFantasia = new Genero("Fantasia");
        Genero gnrSuperheroes = new Genero("Superheroes");

        ArrayList<Pelicula> object = new ArrayList<Pelicula>("John Wick: Sin Control", 2014, dirStahelskiC,"src/media/images/img_JohnWick.jpg",gnrAccion);
        object.add("John Wick: Un Nuevo Dia Para Matar", 2017, dirStahelskiC,"src/media/images/img_JohnWick_2.jpg",gnrAccion);
        object.add("John Wick 3: Parabellum", 2019, dirStahelskiC,"src/media/images/img_JohnWick_3.jpg",gnrAccion);
        object.add("Shrek", 2002, dirAdamsonA,"src/media/images/img_Shrek.jpg",gnrComedia);
        object.add("Shrek 2", 2004, dirAdamsonA,"src/media/images/img_Shrek_2.jpg",gnrFantasia);
        object.add("Shrek Tercero", 2007, dirMillerC,"src/media/images/img_Shrek_3.jpg",gnrFantasia);
        object.add("Spider-Man", 2002, dirRaimiS,"src/media/images/img_Spiderman.jpg",gnrSuperheroes);
        object.add("Spider-Man 2", 2004, dirRaimiS,"src/media/images/img_Spiderman_2.jpg",gnrAccion);
        
        writeToFile("write.txt", object);
    }
}
