import java.math.BigInteger;
import java.util.Scanner;

public class FactorialOfVeryBigInteger {
    public static BigInteger factorial(int N){
        BigInteger big = BigInteger.ONE;
        for (int i = 2; i <= N; i++){
            big = big.multiply(BigInteger.valueOf(i));
        }
        return big;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tc = scanner.nextInt();
        while(tc>0){
            int N = scanner.nextInt();
            System.out.println(factorial(N));
            tc--;
        }
    }
}
