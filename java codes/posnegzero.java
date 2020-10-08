/*Program to check POSITIVE, NEGATIVE or ZERO*/

import java.util.Scanner;
public class POSNEGZERO
{
    public static void main(String args[])
    {
     System.out.println("Enter Number: ");
     ABC F=new ABC();
     F.display();
   }
} 
class ABC
{
   Scanner A = new Scanner(System.in);
   int N=A.nextInt();
   public void display()
    {
   if(N>0)
   {
       System.out.println("Positive");
   }
   else if(N<0)
   {
   System.out.println("Negative");
   }
   else
   {
   System.out.println("Zero");
   }
    }
}
