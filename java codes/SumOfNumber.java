import java.util.*;

class SumOfNumber
{
  public static void main(String args[])
  {
    int num,rem,sum=0;
    System.out.println("Enter a number:");

    // Input provided will be stored in sc    
    Scanner sc = new Scanner(System.in);
    num = sc.nextInt();

    while(num>0)
    {
	      rem=num%10;
        sum=sum+rem;
        num=num/10;
    }

    //displaying the output
    System.out.println("Sum of number is "+sum);
}
}
