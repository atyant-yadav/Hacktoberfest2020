import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class pro9_optimised {
    public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            int size = scanner.nextInt();
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = scanner.nextInt();   
            }
    
            System.out.println(findFirstNonRepetingElement(array));
        }

        // Time complexity O(n) && Space complexity O(n)
	private static int findFirstNonRepetingElement(int[] array) {
        Map<Integer,Integer> map = new HashMap<>(); // Space complexity O(n)
        for (int i = 0; i < array.length; i++) { // Time complexity O(n)
            if(!map.containsKey(array[i])) {
                map.put(array[i], 0);
            }

            map.put(array[i], map.get(array[i]) + 1);
        }

        for (int i = 0; i < array.length; i++) { // Time complexity O(n)
            if(map.get(array[i]) == 1){
                return array[i];
            }
        }
		return 0;
    }
}