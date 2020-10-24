#include<stdio.h>

int main()
{
	int n,i,j,k,ckc;
	
	printf("Enter number of terms");
	scanf("%d",&n);
	int pr[n];
	float x[n],p[n],w[n],pw[n],max;
	
	for(i=0;i<n;i++)	//initialising fraction index as zero;
	{
		x[i]=0;
	}
	
	printf("Enter weights");
	for(i=0;i<n;i++)
		scanf("%f",&w[i]);

	printf("Enter profits");
	for(i=0;i<n;i++)
		scanf("%f",&p[i]);
	
	printf("Enter Knapsack capacity");
	scanf("%d",&ckc);
	
	for(i=0;i<n;i++)
	{
		pw[i]=(p[i]/w[i]);
	}
	
	printf("p/w: ");
	for(i=0;i<n;i++)
		printf("%f ",pw[i]);
	 
	 printf("\n");
	 
	for(j=0;j<n;j++)
	{
		max = pw[0];
		k=0;
		for(i=0;i<n;i++)
		{
			if(max<=pw[i])
			{
				max=pw[i];
				k=i;
			}
		}
		pr[j]=k;
		printf("%d:%d:%d ",k,pr[j],j);
		pw[k]=-100;
		
	}
	printf("\n\ntest:\n%d %d %d\n",pr[0],pr[1],pr[2]);
	printf("\nPriority: \n");
	for(i=0;i<n;i++)
		printf("%d ",pr[i]);
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		if(ckc>=w[pr[i]])
		{
			x[pr[i]]=1;
			ckc=ckc-w[pr[i]];
		}
		
		else if((ckc==0)||(ckc<w[pr[i]]))
			break;
		
	}
	if(ckc!=0)
	{
		x[pr[i]]=(ckc/w[pr[i]]);
	}
	
	for(i=0;i<n;i++)
	{
		printf("%.2f ",x[i]);
	}
	
	return 0;
}
