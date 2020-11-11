import java.util.*;

public class Manupulation{
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        long[] arr = new long[N+1];
        
        while(M-- >0){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int k = sc.nextInt();

            arr[a-1] += k;
            arr[b]   -= k;

        }
        sc.close();

        long sum = 0;
        long max = 0;
        long min=0;

        for(int i=0;i<N;i++){
            sum +=arr[i];
            max = Math.max(max,sum);
            min=Math.min(min,sum);
        }
        System.out.println(max);
        System.out.println(min);
    }
}
