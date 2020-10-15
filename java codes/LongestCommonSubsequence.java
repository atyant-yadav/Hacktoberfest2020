import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
 {
    static int LCS(char[] X,char[] Y,int m,int n){
        int[][] arr = new int[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    arr[i][j]=0;
                    
                }
                else if(X[i-1]==Y[j-1]){
                    arr[i][j]=arr[i-1][j-1]+1;
                    
                }
                else{
                    arr[i][j]=(int)Math.max(arr[i-1][j],arr[i][j-1]);
                    
                }
                
            }
            
        }
        return arr[m][n];
        
    }
	public static void main (String[] args)
	 {
	     
	     Scanner sc=new Scanner(System.in);
	     int t=sc.nextInt();
	     while(t>0){
	         int m=sc.nextInt();
	         int n=sc.nextInt();
	         sc.nextLine();
	         String s1=sc.nextLine();
	         String s2=sc.nextLine();
	         char[] X=s1.toCharArray();
	         char[] Y=s2.toCharArray();
	         System.out.println(LCS(X,Y,m,n));
	         t--;
	     }
	 }
}
