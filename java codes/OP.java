public class OP
{
  public static void main(String[] args)
  
   {
     int a = 5;
     int b = 7;
     int c = 9;

     System.out.println("a AND b = " + (a&b));
     System.out.println("a OR b =" + (a|b));
     System.out.println("a XOR b = " + (a^b));
     System.out.println("a NOT = " + ~a);
    
     //complex calculation to check precedence of operators
    
    int complex= ~(a|b) & (b|c);
    System.out.println("Output="+complex);
 }

}
