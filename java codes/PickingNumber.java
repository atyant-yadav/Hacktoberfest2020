import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;


//A program that returns length of longest subsequence such that absolute difference between two numbers is <=1.
class Result {

    public static int pickingNumbers(ArrayList<Integer> a) {
        int[] freq = new int[100];
        int max = 0;
        for(int i=0;i<a.size();i++){
            freq[a.get(i)] = freq[a.get(i)] +1;
        }
        for(int i=0;i<a.size()-1;i++){
            if((freq[i]+freq[i+1])>max)
                max = freq[i]+freq[i+1];
        }
        return max;
    }

}

public class PickingNumber{
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Integer> a = new ArrayList<Integer>();
        for(int i=0;i<n;i++)
	a.add(sc.nextInt());
	
        int result = Result.pickingNumbers(a);

        System.out.println("Length of longest subarray is: "+result);
    }
}
