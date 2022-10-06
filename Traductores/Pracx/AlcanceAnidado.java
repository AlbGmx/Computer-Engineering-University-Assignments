package Prac8;
import BuiltInTypeSymbol;
import Scope;
import Symbol;
import VariableSymbol;

public class AlcanceAnidado {
   public static void main(String[] args) {
      Scope currentScope;

      currentScope = new GlobalScope();
      currentScope.define(new Symbol("int"));
      currentScope.define(new Symbol("float"));
      currentScope.define(new Symbol("void"));

      BuiltInTypeSymbol t1 = (BuiltInTypeSymbol) currentScope.resolve("int");
      if (t1 != null) {
         System.out.println("t1 = " + t1);
      }

      currentScope.define(new VariableSymbol("i", t1));

      BuiltInTypeSymbol returnType = (BuiltInTypeSymbol) currentScope.resolve("float");
      if (returnType != null) {
         System.out.println("returnType = " + returnType);
      }

      BuiltInTypeSymbol t2 = (BuiltInTypeSymbol) currentScope.resolve("int");
      if (t2 != null) {
         System.out.println("t2 = " + t2);
      }

      BuiltInTypeSymbol t3 = (BuiltInTypeSymbol) currentScope.resolve("int");
      if (t2 != null) {
         System.out.println("t2 = " + t2);
      }

      VariableSymbol parameters[] = { new VariableSymbol("x", t2), new VariableSymbol("y", t3) };
      currentScope = new MethodSymbol("f", parameters, currentScope);

      t1 = (BuiltInTypeSymbol) currentScope.resolve("float");
      if (t1 != null) {
         System.out.println("t1 = " + t1);
      }

      currentScope.define(new VariableSymbol("i", t1));

      currentScope = new LocalScope(currentScope);

      t1 = (BuiltInTypeSymbol) currentScope.resolve("float");
      if (t1 != null) {
         System.out.println("t1 = " + t1);
      }

      currentScope.define(new VariableSymbol("z", t1));

      VariableSymbol v1 = (VariableSymbol) currentScope.resolve("x");
      if (v1 != null) {
         System.out.println("v1 = " + v1);
      }

      VariableSymbol v2 = (VariableSymbol) currentScope.resolve("y");
      if (v2 != null) {
         System.out.println("v2 = " + v2);
      }

      v1 = (VariableSymbol) currentScope.resolve("i");
      if (v1 != null) {
         System.out.println("v1 = " + v1);
      }

      v2 = (VariableSymbol) currentScope.resolve("z");
      if (v2 != null) {
         System.out.println("v2 = " + v2);
      }

      currentScope = currentScope.getEnclosingScope();
   }
}