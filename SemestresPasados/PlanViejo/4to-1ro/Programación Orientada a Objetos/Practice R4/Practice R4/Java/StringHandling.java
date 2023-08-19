public class StringHandling{
    public static void countCharacters(String str){
        System.out.println("\nNumber of characters in \"" + str + "\": " + str.length());    
    } 
    public static void countThisCharacter(String temp, String str){
        char c = temp.charAt(0);        
        int count = 0;
        for(int i = 0; i < str.length(); i++){
            if ( str.charAt(i) == c){
                count++;
            }
        }
        System.out.println("\nNumber of times the character \"" + c + "\" ocurres in \"" + str + "\": " + count);
    }
    public static void countDifCharacters(String str){
        int[] difChar = new int [255];
        int numChar = 0;
        
        for(int i = 0; i < str.length(); i++){
            difChar[ (int) str.charAt(i)] = 1;
        }
        for(int i = 0; i < difChar.length; i++){
            numChar += difChar[i];
        }
        System.out.println("\nNumber of differrent characters in \"" + str + "\": " + numChar);
    }
    public static void countSubstringAppears(String str, String subStr) {
        int[] count = new int [str.length()];
        int numSubs = 0;
        for(int i = 0; i < str.length(); i++){
            if(str.indexOf(subStr,i)>=0){
            count[str.indexOf(subStr, i)] = 1;
            }
        }
        for(int i = 0; i < count.length; i++){
            numSubs += count[i];
        }
        System.out.println("\nNumber of times the subString \"" + subStr + "\" ocurres in \"" + str + "\": " + numSubs);
    }
}