public interface Scope {
   public String getScopeName(); // Do I have a name?

   public Scope getEnclosingScope(); // Am I nested in another?

   public void define(Symbol sym); // Define symbol in this scope

   public Symbol resolve(String name); // Look up name in this scope
}
