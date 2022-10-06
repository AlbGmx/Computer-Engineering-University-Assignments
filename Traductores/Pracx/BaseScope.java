package Prac8;
import java.util.HashMap;
import java.util.Map;

import Scope;
import Symbol;

public class BaseScope implements Scope {
   Scope enclosingScope;
   Map<String, Symbol> members = new HashMap<String, Symbol>();

   public BaseScope(Scope currentScope) {
      this.enclosingScope = currentScope;
   }

   public Scope getEnclosingScope() {
      return enclosingScope;
   }

   public void define(Symbol sym) {
      members.put(sym.getName(), sym);
   }

   public Symbol resolve(String name) {
      Symbol s = members.get(name);
      if (s != null)
         return s;
      if (enclosingScope != null)
         return enclosingScope.resolve(name);
      return null;
   }

   @Override
   public String getScopeName() {
      // TODO Auto-generated method stub
      return null;
   }
}
