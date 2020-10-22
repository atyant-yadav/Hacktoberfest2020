import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class pro8 {

	private static int findFirstDuplicate(int[] array)  {
        int n = array.length;
        Map<Integer,Integer> map = new HashMap<>(); // Space complexity is O(n);
        for (int i = 0; i < n; i++) {  // Time complexity is O(n)
            if(!map.containsKey(array[i])){ // O(1)
                map.put(array[i],0); // O(n)
            }

            map.put(array[i] ,map.get(array[i]) + 1); // O(1)
        }

        for (int i = 0; i < n; i++) { // O(n) 
            if(map.get(array[i]) > 1){ //O(1)
                return i + 1;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }
        System.out.println(findFirstDuplicate(array));

    }
}