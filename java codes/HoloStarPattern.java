// holo Triangle
//     *
//    * *
//   *   *
//  *     *
// * * * * *

class pattern3 {

    // holo triangle pattern
    public static void main(String arg[]) {
        for (int i = 1; i <= 5; i++) {
            for (int j = 5; j > i; j--) {
                System.out.print(" ");
            }
            for (int k = 1; k <= i; k++) {
                if (i == k || k == 1 || i == 5)
                    System.out.print("* ");
                else
                    System.out.print("  ");
            }
            System.out.println();
        }
    }
}
