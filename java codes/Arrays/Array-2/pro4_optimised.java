import java.util.HashMap;
import java.util.Scanner;
public class pro4_optimised {
    public static int getPairCount(int[] array, int sum) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for (int i = 0; i < array.length; i++) {
            if(!map.containsKey(array[i]))
                map.put(array[i], 0);

            map.put(array[i], map.get(array[i]) + 1);
        }
        int twice_counter = 0;
        for (int i = 0; i < array.length; i++) {
            if(map.containsKey(sum - array[i])) {
                twice_counter += map.get(sum - array[i]);
            }

            if(sum - array[i] == array[i]){
                twice_counter--;
            }

        }
        return twice_counter/2;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int sum = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }
        System.out.println(getPairCount(array, sum));
    }
}