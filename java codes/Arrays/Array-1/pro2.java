import java.util.Scanner;

public class pro2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        int sizeOfArray = scanner.nextInt();
        int[] array = new int[sizeOfArray];
        boolean result = false;
        for (int i = 0; i < sizeOfArray; i++) {
            array[i] = scanner.nextInt();
            if(array[i] == number) {
                result = true;
            }
        }
        System.out.println(result ? "TRUE" : "FALSE");
    }
}