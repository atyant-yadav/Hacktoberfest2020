import java.util.Scanner;

public class pro2 {
    public static void rotateArray(int[] array) {
        int temp = array[array.length - 1];
        for (int i = array.length - 2; i >= 0; i--) {
            array[i + 1] = array[i];
        }
        array[0] = temp;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }

        rotateArray(array);
        for (int i : array) {
            System.out.print(i + " ");
        }
    }
}