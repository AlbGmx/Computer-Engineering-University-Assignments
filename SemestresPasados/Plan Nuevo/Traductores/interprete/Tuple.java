import java.util.Arrays;

public class Tuple {
    private int position;
    private String instruction;
    private String[] parameters;
    private int nextPositionIfTrue;
    private int nextPositionIfFalse;

    public Tuple(int position, String instruction, String[] parameters, int nextPositionIfTrue, int nextPositionIfFalse) {
        this.position = position;
        this.instruction = instruction;
        this.parameters = parameters;
        this.nextPositionIfTrue = nextPositionIfTrue;
        this.nextPositionIfFalse = nextPositionIfFalse;
    }

    public int getPosition() {
        return this.position;
    }

    public void setPosition(int position) {
        this.position = position;
    }

    public String getInstruction() {
        return this.instruction;
    }

    public void setInstruction(String instruction) {
        this.instruction = instruction;
    }

    public String[] getParameters() {
        return this.parameters;
    }

    public String getParam(int index) {
        return this.parameters[index];
    }

    public void setParameters(String[] params) {
        this.parameters = params;
    }

    public void setParam(int index, String string) {
        this.parameters[index] = String.valueOf(string);
    }

    public int getNextPositionIfTrue() {
        return this.nextPositionIfTrue;
    }

    public void setNextPositionIfTrue(int nextPositionIfTrue) {
        this.nextPositionIfTrue = nextPositionIfTrue;
    }

    public int getNextPositionIfFalse() {
        return this.nextPositionIfFalse;
    }

    public void setNextPositionIfFalse(int nextPositionIfFalse) {
        this.nextPositionIfFalse = nextPositionIfFalse;
    }

    public String toString() {
        return "( " + getPosition() + ", " +
                getInstruction() + ", " +
                Arrays.toString(getParameters()) + ", " +
                getNextPositionIfTrue() + ", " +
                getNextPositionIfFalse() + " )";
    }
}
