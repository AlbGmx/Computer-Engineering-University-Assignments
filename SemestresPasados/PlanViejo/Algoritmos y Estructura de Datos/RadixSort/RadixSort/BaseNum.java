package RadixSort;

import java.util.Arrays;

public class BaseNum   {

	// radix sort
	public static void radixSort(int[] arr) {
		if (arr == null || arr.length < 2) {
			return;
		}
		radixSort(arr, 0, arr.length - 1, maxbits(arr));
	}
		
	// Calculate the maximum number of digits
	public static int maxbits(int[] arr) {
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < arr.length; i++) {
			max = Math.max(max, arr[i]);
		}
		int res = 0;
		while (max != 0) {
			res++;
			max /= 10;
		}
		return res;
	}

	// radix sort
	public static void radixSort(int[] arr, int begin, int end, int digit) {
		final int radix = 10;
		int i = 0, j = 0;
		int[] count = new int[radix];
		int[] bucket = new int[end - begin + 1];
		// traverse each digit in turn
		for (int d = 1; d <= digit; d++) {
			for (i = 0; i < radix; i++) {
				count[i] = 0;
			}
				
			// total number
			for (i = begin; i <= end; i++) {
				j = getDigit(arr[i], d);
				count[j]++;
			}
				
			// calculate position
			for (i = 1; i < radix; i++) {
				count[i] = count[i] + count[i - 1];
			}
				
			// record to the corresponding location
			for (i = end; i >= begin; i--) {
				j = getDigit(arr[i], d);
				bucket[count[j] - 1] = arr[i];
				count[j]--;
			}
			for (i = begin, j = 0; i <= end; i++, j++) {
				arr[i] = bucket[j];
			}
		}
	}

	// Get the number of digits
	public static int getDigit(int x, int d) {
		return ((x / ((int) Math.pow(10, d - 1))) % 10);
	}

}