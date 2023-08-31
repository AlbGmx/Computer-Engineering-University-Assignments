import java.util.*;
public class Alumno extends Persona {
  /**
   *
   */
  private static final long serialVersionUID = 8433117780406384395L;
  double ID;
  float avg;

  public Alumno(double ID, float avg, String name, String mail, String account){
    super(name, mail, account);
    setID(ID);
    setAvg(avg);
    setName(name);
    setMail(mail);
    setAccount(account);        
  }

  public void setID(double ID) {
    this.ID = ID;
  }

  public void setAvg(float avg) {
    this.avg = avg;
  }
  
  public void setName(String name) {
    this.name = name;
  }
  
  public void setMail(String mail) {
    this.mail = mail;
  }

  public void setAccount(String account) {
    this.account = account;
  }

  public String getAccount() {
    return account;
  }

  public String getMail() {
    return mail;
  }
  
  public String getName() {
    return name;
  }
  
  public float getAvg() {
    return avg;
  }

  public double getID() {
    return ID;
  }

  public static Alumno getStudent() {
    System.out.println("\n\tCapturar datos del Alumno");
    Alumno temp = new Alumno(GetInput.getDouble("Matricula"),GetInput.getFloat("Promedio"), GetInput.getLine("Nombre"),
        GetInput.getLine("Correo"), GetInput.getLine("Cuenta"));
    return temp;
  }

  public static List<Alumno> createListStudents() {
    List<Alumno> listStudents = new ArrayList<Alumno>();
    boolean user = true;
    while (user) {
      listStudents.add(Alumno.getStudent());
      if (GetInput.getBoolean("Desea agregar otro alumno a la lista? (y/n)")) {
      } else
        user = false;
    }
    return listStudents;
  }
  public static void showStudents(List<Alumno> listStudents) {
    for (int i = 0; i < listStudents.size(); i++) {
      System.out.println("\nAlumno " + (i+1) + ": ");
      System.out.println("\tNombre: " + listStudents.get(i).getName());
      System.out.println("\tMatricula: " + listStudents.get(i).getID());
      System.out.println("\tPromedio: " + listStudents.get(i).getAvg());
      System.out.println("\tCorreo: " + listStudents.get(i).getMail());
      System.out.println("\tCuenta: " + listStudents.get(i).getAccount() + "\n");
    }
  }

  public static void showStudent(List<Alumno> listStudents, int i) {
    System.out.println("\nAlumno " + (1+i) + ": ");
    System.out.println("\tNombre: " + listStudents.get(i).getName());
    System.out.println("\tMatricula: " + listStudents.get(i).getID());
    System.out.println("\tPromedio: " + listStudents.get(i).getAvg());
    System.out.println("\tCorreo: " + listStudents.get(i).getMail());
    System.out.println("\tCuenta: " + listStudents.get(i).getAccount() + "\n");
  }
}