import java.util.Scanner;
import java.lang.Math;;

public class GCD {

  public static int findGCD(int n1, int n2) {
    int gcd = 0;
    int small = Math.min(n1, n2);
    for (int i = 2; i <= small; i++)
      if (n1 % i == 0 && n2 % i == 0)
        gcd = i;
    return gcd;
  }

  public static int findGCDFast(int n1, int n2) {
    // int rem = n1 % n2;
    // if(rem == 0)
    //   return n2;
    // else
    //   return findGCDFast(n2, rem);

    return (n1 % n2 == 0) ? n2 : findGCDFast(n2, (n1 % n2));
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the 1st number: ");
    int num1 = sc.nextInt();
    System.out.print("Enter the 2nd number: ");
    int num2 = sc.nextInt();
    System.out.println(findGCDFast(num1, num2));
    System.out.println(findGCD(num1, num2));
  }
}