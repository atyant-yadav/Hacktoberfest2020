class F
{
	public static void main(String args[])
	{
		int a=153;
		int r=0;
		int sum=0;
		int num=a;
		while(a!=0)
		{
			r=a%10;
			a=a/10;
			sum=sum+(r*r*r);
		}
		if(sum==num)
		{
			System.out.println("Amstrong number");
		}
		else
		{
			System.out.println("Not a armstrong number");
		}
		

	}
}