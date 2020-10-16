import java.util.Random;
import java.util.Scanner;

public class random {
   public static void main(String args[]){
       Random number = new Random();
       Scanner input = new Scanner(System.in);
       int min, max, num;
       System.out.println("Enter the minimum value: ");
       min = input.nextInt();
       System.out.println("Enter the maximum value: ");
       max = input.nextInt();
       num = min+number.nextInt(max);
       System.out.println(num + "  ");
       input.close();
   }
}
