#include<stdio.h>
main()
{
    int a[20],i,j,d,t,x,1=0,low,mid,high;
    printf("\nenter the number of elements\n");
    scanf("%d",&d);
    printf("enter the numbers\n");
    for(i=0;i<d;i++)
    scanf("%d",&a[i]);
    for(i=0;i<d;i++)
    {
        for(j=i+1;j<d;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    printf("\nthe sorted list:");
    for(i=0;i<d;i++)
    printf("%d",a[i]);
    printf("\nenter the number to be searched\n");
    scanf("%d",&x);
    low=0;
    high=d-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x<a[mid])
        high=mid-1;
        else if(x>a[mid])
        low=mid+1;
        else
        {
        if(x==a[mid])
        {
            1++;
        printf("the item %d is found at location %d\n",x,mid+1);
        exit(0);
        }
        }
    }
     if(1==0)
     printf("item is not found\n");
}
