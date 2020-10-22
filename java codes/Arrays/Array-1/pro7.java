import java.util.Scanner;
public class pro7 {
    public static void main(String[] args) {
        java.util.Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int size = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }
        int count = 0;
        for (int i = 0; i < size; i++) {
            if(array[i] == num) {
                count++;
            }
        }
        System.out.println(count);
    }
}