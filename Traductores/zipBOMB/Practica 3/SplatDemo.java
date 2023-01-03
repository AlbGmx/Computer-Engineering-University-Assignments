import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class SplatDemo {
    
    private static final String REGEX = ":";
    private static final String INPUT =
        "one:two:three:four:five";

    public static void main(String[] args) {

        Pattern pattern = Pattern.compile(REGEX);
        String[] items = pattern.split(INPUT);
        for(String s : items) {
            System.out.println(s);
        }
    }
}
