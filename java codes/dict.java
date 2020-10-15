//Complete this code or write your own from scratch
import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh){
        Scanner scan = new Scanner(System.in);    


        Map<String,Integer> users = new HashMap<>();
        // System.out.println("enter turns");
        int turns = scan.nextInt();
        scan.nextLine();

        for(int i =0; i<turns;i++) {
            String str =scan.next();
            int value = scan.nextInt();
            scan.nextLine();
            users.put(str,value);
        }
        // Iterator it = users.entrySet().iterator();
        while(scan.hasNext()) {
            String a = scan.next();
            if(users.containsKey(a)) {
                System.out.println(a+"="+users.get(a));
            }else {
                System.out.println("Not found");
            }
        }
        scan.close();
    }
}

