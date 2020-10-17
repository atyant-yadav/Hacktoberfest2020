#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    int x,i;
    while(T!=0)
    {
        int N;
        scanf("%d",&N);
        int A[1000];
        for(i=0;i<N;i++)
        {
            scanf("%d\t",&A[i]);

        }
        x=1;
        for(i=0;i<N;i++)
        {
            x=x*A[i];
        }
       if(x%2==0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
        T--;
    }
    return 0;
}

