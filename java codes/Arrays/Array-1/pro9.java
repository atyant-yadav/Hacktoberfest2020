import java.util.Scanner;

public class pro9 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }
        int max = array[0];
        int min = array[0];
        for (int i = 0; i < size; i++) {
            if(array[i] > max) {
                max = array[i];
            } 
            if(array[i] < min) {
                min = array[i];
            }
        }

        System.out.println(max - min);
    }
}