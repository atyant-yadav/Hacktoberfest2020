import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
 {
	public static void main (String[] args)
	 {
	    Scanner sc = new Scanner(System.in);
	    int t = sc.nextInt();
	    while(t-- > 0){
	        int n = sc.nextInt();
	        int a[] = new int[n];
	        for(int i= 0 ; i<n ;i ++){
	            a[i] = sc.nextInt();
	        }
	        int sum = 0, msum = 0;
	        for(int i=0 ; i<n ; i++){
	            sum += a[i];
	            if(i == 0){msum = sum;}
	            
	            if(msum < sum){
	                msum = sum;
	            }
	            
	            if(sum < 0){sum = 0;}
	        }
	        System.out.println(msum);
	    }
	 }
}