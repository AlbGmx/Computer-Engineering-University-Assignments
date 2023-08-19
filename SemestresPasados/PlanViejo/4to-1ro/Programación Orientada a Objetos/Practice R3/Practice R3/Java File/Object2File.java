import java.io.*;
import java.util.*;

public class Object2File {

  public static List<Alumno> readStudentsListFromFile(String fileName) {
    List<Alumno> listStudents = new ArrayList<Alumno>();
    FileInputStream file = null;
    try {
      file = new FileInputStream(fileName);
      ObjectInputStream tube = new ObjectInputStream(file);
      listStudents = (ArrayList<Alumno>) tube.readObject();
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    } catch (ClassNotFoundException e) {
      e.printStackTrace();
    }
    System.out.println("Lista de alumnos cargada...");
    return listStudents;
  }

  public static List<Profesor> readTeachersListFromFile(String fileName) {
    List<Profesor> listTeachers = new ArrayList<Profesor>();
    FileInputStream file = null;
    try {
      file = new FileInputStream(fileName);
      ObjectInputStream tube = new ObjectInputStream(file);
      listTeachers = (ArrayList<Profesor>) tube.readObject();
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    } catch (ClassNotFoundException e) {
      e.printStackTrace();
    }
    System.out.println("Lista de profesores cargada...");
    return listTeachers;
  }

  public static void printStudentsList2File(List<Alumno> listStudents, String fileName) {
    FileOutputStream file = null;
    try {
      file = new FileOutputStream(fileName);
      ObjectOutputStream tube = new ObjectOutputStream(file);
      tube.writeObject(listStudents);
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    } finally {
      try {
        file.close();
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
    System.out.println("Lista de alumnos guardada...");
  }

  public static void printTeachersList2File(List<Profesor> listTeachers, String fileName) {
    FileOutputStream file = null;
    try {
      file = new FileOutputStream(fileName);
      ObjectOutputStream tube = new ObjectOutputStream(file);
      tube.writeObject(listTeachers);
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    } finally {
      try {
        file.close();
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
    System.out.println("Lista de profesores guardada...");
  }
}