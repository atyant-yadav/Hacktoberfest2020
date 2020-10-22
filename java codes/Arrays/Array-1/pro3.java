import java.util.Scanner;

public class pro3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int[] array = new int[size];
        int max, min;
        max = min = scanner.nextInt();
    
        for (int i = 1; i < size; i++) {
                array[i] = scanner.nextInt();
                if(array[i] > max){
                    max = array[i];
                } else if(array[i] < min){
                    min = array[i];
                }
        }
        System.out.println("MAX: " + max);
        System.out.println("MIN: " + min);
    }
}