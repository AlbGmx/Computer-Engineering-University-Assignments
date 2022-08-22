import java.util.*;
public class Profesor extends Persona {
  /**
   *
   */
  private static final long serialVersionUID = 4466500291757430756L;
  int ID;
  String cubicle;

  public Profesor(final int ID, final String name, final String mail, final String cubicle, final String account) {
    super(name, mail, account);
    setID(ID);
    setName(name);
    setMail(mail);
    setCubicle(cubicle);
    setAccount(account);
  }

  public void setID(final int ID) {
    this.ID = ID;
  }

  public void setName(final String name) {
    this.name = name;
  }

  public void setMail(final String mail) {
    this.mail = mail;
  }

  public void setCubicle(final String cubicle) {
    this.cubicle = cubicle;
  }

  public void setAccount(final String account) {
    this.account = account;
  }

  public String getAccount() {
    return this.account;
  }

  public String getMail() {
    return this.mail;
  }
  
  public String getName() {
    return this.name;
  }
  
  public String getCubicle() {
    return this.cubicle;
  }

  public int getID() {
    return this.ID;
  }

  public static List<Profesor> createListTeachers() {
    List<Profesor> listTeachers = new ArrayList<Profesor>();
    boolean user = true;
    while (user) {
      listTeachers.add(Profesor.getTeacher());
      if (GetInput.getBoolean("Desea agregar otro profesor a la lista? (y/n)")) {
      } else
        user = false;
    }
    return listTeachers;
  }

  public static Profesor getTeacher() {
    System.out.println("\n\tCapturar datos del maestro");
    Profesor temp = new Profesor(GetInput.getInt("Numero de identificacion"), GetInput.getLine("Nombre"),
        GetInput.getLine("Correo"), GetInput.getLine("Cubiculo"), GetInput.getLine("Cuenta de Facebook"));
    return temp;
  }

  public static void showTeachers(List<Profesor> listTeachers) {
    for (int i = 0; i < listTeachers.size(); i++) {
      System.out.println("\nProfesor " + (i+1) + ":");
      System.out.println("\tNombre: " + listTeachers.get(i).getName());
      System.out.println("\tNO. de Identificacion: " + listTeachers.get(i).getID());
      System.out.println("\tCubiculo:" + listTeachers.get(i).getCubicle());
      System.out.println("\tCorreo:" + listTeachers.get(i).getMail());
      System.out.println("\tCuenta:" + listTeachers.get(i).getAccount() + "\n");
    }
  }

  public static void showTeacher(List<Profesor> listTeachers, int i) {
    System.out.println("\nProfesor " + (i+1) + " : ");
    System.out.println("\tNombre: " + listTeachers.get(i).getName());
    System.out.println("\tNO. de Identificacion: " + listTeachers.get(i).getID());
    System.out.println("\tCubiculo: " + listTeachers.get(i).getCubicle());
    System.out.println("\tCorreo: " + listTeachers.get(i).getMail());
    System.out.println("\tCuenta: " + listTeachers.get(i).getAccount() + "\n");
  }
}