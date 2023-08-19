import java.util.*;
public class GradeOperations{
	public static float avgGrades(List<Integer> grades, int gradesCount){
		int counter = 0;
        float avg = 0;
		for(int i = 0; i < gradesCount; i++){
			avg+= (float)grades.get( i );
            counter++;
		}
        return (float)(avg/counter);
	}
}