import java.util.Scanner;

public class NineTimesQuiz {

        public static void main(String[] args) {
            execute9multQuiz();
        }

        private static void execute9multQuiz(){

            int count=0;
            Scanner scanner = new Scanner(System.in);

            System.out.println("Welcome to the 9's Multiplication Quiz!");
            System.out.println("What is 9 x 1 ? : ");
            //get answer
            int answer = scanner.nextInt();
            //check answer and count if correct
            if (answer == 9) {
                System.out.println("Correct!");
                count++;
            } else{
                System.out.println("I'm sorry the answer was 9");
            }
            System.out.println("What is 9 x 2 ? : ");
            int answer2 = scanner.nextInt();
            if (answer2 == 18) {
                System.out.println("Correct!");
                count++;
            } else{
                System.out.println("I'm sorry the answer was 18");
            }
            System.out.println("What is 9 x 3 ? : ");
            int answer3 = scanner.nextInt();
            if (answer3 == 27) {
                System.out.println("Correct!");
                count++;
            } else{
                System.out.println("I'm sorry the answer was 27");
            }
            System.out.println("What is 9 x 4 ? : ");
            int answer4 = scanner.nextInt();
            if (answer4 == 36) {
                System.out.println("Correct!");
                count++;
            } else{
                System.out.println(""); System.out.println("I'm sorry the answer was 36");
            }

            System.out.println("What is 9 x 5 ? : ");
            int answer5 = scanner.nextInt();
            if (answer5 == 45) {
                System.out.println("Correct!");
                count++;
            } else{
                System.out.println("I'm sorry the answer was 45");
            }

            System.out.println("What is 9 x 6 ? : ");
            int answer6 = scanner.nextInt();
            if (answer6 == 54) {
                System.out.println("Correct!");
                count++;
            } else{
                System.out.println("I'm sorry the answer was 54");
            }

            System.out.println("What is 9 x 7 ? : ");
            int answer7 = scanner.nextInt();
            if (answer7 == 63) {
                System.out.println("Correct!");
                count++;
            } else{
                System.out.println("I'm sorry the answer was 63");
            }

            System.out.println("What is 9 x 8 ? : ");
            int answer8 = scanner.nextInt();
            if (answer8 == 72) {
                System.out.println("Correct!");
                count++;
            } else{
                System.out.println("I'm sorry the answer was 72");
            }

            System.out.println("What is 9 x 9 ? : ");
            int answer9 = scanner.nextInt();
            if (answer9 == 81) {
                System.out.println("Correct!");
                count++;
            } else{
                System.out.println("I'm sorry the answer was 81");
            }

            System.out.println("What is 9 x 10 ? : ");
            int answer10 = scanner.nextInt();
            if (answer10 == 90) {
                System.out.println("Correct!");
                count++;
            } else{
                System.out.println("I'm sorry the answer was 90");
            }
            System.out.println("You got "+ count +" out of 10 correct.");
            System.out.println("Thanks for playing!");
            scanner.close();
        }
    }
