public class Symbol {
    String name;
    Type type;
    int intValue;
    float floatValue;

    public Symbol(String name) {
        this.name = name;
    }

    public Symbol(String name, Type type) {
        this(name);
        this.type = type;
    }

    public Symbol(String name, Type type, int intValue) {
        this.name = name;
        this.type = type;
        this.intValue = intValue;
    }

    public Symbol(String name, Type type, float floatValue) {
        this.name = name;
        this.type = type;
        this.floatValue = floatValue;
    }
    
    public void setInt(int intValue) {
        this.intValue = intValue;
    }

    public void setFloat(float floatValue) {
        this.floatValue = floatValue;
    }

    public String getName() {
        return name;
    }

    public String toString() {
        if(type != null) {
            return '<' + getName() + ":" + type + '>';
        }
        return getName();
    }
}