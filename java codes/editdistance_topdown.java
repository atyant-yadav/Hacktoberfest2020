 import java.util.*;
 public class editdistance_topdown {

	  
	
	static int min(int x, int y, int z) 
	{ 
	    if(x<y && x<z) 
	    	return x;
	    else if(y<x && y<z)
	    	return y;
	    else
	    	return z;
	} 
	  
	static int editDist(char str1[], char str2[], int m, int n, int dp[][]) 
	{ 
	   
	    if (m == 0) 
	        return n; 
	    if (n == 0) 
	        return m; 
	    if (dp[m - 1][n - 1] != -1) 
	        return dp[m - 1][n - 1]; 
	    if (str1[m-1]==str2[n-1])  
	        return dp[m - 1][n - 1] = editDist(str1, str2, m - 1, n - 1, dp); 
	    return dp[m - 1][n - 1] = 1 + min(editDist(str1, str2, m, n - 1, dp), editDist(str1, str2, m - 1, n, dp),   editDist(str1, str2, m - 1, n - 1, dp)); 
	                                      
	} 
	  
	public static void main(String args[]) 
    { 
		int max=1000;
       
	    Scanner sc=new Scanner(System.in);
	    System.out.println("Enter first string");
	    String str1=sc.nextLine();
	    System.out.println("Enter the second string");
	    String str2=sc.nextLine();	
        int m=str1.length();
        int n=str2.length();
	    int dp[][]=new  int [m][max]; 
	    for(int i=0;i<m;i++)
	    {
		    for(int j=0;j<max;j++)
		    {
		       	 dp[i][j]=-1;
		    }
	    }
	    System.out.println(editDist(str1.toCharArray(), str2.toCharArray(), m, n, dp)); 
	} 

}