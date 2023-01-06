public class AlcanceAninado {

    public static void main(String args[]) {
        Scope currentScope;

        currentScope = new GlobalScope();
        currentScope.define(new BuiltInTypeSymbol("int"));
        currentScope.define(new BuiltInTypeSymbol("float"));
        currentScope.define(new BuiltInTypeSymbol("void"));

        BuiltInTypeSymbol t1 = (BuiltInTypeSymbol) currentScope.resolve("int");
        if(t1 == null) { 
            throw new RuntimeException("Not Defined" + t1);
        }
        currentScope.define(new VariableSymbol("i", t1));

        BuiltInTypeSymbol returnType = (BuiltInTypeSymbol) currentScope.resolve("float");
        if(returnType == null) { 
            throw new RuntimeException("Not Defined" + returnType);
        }

        BuiltInTypeSymbol t2 = (BuiltInTypeSymbol) currentScope.resolve("int");
        if(t2 == null) { 
            throw new RuntimeException("Not Defined" + t2);
        }

        BuiltInTypeSymbol t3 = (BuiltInTypeSymbol) currentScope.resolve("int");
        if(t3 == null) { 
            throw new RuntimeException("Not Defined" + t3);
        }

        VariableSymbol parameters[] = {new VariableSymbol("x", t2), new VariableSymbol("y", t3)};

        currentScope = new MethodSymbol("f", parameters, currentScope);

        t1 = (BuiltInTypeSymbol) currentScope.resolve("float");
        if(t1 == null) { 
            throw new RuntimeException("Not Defined" + t1);
        }
        currentScope.define(new VariableSymbol("i", t1));

        currentScope = new LocalScope(currentScope);

        t1 = (BuiltInTypeSymbol) currentScope.resolve("float");
        if(t1 == null) { 
            throw new RuntimeException("Not Defined" + t1);
        }
        currentScope.define(new VariableSymbol("z", t1));

        VariableSymbol v1 = (VariableSymbol) currentScope.resolve("x");
        if(v1 == null) {
            throw new RuntimeException("Not Defined" + v1);
        }

        VariableSymbol v2 = (VariableSymbol) currentScope.resolve("y");
        if(v2 == null) {
            throw new RuntimeException("Not Defined" + v2);
        }

        v1 = (VariableSymbol) currentScope.resolve("i");
        if(v1 == null) {
            throw new RuntimeException("Not Defined" + v1);
        }

        v2 = (VariableSymbol) currentScope.resolve("z");
        if(v2 == null) {
            throw new RuntimeException("Not Defined" + v2);
        }

        currentScope = currentScope.getEnclosingScope();
        System.out.println(currentScope);

        currentScope = new LocalScope(currentScope);

        t1 = (BuiltInTypeSymbol) currentScope.resolve("float");
        if(t1 == null) { 
            throw new RuntimeException("Not Defined" + t1);
        }
        currentScope.define(new VariableSymbol("z", t1));

        v1 = (VariableSymbol) currentScope.resolve("i");
        if(v1 == null) {
            throw new RuntimeException("Not Defined" + v1);
        }

        v1 = (VariableSymbol) currentScope.resolve("i");
        if(v1 == null) {
            throw new RuntimeException("Not Defined" + v1);
        }

        v2 = (VariableSymbol) currentScope.resolve("z");
        if(v2 == null) {
            throw new RuntimeException("Not Defined" + v2);
        }

        currentScope = currentScope.getEnclosingScope();
        System.out.println(currentScope);

        currentScope = currentScope.getEnclosingScope();
        System.out.println(currentScope);

        currentScope = new MethodSymbol("g", null, currentScope);

        currentScope = new LocalScope(currentScope);

        t1 = (BuiltInTypeSymbol) currentScope.resolve("int");
        if(t1 == null) { 
            throw new RuntimeException("Not Defined" + t1);
        }

        currentScope = currentScope.getEnclosingScope();
        System.out.println(currentScope);

        currentScope = currentScope.getEnclosingScope();
        System.out.println(currentScope);

        currentScope = currentScope.getEnclosingScope();
        System.out.println(currentScope);

    }
    
}
