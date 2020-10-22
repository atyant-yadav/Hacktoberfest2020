import java.util.Scanner;

public class pro3 {
    public static void main(String[] args) {
        // n is the size 
        // list of n - 1 integers 
        // 1 to n 
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < array.length; i++) {
            array[i] = scanner.nextInt();
        }
        for (int i = 0; i < array.length; i++) { // O(n)
            if(array[i] < array.length -1) {
                int temp = array[array[i] - 1];
                array[array[i] - 1] = array[i];
                array[i] = temp;
            }
            
        }
    
        for (int i = 0; i < array.length; i++) { // O(n)
            if(array[i] != i + 1) {
                System.out.println(i + 1);
            }
        }
       

    }
}