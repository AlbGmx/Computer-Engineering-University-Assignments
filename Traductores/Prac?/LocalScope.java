package Prac8;
import Scope;

public class LocalScope extends BaseScope {
   public LocalScope(Scope currentScope) {
      super(currentScope);
   }

   public String getScopeName() {
      return "Local";
   }
}