import java.util.*;

class Fib
{
public static void nonrecur(int a,int b,int n)
{
	int i;
	int c;
	for(i=2;i<n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	System.out.println("nth number(non-recur) is :"+b);
}

public static void recur(int a, int b, int n)
{
	
	if(n==0)
	{
		System.out.println("nth number(recur) is :"+b);
	}
	else
	{
		recur(b,a+b,--n);
	}
}

public static void main(String[] args)
	{
		Fib a=new Fib();
		Scanner scan=new Scanner(System.in);
		System.out.println("enter the value of n");
		int n=scan.nextInt();
		
		a.nonrecur(1,1,n);
		a.recur(1,1,n-2);
	}
}
