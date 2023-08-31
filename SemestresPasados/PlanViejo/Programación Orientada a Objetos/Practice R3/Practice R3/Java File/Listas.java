import java.util.*;

public class Listas {
  public static void main(String[] args) {
    boolean menu = true;
    boolean user = true;
    List<Alumno> listStudents = new ArrayList<Alumno>();
    List<Profesor> listTeachers = new ArrayList<Profesor>();
    while(menu){
      Menu.main();
      String opc = GetInput.getLine("Seleccione una opcion");
      switch (opc) {
        case "1":
          listStudents = Object2File.readStudentsListFromFile(GetInput.getLine("Nombre de archivo"));
          break;
        case "2":
          listTeachers = Object2File.readTeachersListFromFile(GetInput.getLine("Nombre de archivo"));
          break;
        case "3":
          listStudents = Alumno.createListStudents();
          break;
        case "4":
          listTeachers = Profesor.createListTeachers();
          break;
        case "5":
          if (listStudents.size() > 0) {
            user = true;
            while (user) {
              listStudents.add(Alumno.getStudent());
              if (GetInput.getBoolean("Desea agregar otro alumno a la lista? (y/n)")) {
              } else
                user = false;
            }
          } else
            System.out.println("No se encontro la lista de alumnos, favor de primero crear una");
          break;
        case "6":
          if (listTeachers.size() > 0) {
            user = true;
            while (user) {
              listTeachers.add(Profesor.getTeacher());
              if (GetInput.getBoolean("Desea agregar otro alumno a la lista? (y/n)")) {
              } else
                user = false;
            }
          } else
            System.out.println("No se encontro la lista de profesores, favor de primero crear una");
          break;
        case "7":
          if (listStudents.size() > 0) {
            Object2File.printStudentsList2File(listStudents, GetInput.getLine("Nombre de archivo"));
          } else
            System.out.println("No existen datos a guardar");
          break;
        case "8":
          if (listTeachers.size() > 0) {
            Object2File.printTeachersList2File(listTeachers, GetInput.getLine("Nombre de archivo"));
          } else
            System.out.println("No existen datos a guardar");
          break;
        case "9":
          if ((listTeachers.size() == 0) & (listStudents.size() == 0))
            System.out.println("\tNo se han encontrado datos...");
          else {
            Profesor.showTeachers(listTeachers);
            Alumno.showStudents(listStudents);
          }
          break;
        case "0":
          menu = false;
          break;
      }
    }    
  }
}