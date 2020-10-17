/* Example of Fibonacci calcualtion using recursion function.
Prints out sequence of first 10 Fibonacci numbers */

public class FibonacciRecursion{
	public static int fibonacciRecursion(int n){
	  if(n == 0){
		  return 0;
	  }
    
	  if(n == 1 || n == 2){
			return 1;
		}
    
	  return fibonacciRecursion(n-2) + fibonacciRecursion(n-1);
	}
  
  public static void main(String args[]) {
	  int sequence = 10;
	  System.out.print("Fibonacci sequence of " + sequence + " numbers: ");
	  for(int i = 0; i < sequence; i++){
			System.out.print(fibonacciRecursion(i) +" ");
		}
	}
}
