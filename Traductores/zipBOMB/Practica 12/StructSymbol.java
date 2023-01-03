import java.util.HashMap;
import java.util.Map;

public class StructSymbol extends Symbol implements Scope{
    Scope enclosingScope;
    Map<String, Symbol> members = new HashMap<String, Symbol>();
    
    public StructSymbol(String name, Scope enclosingScope) {
        super(name);
        this.enclosingScope = enclosingScope;
    }

    public String getScopeName() {
        return name;
    }

    public Scope getEnclosingScope() {
        return enclosingScope;
    }

    public void define(Symbol sym) {
        members.put(sym.name, sym);
    }

    public String toString(){
        return "struct" + name+":{"+
                stripBrackets(members.keySet().toString())+"}";
    }

    private String stripBrackets(String string) {
        return string.replaceAll("\\p{P}","");
    }

    public Symbol resolve(String name) {
        Symbol s = members.get(name);
        if(s != null)
            return s;

        if(enclosingScope != null)
            return enclosingScope.resolve(name);

        return null;
    }
}
