import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * Performs the four operations (addition, subtraction, division or multiplication) for whole numbers.
 * 
 * @author Jackson Roberio (https://jacksonroberio.com.br)
 **/
public class Calculator {

	private static int number1;
	
	private static int number2;
	
	private static int operation;
	
	private static Scanner scan = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		System.out.println("Which operation do you want?");
		System.out.println("Enter number 1 (one) for sum");
		System.out.println("Enter number 2 (two) for subtraction");
		System.out.println("Enter number 3 (three) for multiplication");
		System.out.println("Enter number 4 (four) division");
		operation = scan.nextInt();
		
		try {
			System.out.println("Enter first number:");
			number1 = scan.nextInt();
			System.out.println("Enter second number:");
			number2 = scan.nextInt();
			System.out.println("It is result:");
			System.out.println(result(number1, number2, operation));
		} catch (InputMismatchException | ArithmeticException e) {
			System.out.println("Invalid Number!");
		}
	}
	
	private static int result(int number1, int number2, int operation) {
		if (operation == 1)
			return number1 + number2;
		else if (operation == 2)
			return number1 - number2;
		else if (operation == 3)
			return number1 * number2;
		else if (operation == 4)
			return number1 / number2; 
		else
			return 0;
	}
	
}
