import java.util.*;

public class reverse
{
    static void reverseNum(int inputNum) //to get reverse of number
    {
        int resultNum = 0;
        int rem = 0;

        while(inputNum>0)
        {
            rem = inputNum%10;
            resultNum = resultNum*10+rem;
            inputNum = inputNum/10;
        }
        System.out.println("Reverse of Number is:- "+resultNum);
    }

    static void reverseStr(String inputStr) //to get reverse of string
    {
        String resultStr = "";
        int lengthStr = inputStr.length();

        for(int i = lengthStr-1; i>=0; i--)
        {
            resultStr = resultStr + inputStr.charAt(i);
        }
        System.out.println("Reverse of String is :- "+resultStr);
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Number to be reversed : ");
        int numInput = sc.nextInt();

        reverseNum(numInput);

        System.out.println("Enter String to be reversed :");
        String strInput = sc.next();

        reverseStr(strInput);
    }
}