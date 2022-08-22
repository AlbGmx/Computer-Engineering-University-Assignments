
public class Token {
   public int type;
   public String text;
   public Token(int type, String string){
      this.type=type;
      this.text=string;
   }
   public String toString(){
      String tname = Listlexer.tokenNames[type];
      return "<'"+text+"',"+tname+">";
   }
}
