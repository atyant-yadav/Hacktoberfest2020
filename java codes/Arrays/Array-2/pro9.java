import java.util.Scanner;

public class pro9 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();   
        }

        System.out.println(findFirstNonRepetingElement(array));
    }
    // total time complexity O(n^2) && Space complexity is O(1)
    private static int findFirstNonRepetingElement(int[] array) {
        int n = array.length;
        for (int i = 0; i < n - 1; i++) { //Time complexity for outer loop O(n)
            int j;
            for (j = 0; j < n; j++) {  //for inner loop  O(n)
                 if(array[i] == array[j] && i != j){
                     break;
                 }
            }
            if(j == n){
                return array[i];
            }
        }
        return 0;
    }
}