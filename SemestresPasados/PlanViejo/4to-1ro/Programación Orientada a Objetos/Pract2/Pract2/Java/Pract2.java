import java.util.*;

public class Pract2{
    public static void main(String args[]){
        String opc = "";
		boolean flag = true;
		int i,j;
        String name = "";
        String lastName = "";
        int gradesCount = 0;
        int subjectCount = 0;
        Scanner sc = new Scanner(System.in);
        List<Integer> grades = new ArrayList<Integer>();      
        List<String> subject = new ArrayList<String>();

        while (flag){
			Menu.printIt();
			opc = sc.nextLine();

			switch(opc){
				case "1": name = GetInput.getLine("su(s) nombre(s)");
						lastName = GetInput.getLine("su(s) apellido(s)");
						Print.printStr("Datos Capturados...\n");
				break;
				case "2": name = GetInput.getLine("solo su nombre");
						Print.printStr("Datos Capturados...\n");
				break;
				case "3": lastName = GetInput.getLine("solo su apellido");
						Print.printStr("Datos Capturados...\n");
				break;
				case "4": subject.add(GetInput.getLine("el nombre de la materia"));
						subjectCount++;
				break;
				case "5": if(subjectCount != 0){
							gradesCount = 0;
							grades.clear();
							for(i = 0; i<subjectCount; i++){
								for(j = 0; j<4; j++){
									grades.add(GetInput.getInt("calificacion #" + (j+1) + " de " + subject.get(i) ) );
									gradesCount++;	
								}
								Print.printStr("\n");
							}
						}
						else{
							Print.printStr("Por favor, primero introduzca una materia\n\n");
						}
				break;
				case "6": if((subjectCount != 0) & (gradesCount != 0) ){
							Print.printStr("Calificaciones de las materias del alumno " + name + " " + lastName + "\n" );
							for(i=0; i<subjectCount; i++){
								Print.printStr("\n\t" + subject.get(i) + ": \n");							
								for(j=0; j<4; j++){
									Print.printStr("\t");
									Print.printInt(grades.get((i*4) + j));
								}
								Print.printStr("\n");
							}
						}
						else{
							Print.printStr("Por favor, primero introduzca sus calificaciones\n\n");
						}	
				break;
				case "7": if((subjectCount != 0) & (gradesCount != 0) ){
								Print.printStr("Calificacion final promediada:\n");
								Print.printFloat(GradeOperations.avgGrades(grades, gradesCount));
							}
							else{
								Print.printStr("Por favor, primero introduzca sus calificaciones\n\n");
							}
				break;
				case "0": flag = false;
				break;
				default:	Print.printStr("Por favor, seleccione una de las opciones sugeridas...\n\n");
				break;
			}
		}
    }
}