import java.util.Scanner;

public class pro5 {


    public static void SelectionSort(int[] array) {
        int n = array.length;
        
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if(array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }

    }

public static void PrintArray(int[] array) {
    int size = array.length;
    for (int i = 0; i < size; i++) {
        System.out.print(array[i] + " ");
    }
    System.out.println();
}
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt(); 
        }
        SelectionSort(array);
        PrintArray(array);
        
    }
}