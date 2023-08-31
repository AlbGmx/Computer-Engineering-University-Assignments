public class VariableSymbol extends Symbol {
    public VariableSymbol(String name, Type type) {
        super(name, type);
    }

    public VariableSymbol(String name, Type type, int intValue) {
        super(name, type, intValue);
    }

    public VariableSymbol(String name, Type type, float floatValue) {
        super(name, type, floatValue);
    }
}
