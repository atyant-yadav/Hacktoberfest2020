import java.util.Scanner;

public class pro10 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int[] array = new int[size];

        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        
        }
        int high = size - 1;
        int low = 0;
        int temp = 0;
        while(low <= high) {
            if(array[low] < 0) {
                low++;
            } else if(array[low] >= 0) {
                temp = array[high];
                array[high] = array[low];
                array[low] = temp;
                high--;

            }
        }
        for (int i : array) {
            System.out.print(i + " ");

        }
        
    }
}