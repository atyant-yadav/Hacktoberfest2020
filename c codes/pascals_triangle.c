#include<stdio.h>
int main()
{
    int r,k,j,i,coeff;
    scanf("%d",&r);//input how many number of rows you want in a pascal triangle
    for(i=0;i<r;i++)
    {
        printf("\n");
        for(j=0;j<r-1-i;j++)
        {
            printf(" ");
        }
        for(k=0;k<=i;k++)
        {
        if(i==0 || k==0)
        coeff=1;
        else
        coeff=coeff*(i-k+1)/k;
        printf("%d ",coeff);
        }
    }
    return 0;
}

