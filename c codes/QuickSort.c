#include<stdio.h>

void quick_sort(int a[],int p,int q);
int partition(int a[],int p,int q);
int swap(int*a,int*b);

int main()
{
    int a[50],n,i;
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    quick_sort(a,0,n-1);
    
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}

void quick_sort(int a[],int p,int q)
{
    int m;
    if(p<q)
    {
        m=partition(a,p,q);
        quick_sort(a,p,m-1);
        quick_sort(a,m+1,q);
    }
}

int partition(int a[],int p,int q)
{
    int pivot,i,j;
    pivot=a[p];
    i=p;
    for(j=p+1;j<=q;j++)
    {
        if(a[j]<=pivot)
        {
            i=i+1;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[p],&a[i]);
    return (i);
}

int swap(int*a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}