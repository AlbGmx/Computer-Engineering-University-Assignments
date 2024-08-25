import java.util.Arrays;

public class Tuple {
    private int line;
    private String instruction;
    private String[] params;
    private int trueLine;
    private int falseLine;

    public Tuple(int line, String instruction, String[] params, int trueLine, int falseLine) {
        this.line = line;
        this.instruction = instruction;
        this.params = params;
        this.trueLine = trueLine;
        this.falseLine = falseLine;
    }


    public int getLine() {
        return this.line;
    }

    public void setLine(int line) {
        this.line = line;
    }

    public String getInstruction() {
        return this.instruction;
    }

    public void setInstruction(String instruction) {
        this.instruction = instruction;
    }

    public String[] getParams() {
        return this.params;
    }

    public String getParam(int index) {
        return this.params[index];
    }

    public void setParams(String[] params) {
        this.params = params;
    }

    public void setParam(int index, String string) {
        this.params[index] = String.valueOf(string);
    }

    public int getTrueLine() {
        return this.trueLine;
    }

    public void setTrueLine(int trueLine) {
        this.trueLine = trueLine;
    }

    public int getFalseLine() {
        return this.falseLine;
    }

    public void setFalseLine(int falseLine) {
        this.falseLine = falseLine;
    }
    
    public String toString() {
        return "( " + getLine() + ", " +
                getInstruction() + ", " +
                Arrays.toString(getParams()) + ", " +
                getTrueLine() + ", " + 
                getFalseLine() + " )";
    }

}
