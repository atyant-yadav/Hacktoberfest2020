#include<stdio.h>

int main(){
	
	int i,n,j,max,k;
	
	printf("Enter size");
	scanf("%d",&n);
	
	int jb[n],ijb[n],d[n],pr[n],sq[n];

	printf("Enter array of jobs");
	for(i=0;i<n;i++)
	{
		scanf("%d",&jb[i]);
		ijb[i]=jb[i];
	}	

	printf("Enter array of delays");
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i]);	
	}	
	
	
	for(j=0;j<n;j++)
	{
		max = jb[0];
		k=0;
		for(i=0;i<n;i++)
		{
			if(max<jb[i])
			{
				max=jb[i];
				k=i;
			}
		}
		pr[j]=k;
		jb[k]=-100;
		
	}
		
		for(i=0;i<n;i++)//initialising sequence array as -100
		{
			sq[i]=-100;
		}
		
		for(i=0;i<n;i++)
		{
			if(sq[d[pr[i]]]==-100)
			{
				sq[d[pr[i]]]=pr[i];
				
			}
			else
			{
				for(j=d[pr[i]];j>0;j--)
				{
					if(sq[j]==-100)
					{
						sq[j]=pr[i];
						
						break;
					}
				}
			}
		}
		
		
		for(i=0;i<n;i++)
		{
			if(sq[i]!=-100)
			{
				printf("%d ",ijb[sq[i]]);
			}
		}

		
		printf("\n Squence of jobs is\n");
		
		for(i=0;i<n;i++)
		{
			if(sq[i]!=-100)
			{
				printf("%d ",sq[i]+1);
			}
		}	
	
	return 0;
	}
