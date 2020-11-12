import java.util.Scanner;
public class Math {
    public static void main(String[] args) {
        int ans,input1,input2;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter two numbers ");
        input1 = scan.nextInt();
        input2 = scan.nextInt();
        ans = input1 + input2;
        System.out.println("Addition = "+ans);

        ans = input1 - input2;
        System.out.println("Subtraction = "+ans);

        ans = input1 * input2;
        System.out.println("Multiplication = "+ans);
        
        ans = input1/input2;
        System.out.println("Quotient = "+ans+" & Remainder = "+input1%input2);
        
        scan.close();
    }
}
