import java.util.*;

public class operators {
    public static void main(String[] args)
    {
        String x = "ayush";
        String y = "gupta";

        Scanner s = new Scanner(System.in);
        System.out.print("Enter username:");
        String uuid = s.next();
        System.out.print("Enter password:");
        String upwd = s.next();

        
        if ((uuid.equalsIgnoreCase(x) && upwd.equalsIgnoreCase(y))
            || (uuid.equalsIgnoreCase(y) && upwd.equalsIgnoreCase(x)))
            {
            System.out.println("Welcome "+uuid);
        }
        else {
            System.out.println("Wrong uid or password");
        }
    }
}
