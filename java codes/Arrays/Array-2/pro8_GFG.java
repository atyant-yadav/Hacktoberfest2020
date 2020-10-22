import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class pro8_GFG {

	private static int findFirstDuplicate(int[] array)  {
        int n = array.length;
        Set<Integer> set = new HashSet<>();
        int min = -1;
        for (int i = n - 1; i >= 0 ; i--) {
            if(set.contains(array[i])) {
                min = i + 1;
            }
            set.add(array[i]);
        }
        return min;
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