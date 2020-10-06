//Contributed by LINSMARIYA
#include<stdio.h>
void main()
{
    int bursttime[20],process[20],wt[20],tat[20],i,j,n,total=0,pos,temp,arrivaltime[20];
    float avg_wt,avg_tat;
    printf("\nEnter number of process:");
    scanf("%d",&n);
 
 
    for(i=0;i<n;i++)
    {
	printf("\nEnter Process %d ID:",i+1);
	scanf("%d", &process[i]);
	printf("\nEnter Arrival %d Time:",i+1);
        scanf("%d",&arrivaltime[i]);
	printf("\nEnter Burst %d Time:",i+1);
        scanf("%d",&bursttime[i]);
    }
 
    
    //sorting arrival time in ascending order 
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(arrivaltime[j]<arrivaltime[pos])
                pos=j;
        }
 
        temp=arrivaltime[i];
        arrivaltime[i]=arrivaltime[pos];
        arrivaltime[pos]=temp;
        
        temp=bursttime[i];
        bursttime[i]=bursttime[pos];
        bursttime[pos]=temp;
 
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
 
    wt[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bursttime[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bursttime[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",process[i],bursttime[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
    
}
 
