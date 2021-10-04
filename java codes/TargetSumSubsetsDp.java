
/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number "tar".
4. You are required to calculate and print true or false, if there is a subset the elements of which add 
up to "tar" or not.

sample input : length of  array 5
 {
    4, 2, 7, 1, 3
 }
target : 10

output : true
*/
import java.util.Scanner;

public class TargetSumSubsetsDp {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }
        int tar = scn.nextInt();
        boolean res = TargetSumSubsets(arr, tar);
        System.out.println(res);
    }

    public static boolean TargetSumSubsets(int arr[], int tar) {
        boolean table[][] = new boolean[arr.length + 1][tar + 1];
        for (int row = 0; row < table.length; row++) {
            for (int col = 0; col < table[0].length; col++) {
                if (row == 0 && col == 0) {
                    table[row][col] = true;
                } else if (row == 0) {
                    table[row][col] = false;
                } else if (col == 0) {
                    table[row][col] = true;
                } else {
                    if (table[row - 1][col] == true) {
                        table[row][col] = true;
                    } else {
                        if (col >= arr[row - 1]) {
                            if (table[row - 1][col - arr[row - 1]] == true) {
                                table[row][col] = true;
                            }
                        }
                    }
                }
            }
        }

        return table[table.length - 1][table[0].length - 1];
    }
}
