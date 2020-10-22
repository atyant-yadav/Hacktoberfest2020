import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class pro9_Adv {
    public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            int size = scanner.nextInt();
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = scanner.nextInt();   
            }
    
            findFirstNonRepetingElement(array);
        }

        // Time complexity O(n) && Space complexity O(n)
	private static void findFirstNonRepetingElement(int[] array) {
        Map<Integer,Integer> map = new HashMap<>(); // Space complexity O(n)
        for (int i = 0; i < array.length; i++) { // Time complexity O(n)
            if(!map.containsKey(array[i])) {
                map.put(array[i], 0);
            }

            map.put(array[i], map.get(array[i]) + 1);
        }
        // Print all non-repeting elements
        for (var i : map.entrySet()) {
            if(i.getValue() == 1) {
                System.out.print(i.getKey() + " ");
            }
        }
		
    }
}