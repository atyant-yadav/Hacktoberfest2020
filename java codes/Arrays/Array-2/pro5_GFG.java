import java.util.Scanner;

public class pro5_GFG {

    // This will work only for input from 0 to n-1 where n is size of array
    public static void findDuplicate(int[] array) {
        for (int i = 0; i < array.length; i++) {
            int index = array[i] % array.length;
            array[index] += array.length; 
        }
        for (int i = 0; i < array.length; i++) {
            if(array[i]/array.length > 1) {
                System.out.print(i);
            }
        }
    }
    public static void main(String[] args) {
        Scanner scanner =  new Scanner(System.in);
        int size = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }
        findDuplicate(array);
    }
}