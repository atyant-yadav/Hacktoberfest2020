package exceptionHandling;

import java.util.Scanner;

public class uncheckedException {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in= new Scanner(System.in);
		int[] originalArray= {2,4,5,22,65,43};
		System.out.println("Enter the target index number for which you want the element:");
		int target=in.nextInt();
		System.out.println("enter the divisor:");
		int num1=in.nextInt();
		System.out.println("Enter the dividend:");
		int num2=in.nextInt();
		solution(target,num1,num2,originalArray);
		in.close();

	}
	static void solution(int x,int y, int z,int[] arr) {
		try {
			System.out.println("The element at index "+ x + " is "+ arr[x] );
		}
		catch(IndexOutOfBoundsException e) {
			System.out.println(e);
			System.out.println("The division program follows:");
		}
		try {
			int div=y/z;
			System.out.println("the answer for division  operation is: "+div);
		}
		catch(ArithmeticException exc){
			System.out.println(exc);
			System.out.println("THE END");
		}
		System.out.println("The above operations helps us understand two types of unchecked exception and its handling using try catch method");
	}

}
