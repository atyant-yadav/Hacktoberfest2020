import java.util.Scanner;

public class PrimeTest {

    public boolean isPrime(int number) {
        boolean isPrime = false;
        int divider = 2;
        int divisbleByNumberOfNumbers = 0;

            while (divider < number) {
                if (number % divider == 0) {
                    checker += 1;
                }
                divider++;
            }
        return (checker == 0);
        //this cuts down on lines and makes it easiesr
    }

    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        PrimeTest primeTest = new PrimeTest();
        System.out.println("Type an integer:");
        final int number = scanner.nextInt();
        scanner.close();
        if (primeTest.isPrime(number)) {
            System.out.println("Number " + number + " is a prime number.");
        } else {
            System.out.println("Number " + number + " is not a prime number.");
        }
    }
}
