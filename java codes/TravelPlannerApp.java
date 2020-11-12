import java.util.Scanner;
/*
Travel Planner app calculates budget, time difference between home and destination
and distance between home and destination using user input in the console
 */

public class TravelPlannerApp {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        greetUser();
        calculateBudget();
        calculateTime();
        convertArea();
        calculateDistance();
    }

    //greets user
    private static void greetUser() {
        System.out.println("Welcome to Travel Planner!");
        System.out.print("What is your name? ");
        String name = sc.nextLine();
        System.out.print("Nice to meet you " + name + ", where are you travelling to? ");
        String destination = sc.nextLine();
        System.out.println("Excellent! " + destination + " sounds like a good trip.");
        endMethod();
    }

    //calculates travel budget using user input
    private static void calculateBudget() {
        System.out.print("How many days are you going to spend travelling? ");
        int tripDays = sc.nextInt();
        System.out.print("How much money, in EUR, are you planning to spend on your trip? ");
        double moneyToSpend = sc.nextDouble();
        System.out.print("What is the three letter currency symbol for your travel destination? ");
        String currencySymbol = sc.next();
        System.out.print("How many " + currencySymbol + " are there in 1 EUR? ");
        double currencyRate = sc.nextDouble();
        System.out.println();

        System.out.println("If you are travelling for " + tripDays + " days that is the same as " + (tripDays * 24) + " hours or " + (tripDays * 1440) + " minutes.");
        System.out.printf("If you are going to spend EUR " + moneyToSpend + " that means per day you can spend up to EUR %.2f.\n", (moneyToSpend / tripDays));
        System.out.printf("Your total budget in " + currencySymbol + " is " + (moneyToSpend * currencyRate) + ", which per day is EUR %.2f.\n", (moneyToSpend * currencyRate / tripDays));
        endMethod();
    }

    //calculates time in destination when it is midnight and noon at home
    private static void calculateTime() {
        System.out.print("What is the time difference, in hours, between your home and your destination? ");
        int timeDifference = sc.nextInt();
        int midnightDiff = (24 + timeDifference) % 24;
        int middayDiff = (12 + timeDifference) % 24;
        System.out.println("That means that when it is midnight at home it will be " +midnightDiff + ":00 in your travel destination and when it is noon at home it will be " + middayDiff + ":00.");
        endMethod();
    }

    //converts area for destination country from km^2 to miles^2
    private static void convertArea() {
        System.out.print("What is the square area of your destination country in km2? ");
        double areaKm = sc.nextDouble();
        double areaMiles = areaKm * 0.386;
        System.out.printf("In miles2 that is %.2f.\n", areaMiles);
        endMethod();
    }

    //calculates distance between home and destination using Haversine formula
    private static void calculateDistance() {
        System.out.print("What is latitude for your home? ");
        double lat1 = sc.nextDouble();
        System.out.print("What is longitude for your home? ");
        double lon1 = sc.nextDouble();

        System.out.print("What is latitude for your destination? ");
        double lat2 = sc.nextDouble();
        System.out.print("What is longitude for your destination? ");
        double lon2 = sc.nextDouble();

        //Haversine formula implementation
        final double R = 6372.8; // in km
        double dLat = Math.toRadians(lat2 - lat1);
        double dLon = Math.toRadians(lon2 - lon1);
        lat1 = Math.toRadians(lat1);
        lat2 = Math.toRadians(lat2);
        double a = Math.pow(Math.sin(dLat / 2),2) + Math.pow(Math.sin(dLon / 2),2) * Math.cos(lat1) * Math.cos(lat2);
        double c = 2 * Math.asin(Math.sqrt(a));
        double distance = c * R;

        System.out.printf("Distance from your home to your destination is %.2f km.\n", distance);
        endMethod();
    }

    //line of symbols to separate method from next one
    private static void endMethod() {
        System.out.println("---***---\n");
    }
}
