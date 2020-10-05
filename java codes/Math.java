import java.util.Scanner;
public class Math {
    public static void main(String[] args) {
        int ans,n1,n2;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter two numbers ");
        n1 = scan.nextInt();
        n2 = scan.nextInt();
        ans = n1 + n2;
        System.out.println("Addition = "+ans);

        ans = n1 - n2;
        System.out.println("Subtraction = "+ans);

        ans = n1 * n2;
        System.out.println("Multiplication = "+ans);
        
        ans = n1/n2;
        System.out.println("Quotient = "+ans+" & Remainder = "+n1%n2);
        
        scan.close();
    }
}
