import java.util.ArrayList;
import java.util.LinkedList;


class RadixSort {
    public static void main(String[] args) {
        int[] list = { 21, 43, 212, 6, 32, 54, 67, 98, 90, 12 };
        int max = getMax(list);
        int digits = (int) (Math.log10(max) + 1);
        radixSort(list, digits);
    }

    public static int getMax(int[] list) {
        int max = 0;
        for (int i = 0; i < list.length ; i++)
            if (list[i] > list[max])
                max = i;
        return max;
    }

    public static int getDigits(int number) {
        String n = Integer.toString(number);
        return n.length();
    }




    public static int[] radixSort(int[] list, int digits) {
        LinkedList<LinkedList<Integer>> llist = new LinkedList<LinkedList<Integer>>();
        LinkedList<Integer> orderedLlist = new LinkedList<Integer>();
        for (int i = 0; i < list.length; i++) {
            llist.add(new LinkedList<Integer>());
        }
        for (int i = 0; i < list.length; i++) {

        }


        return list;
    }
}