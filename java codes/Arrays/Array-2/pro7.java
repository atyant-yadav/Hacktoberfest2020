import java.util.Scanner;

class pro7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n1 = scanner.nextInt();
        int n2 = scanner.nextInt();
        int n3 = scanner.nextInt();
        int[] array1 = new int[n1];
        int[] array2 = new int[n2];
        int[] array3 = new int[n3];

        for (int i = 0; i < n1; i++) {
            array1[i] = scanner.nextInt();
        }
        for (int i = 0; i < n2; i++) {
            array2[i] = scanner.nextInt();
        }
        for (int i = 0; i < n3; i++) {
            array3[i] = scanner.nextInt();
        }
        
        findUnion(array1, array2, array3);
        

    }

    private static void findUnion(int[] array1, int[] array2, int[] array3) {
        int i = 0;
        int j = 0;
        int k = 0;       
        while(i < array1.length && j < array2.length && k < array3.length){
            if(array1[i] == array2[j] && array1[i] == array3[k]) {
                System.out.print(array1[i] + " ");
                i++;
                j++;
                k++;
            } else if(array1[i] < array2[j]) {
                i++;
            } else if(array2[j] < array3[k]) {
                j++;
            } else {
                k++;
            }
            
    
            
        }
    }
}


