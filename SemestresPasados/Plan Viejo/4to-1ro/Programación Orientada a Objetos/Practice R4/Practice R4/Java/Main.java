public class Main {
    static final int doNotShowMenus = 0;
    static final int showNamesMenus = 1;
    static final int showBigStringMenus = 2;
    public static void main(String[] args) {
        boolean menu = true;
        int show = doNotShowMenus;
        String opt = "";
        String bigString = "";
        String name = "";
        String firstName = "";
        String secondName = "";

        while(menu){
            Menu.main(show);
            opt = GetInput.getLine("Select an option");
            switch (opt.toUpperCase()){
                case "A":   
                    name = GetInput.getLine("Type only your name");
                    firstName = GetInput.getLine("Type your First family name");
                    secondName = GetInput.getLine("Type your Second family name");
                    show = showNamesMenus;
                break;
                case "B":
                    StringHandling.countCharacters(name);
                    StringHandling.countCharacters(firstName);
                    StringHandling.countCharacters(secondName);
                break;
                case "C":
                    bigString = name + firstName + secondName;
                    show = showBigStringMenus;
                    System.out.println("\nbigString: " + bigString);
                break;
                case "D":
                    StringHandling.countCharacters(bigString);
                break;
                case "E":
                    StringHandling.countDifCharacters(bigString);
                break;
                case "F":
                StringHandling.countSubstringAppears(bigString, "al");
                StringHandling.countSubstringAppears(bigString, "sum");
                StringHandling.countSubstringAppears(bigString, "acr");
                break;
                case "G":
                    StringHandling.countThisCharacter(" ", bigString);
                break;
                case "0":
                    menu = false;
                break;
            }


        }
    }
    
}