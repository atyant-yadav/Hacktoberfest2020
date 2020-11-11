import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int[] d=new int[1000001];
	public static int dp(int N) {
		if(N==0 || N==1)
			return 0;
		
		if(d[N]>0)
			return d[N];
		
		if(N%3==0 && N%2==0) {
			d[N]= Math.min(dp(N/3), Math.min(dp(N-1),dp(N/2)))+1;
		}else if(N%3==0) {
			d[N]= Math.min(dp(N/3),dp(N-1))+1;
		}else if(N%2==0) {
			d[N]= Math.min(dp(N/2), dp(N-1))+1;
		}else {
			d[N]= dp(N-1)+1;
		}
		return d[N];
		
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int N=Integer.parseInt(br.readLine());
		
		System.out.println(dp(N));
		
		
	}

}