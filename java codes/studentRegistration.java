import java.util.Scanner;

public class studentRegistration {

        public static void main(String[] args) {

            //add scanner. This is telling java you want a new instance of scanner.
            Scanner sc = new Scanner(System.in);

            //establish variables
            String fName = "";
            String lName = "";
            int birthYear = 0;

            // Welcome to Student Registration
            System.out.println("Student Registration Form");
            System.out.println();

            //Write out entered fields
            System.out.print("Enter First Name: ");
            fName = sc.nextLine();

            System.out.print("Enter Last Name: ");
            lName = sc.nextLine();

            System.out.print("Enter year of birth: ");
            birthYear = sc.nextInt();
            System.out.println();

            //Write out auto populated message
            System.out.println("Welcome" + " " + fName + " " + lName);
            System.out.println("Your Registration is complete.");
            System.out.println("Your temporary password is: " + fName + "*" + birthYear);

            sc.close();
        }
}
