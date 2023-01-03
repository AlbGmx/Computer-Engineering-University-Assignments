public class AlcanceAninado {

    public static void main(String args[]) {
        Scope currentScope;

        currentScope = new GlobalScope();
        currentScope.define(new BuiltInTypeSymbol("int"));
        currentScope.define(new BuiltInTypeSymbol("float"));
        currentScope.define(new BuiltInTypeSymbol("void"));
        StructSymbol ss = new StructSymbol("A", currentScope);
        
        currentScope.define(ss);
        currentScope = ss;

        BuiltInTypeSymbol t1 = (BuiltInTypeSymbol) currentScope.resolve("int");
        if(t1 == null) { 
            throw new RuntimeException("Not Defined" + t1);
        }
        currentScope.define(new VariableSymbol("x", t1));

        BuiltInTypeSymbol t2 = (BuiltInTypeSymbol) currentScope.resolve("float");
        if(t2 == null) { 
            throw new RuntimeException("Not Defined" + t2);
        }
        currentScope.define(new VariableSymbol("y", t2));

        System.out.println(currentScope);

        currentScope = currentScope.getEnclosingScope();
        System.out.println(currentScope);

        BuiltInTypeSymbol returnType = (BuiltInTypeSymbol) currentScope.resolve("void");
        if(returnType == null) {
            throw new RuntimeException("Not Defined" + returnType);
        }

        currentScope = new MethodSymbol("f", null, currentScope);

        StructSymbol s1 = (StructSymbol) currentScope.resolve("A");
        if(s1 == null) { 
            throw new RuntimeException("Not Defined" + s1);
        }
        currentScope.define(new StructSymbol("a",s1));
        System.out.println(s1.resolve("x"));
    }
    
}
