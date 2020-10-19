import java.util.Scanner;

public class calculatorswitchcase {
    public static void main(String[] args)
    {
        System.out.println("Enter the 2 values");
        int a,b,result;
        Scanner sc =new Scanner(System.in);
        a=sc.nextInt();
        b=sc.nextInt();
        System.out.println("Enter the symbol");
        String symbol=sc.next();
        switch(symbol)
        {
            case "+":result=a+b;
            System.out.println(result);
                    break;
            case "-":result=a-b;
            System.out.println(result);
                    break;
            case "*":result=a*b;
            System.out.println(result);
                    break;
            case "/":result=a/b;
            System.out.println(result);
                    break;
            default:System.out.println("Invalid output");

        }


    }
}
