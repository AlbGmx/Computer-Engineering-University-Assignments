    public class RFC{
    public static String generateRFC(String name, String firstLastName, String secondLastName, int year, int month, int day){
        String rfc = "";

        rfc = rfc.concat(getFirstLetter(firstLastName)); 
        rfc = rfc.concat(getVocal(firstLastName));
        rfc = rfc.concat(getFirstLetter(secondLastName));
        rfc = rfc.concat(getFirstLetter(name));
        rfc = rfc.concat(intToString(year));
        rfc = rfc.concat(intToString(month));
        rfc = rfc.concat(intToString(day));
        rfc = rfc.concat(operacionClaveDif(stringClaveDif(name, firstLastName, secondLastName)));
        rfc = rfc.concat(digVerRegFedContribuyentes(rfc));

        System.out.println(rfc);
        return rfc;
    }

    public static String getFirstLetter(String word){
        String character = "" + word.charAt(0);

        return character;
    }

    public static String getVocal(String word){
        int index = 100;
        String tempWord = word.toUpperCase();

        if(word.indexOf('A') < index && tempWord.indexOf('A') > 0) index = tempWord.indexOf('A');
        if(word.indexOf('I') < index && tempWord.indexOf('I') > 0) index = tempWord.indexOf('I');
        if(word.indexOf('O') < index && tempWord.indexOf('O') > 0) index = tempWord.indexOf('O');
        if(word.indexOf('E') < index && tempWord.indexOf('E') > 0) index = tempWord.indexOf('E');
        if(word.indexOf('U') < index && tempWord.indexOf('U') > 0) index = tempWord.indexOf('U');

        String character = "" + word.charAt(index);
        return character;
    }

    public static String intToString(int number){

        if(number > 100) number = number % 100;
        String string = String.format("%02d", number);

        return string;
    }

    public static int stringToInt(String string){
        int number = Integer.parseInt(string);
        return number;
    }

    public static String stringClaveDif(String name, String firstLastname, String secondLastname){
        String valores = "0";

        for(int i = 0; i < firstLastname.length(); i++){
            valores = valores.concat(String.format("%02d", valueLetter(firstLastname.charAt(i))));
        }
        valores = valores.concat("00");
        for(int i = 0; i < secondLastname.length(); i++){
            valores = valores.concat(String.format("%02d", valueLetter(secondLastname.charAt(i))));
        }
        valores = valores.concat("00");
        for(int i = 0; i < name.length(); i++){
            valores = valores.concat(String.format("%02d", valueLetter(name.charAt(i))));
        }
        
        return valores;
    }

    public static int valueLetter(char letter){
        int value = (int)letter-54;
        if(value > 19) value += 1;
        if(value > 29) value += 2;
        
        if(value == -22) value = 0;

        return value;
    }

    public static String numToCharClaveDif(int num){
        String character = "";

        if(num < 9){
            character = String.valueOf((char)(num+49));
        }
        else{
            character = String.valueOf((char)(num+56));
        }

        return character;
    }

    public static String operacionClaveDif(String stringClave){
        String cf = "";
        int resultado = 0;

        System.out.println("string clave = "+stringClave);

        for(int i = 0; i < stringClave.length() - 1; i++){
            resultado += (Character.getNumericValue(stringClave.charAt(i)) * 10 + Character.getNumericValue(stringClave.charAt(i+1)) ) * Character.getNumericValue(stringClave.charAt(i+1));
        }
        resultado = resultado % 1000;
        cf = cf.concat(numToCharClaveDif((int)(resultado / 34)));
        cf = cf.concat(numToCharClaveDif(resultado % 34));

        return cf;
    }

    public static String digVerRegFedContribuyentes(String rfc){
        String dig = "";
        int value = 0, valChar = 0;

        for(int i = 0; i < rfc.length() ; i++){
            valChar = (int) (rfc.charAt(i) - 55);
            if(valChar < 5) valChar += 7;
            value += valChar * (rfc.length() - i + 1);
        }
        System.out.println(value);
        value = value % 11;
        System.out.println(value);
        
        if(value > 0) value = 11 - value;
        if(value == 10) dig = "A";
        dig = Integer.toString(value);

        return dig;
    }
    public static void main(String[] args){
        Persona you = new Persona(GetInput.getLine("Introduce tu nombre"), GetInput.getLine("Introduce tu apellido paterno"), GetInput.getLine("Introduce tu apellido materno"), GetInput.getInt("Introduce tu año de nacimiento"), GetInput.getInt("Introduce tu mes de nacimiento (1-12)"), GetInput.getInt("Introduce tu dia de nacimiento"));
        System.out.println(you.getPersonaRFC());
    }
}