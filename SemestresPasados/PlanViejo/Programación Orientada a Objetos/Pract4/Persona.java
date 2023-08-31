import java.io.Serializable;

public class Persona implements Serializable{
  /**
	 *
	 */
	private static final long serialVersionUID = -5118100802209803888L;
String name;
  String mail;
  String account;

  public Persona(final String name, final String mail, final String account) {
    setName(name);
    setMail(mail);
    setAccount(account);
  }

  public void setName(final String mail) {
    this.mail = mail;
  }

  public void setMail(final String mail) {
    this.mail = mail;
  }

  public void setAccount(final String account) {
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
}