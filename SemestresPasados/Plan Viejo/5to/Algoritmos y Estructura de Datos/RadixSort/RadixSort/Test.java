package RadixSort;

import java.util.Arrays;
public class Test {
	//test
	public static void main(String[] args) {
		// TODO automatically generated method stub
          int[] a= {9,1,2,5,7,4,8,6,3,5};
          System.out.println(Arrays.toString(a));
          BaseNum.radixSort(a);
          System.out.println(Arrays.toString(a));
         //[9, 1, 2, 5, 7, 4, 8, 6, 3, 5]
         //[1, 2, 3, 4, 5, 5, 6, 7, 8, 9]
	}
}
