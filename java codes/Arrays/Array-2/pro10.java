import java.util.Scanner;


public class pro10 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();   
        }

        threeMaxValue(array);
    }

    private static void threeMaxValue(int[] array) {
        int n = array.length;
        int n1 = array[0];
        int n2 = array[0];
        int n3 = array[0];
        for (int i = 0; i < n; i++) { //Time Complexity O(n)
            if(array[i] > n1){
                n3 = n2;
                n2 = n1;
                n1 = array[i];
            } else if(array[i] > n2) {
                n2 = array[i];
            } else if(array[i] > n3) {
                n3 = array[i];
            }
        }
        System.out.println(n1 + ", " + n2 + ", " + n3);
    }
}