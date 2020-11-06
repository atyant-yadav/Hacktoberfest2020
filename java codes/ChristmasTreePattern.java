// Christmas Tree Program
//       *
//      * *
//     * * *
//   * * * * *
//      |||
//      |||
//      |||
// Marry Christmas

class marrychristmas{
    public static void main(String a[]){
        
        for(int i=1;i<=5;i++){
            for(int j=1;j<=6;j++){
                if(j>=6-i&&j<=5){
                    System.out.print("* ");
                }
                else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
        for(int i=1;i<=3;i++){
            for(int j=1;j<=12;j++){
                if(j>=4&&j<=6)
                System.out.print("|");
                else
                System.out.print(" ");
            }
            System.out.println();
        }
        System.out.println("Marry Christmas");

    }
}
