import java.util.*;

public class Listas {
  public static void main(String[] args) {
    boolean menu = true;
    boolean user = true;
    List<Alumno> listStudents = new ArrayList<Alumno>();
    List<Profesor> listTeachers = new ArrayList<Profesor>();
    while(menu){
      Menu.menuRFC();
      String opc = GetInput.getLine("Seleccione una opcion");
      switch (opc) {
        case "5":
          user = true;
          while (user) {
            listTeachers.add(Profesor.getTeacher());
            if (GetInput.getBoolean("Desea agregar otro profesor a la lista? (y/n)"));
            else  user = false;
          }
        break;
        case "6":
          user = true;
          while (user) {
            listStudents.add(Alumno.getStudent());
            if (GetInput.getBoolean("Desea agregar otro alumno a la lista? (y/n)"));   
            else user = false;
          }
          break;
        case "7":
          if ((listTeachers.size() == 0) & (listStudents.size() == 0))
            System.out.println("\tNo se han encontrado datos...");
          else {
            Profesor.showTeachers(listTeachers);
            Alumno.showStudents(listStudents);
          }
        break;        
        case "8":
          if (listStudents.size() > 0) {
            Object2File.printStudentsList2File(listStudents, "Alumnos.bin");
          } else
            System.out.println("No existen datos a guardar");
          if (listTeachers.size() > 0) {
            Object2File.printTeachersList2File(listTeachers, "Profesores.bin");
          } else
            System.out.println("No existen datos a guardar");
          break;
        case "9":
          listStudents = Object2File.readStudentsListFromFile("Alumnos.bin");
          listTeachers = Object2File.readTeachersListFromFile("Profesores.bin");
        break;
        case "0":
          menu = false;
        break;
      }
    }    
  }
}