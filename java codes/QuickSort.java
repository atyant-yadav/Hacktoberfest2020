import java.util.Scanner;

public class QuickSort {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");

        int length = sc.nextInt();
        int[] intArray = new int[length];

        System.out.print("Enter the array elements: ");

        for (int i = 0; i < intArray.length; i++) {
            intArray[i] = sc.nextInt();
        }

        quickSort(intArray, 0, intArray.length);

        System.out.print("Sorted array: ");
        for (int i = 0; i < intArray.length; i++) {
            System.out.print(intArray[i] + " ");
        }
    }

    public static void quickSort(int[] input, int start, int end) {

        if(end - start < 2) {
            return;
        }

        int pivotIndex = partition(input, start, end);
        quickSort(input, start, pivotIndex);
        quickSort(input, pivotIndex + 1, end);
    }

    public static int partition(int[] input, int start, int end) {
        
        // This is using the first element as the pivot
        int pivot = input[start];
        int i = start;
        int j = end;

        while (i < j) {

            while (i < j && input[--j] >= pivot);
            if(i < j) {
                input[i] = input[j];
            }

            while (i < j && input[++i] <= pivot);
            if(i < j) {
                input[j] = input[i];
            }
        }

        input[j] = pivot;
        return j;

    }
}