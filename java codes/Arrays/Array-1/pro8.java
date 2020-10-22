import java.util.Scanner;

public class pro8 {

    public static void sortWithOutAlgo(int[] array) {
        int n = array.length;
        int low = 0;
        int mid = 0;
        int high = n - 1;
        int temp = 0;

        while(mid <= high) {
            switch(array[mid]) {
                case 0 :
                    temp = array[low];
                    array[low] = array[mid];
                    array[mid] = temp;
                    mid++;
                    low++;
                    break;
                case 1 :
                    mid++;
                    break;
                case 2 : 
                    temp = array[high];
                    array[high] = array[mid];
                    array[mid] = temp;
                    mid++;
                    high--;
                    break;
            }
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }
        sortWithOutAlgo(array);

        for (int i : array) {
            System.out.print(i + " ");
        }
    }
}