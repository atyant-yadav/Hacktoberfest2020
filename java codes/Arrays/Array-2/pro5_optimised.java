import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class pro5_optimised {
    
    public static void main(String[] args) {
        Set<Integer> set = new HashSet();
        Scanner scanner =  new Scanner(System.in);
        int size = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }
        set = findDuplicate(array);
        for (int i : set) {
            System.out.print(i + " ");
        }
    }

	private static Set<Integer> findDuplicate(int[] array) {
        Set<Integer> set = new HashSet<Integer>();  //O(n) space for result
        // 1 2 3 4 2 
        for (int i = 0; i < array.length; i++) { // O(n) time complexity
            int index = Math.abs(array[i]);
            if(index < array.length) {
                if(array[index] < 0) {
                   set.add(index);
                }
            }
            if(index < array.length){
                if(array[index] > 0){
                    array[index] = -array[index];
                }
            }
        }
        return set;
    }
}