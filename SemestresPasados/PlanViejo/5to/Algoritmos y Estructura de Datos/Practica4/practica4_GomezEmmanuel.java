import java.text.DecimalFormat;
import java.util.Scanner;
/*
    Algoritmos y Estructura de Datos
    Práctica 4. Análisis de Algoritmos Empirico y Recursion
    Alumno: Gómez Cárdenas Emmanuel Alberto
    Docente: M.I Palacios Guerreros Alma Leticia
    Fecha de Entrega: 19 de octubre a las 13:00

    Implementar el algoritmo de busqueda binaria recursiva e iterativamente
    La búsqueda binaria es un algoritmo que encuentra la posición de un valor
    en un array ordenado. Este compara el valor con el elemento en el medio 
    del array, si no son iguales, la mitad en la cual el valor no puede estar 
    es eliminada y la búsqueda continúa en la mitad restante hasta que el valor
    se encuentre.


*/
public class practica4_GomezEmmanuel{
    public static void main(String args[]){
        binarySearchMain();
    }

    public static void binarySearchMain(){
        Scanner input = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#.##########s");
        String[] words = {
        //Las palabras fueron generadas aleatoriamente
        //200words        
            "abridgeable","acclimatise","albumenised","alembic","allegedly","aneurismal","anguish","antihalation","armillae","attired","autarchically","bahilist","baloney","becloud","bethany","billable","bombay","brahmaputra","breadnut","brewer","brucite","bulky","bullbat","bunco","calvina","cantala","capote","catechise","cephalothoraces","ceraceous","chaldaea","chapter","checksum","chordophone","choriomas","chowchilla","cisel","clingingness","consideration","costarring","costotome","counteractively","counterdeclaration","courtelle","cripplingly","curch","cyaneous","declamation","derbent","descalate","desirableness","desire","dhamma","discomfortable","doughiness","duka","eisteddfod","enrobed","ensphere","estaing","eucalyptic","eupneic","excavator","excretal","experiencing","eyespot","faade","festive","firman","francis","freeloader","gabo","glandule","gluer","groundwards","grummet","guiltier","hamperedly","hierarchical","hunchback","hypercarbia","illegitimation","immigrate","interchanging","interveinous","josiah","knickered","kudos","labdanum","laborless","languorously","lauwine","logroller","lunatical","lusatian","lyse","madag","malayan","mammonite","memphis","metioche","micronesian","midnight","milyukov","mirepois","mlaga","monotrichous","naperian","niersteiner","nondismemberment","nonextrinsic","nontan","obstructionistic","oping","organza","ostentatiousness","overnursed","paleozoic","paracystitis","patinated","peccantly","peeper","pelican","pentahydrate","pepperer","petto","precopying","prediscontented","premeditator","prophylactic","prussianizing","quiescently","racemization","rapidity","rater","reassignment","rebuke","reckon","reenlighten","refundment","remonstrant","rendering","repopularized","roscoe","rounce","sastruga","schizopod","scratchlike","seafighter","semidomestication","serialized","serrate","shrubby","singer","skinneries","somite","sorbic","sosnowiec","stealth","stoppably","strawworm","strongness","subtemperate","supererogating","superficies","suppository","tasteful","tenebrous","theophrastian","thermoelectricity","thurgau","thymi","titicaca","toluene","transitoriness","transnatural","tubifex","unadoring","unallured","unbombastic","uncheering","understandingness","undisparaged","unfilamentous","uniseptate","unmasticatory","unpaginated","unparching","unpardoning","unpicked","unscoring","unsecularised","upsetting","uranian","urticant","vanisher","vugg","wanderoos","wethersfield","zoophilous"
        //100words(size 3)
//      "ard","bag","big","bob","bre","bwg","cab","cad","cay","cbd","des","did","dom","dom","dot","dsc","emu","ene","ens","ezr","fad","fer","fez","fla","foh","gaz","gig","gin","gtc","hal","heh","him","hit","ife","ima","inc","jab","jat","jcd","jeh","jnd","lie","loo","ltd","mad","map","mar","mia","mos","mot","mst","nag","nev","nil","nos","num","oba","odd","oho","one","opp","otc","pav","plu","pos","pru","pte","pun","rab","raf","ray","ray","rco","rhg","sat","sax","sch","sci","scr","sen","shy","son","spt","sue","taj","tee","tef","tor","tow","tug","two","uru","ute","vat","wae","wye","yea","yew","yod","zee"
        //100words(size>20)
//       "aerobacteriologically","anatomicopathological","anticonstitutionalism","anticonstitutionalist","antidisestablishmentarianism","antimaterialistically","antinationalistically","antisupernaturalistic","ballistocardiographic","bioelectrogenetically","chlorotrifluoroethylene","chlorotrifluoromethane","chlorprophenpyridamine","counterrevolutionaries","cyclotrimethylenetrinitramine","demethylchlortetracycline","dendrochronologically","deoxyribonucleoprotein","desoxyribonucleoprotein","diaminopropyltetramethylenediamine","dichlorodifluoromethane","dichlorodifluoromethane","dichlorodiphenyltrichloroethane","dichlorodiphenyltrichloroethane","dicyclopentadienyliron","diphenylaminechlorarsine","disestablishmentarian","disestablishmentarianism","disproportionableness","electrocardiographically","electrodiagnostically","electroencephalograph","electroencephalographic","electroencephalographically","electroencephalography","electromyographically","electrophysiologically","establishmentarianism","hdmezov","hexachlorocyclohexane","hexahydroxycyclohexane","hexamethylenetetramine","humuhumunukunukuapuaa","hydrodesulphurization","hyperconstitutionalism","hyperenthusiastically","hyperpolysyllabically","indistinguishableness","intellectualistically","interdenominationalism","intertransformability","isopropylideneacetone","magnetohydrodynamically","magnetothermoelectricity","methyltrinitrobenzene","microspectrophotometric","microspectrophotometry","misapprehensiveranged","misapprehensiveranging","nitrotrichloromethane","noncharacteristically","nondistinguishableness","noninterchangeability","noninterchangeableness","overcommercialization","overimpressionability","overimpressionableness","overindividualistically","overindividualization","overindustrialization","overintellectualization","overintellectualizing","parathyroidectomizing","pentamethylenediamine","phenylethylmalonylurea","poliencephalomyelitis","pseudoanachronistical","pseudoanthropological","pseudoenthusiastically","pseudohermaphroditism","pseudointernationalistic","pseudophilanthropical","psychophysiologically","psychotherapeutically","representationalistic","spectrophotometrically","succinylsulfathiazole","succinylsulphathiazole","supercalifragilisticexpialidocious","superincomprehensible","superincomprehensibleness","temperameperamentally","thermophosphorescence","transubstantiationalist","triacetyloleandomycin","trichloroacetaldehyde","trichloronitromethane","trifluorochloromethane","trinitrophenylmethylnitramine","ultranationalistically",

    };
        String key = "abridgeable";
        int pos;
        long begin, end;

        System.out.println("\nUtilizar recursividad(1) o iteratividad(0)? : ");
        if(input.nextInt() == 1){
            begin = System.nanoTime();
            pos = recursiveBinarySearch(key, words, 0, words.length);
            end = System.nanoTime(); 
        }else{
            begin = System.nanoTime();
            pos = iterativeBinarySearch(key, words, 0, words.length);
            end = System.nanoTime(); 
        }

        double executionTime = (end - begin) / 1000000000.0; 
        System.out.println("La llave se encuentra en la posicion: " + pos);
        String seconds = df.format(executionTime);
        System.out.println("Tiempo de Ejecucion: " + seconds + "\n");
        input.close();
    }

    public static int iterativeBinarySearch(String key, String[] words, int left, int right){
        int center = (left+right)/2;
        while (words[center].compareToIgnoreCase(key)!=0){
            if(left == right) return -1;
            else{
                if(words[center].compareToIgnoreCase(key) > 0) right = center -1;
                else left = center + 1;  
            }
            center = (left+right)/2;
        }
        return center;
    }

    public static int recursiveBinarySearch(String key, String[] words, int left, int right) {
        int center  = (left+right)/2;
        if(words[center].compareToIgnoreCase(key) == 0){
            return center;  //Caso base
        }
        else if(left == right) return -1;
        else{
            if(words[center].compareToIgnoreCase(key) > 0) right = center -1;
            else left = center + 1;
        }
        return recursiveBinarySearch(key, words, left, right);
    }
}