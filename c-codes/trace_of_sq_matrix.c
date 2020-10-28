#include<stdio.h>
#include<math.h>  


int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");

    int i, j, n, aj[10][10], sum = 0, sum1 = 0, a = 0, normal;

    printf("\nEnter the number of rows (columns) of the matrix: \n\n");
    scanf("%d", &n);

    printf("\nEnter the %d elements of the first matrix: \n\n", n*n);

    for(i = 0; i < n; i++)  
    {
        for(j = 0; j < n; j++)   
        {
            scanf("%d", &aj[i][j]);
            a = aj[i][j]*aj[i][j];  
            sum1 += a;  
        }
    }
    normal = sqrt((double)sum1);    

    printf("\n\nThe normal of the given matrix is: %d", normal);
    for(i = 0; i < n; i++)
    {
        sum = sum + aj[i][i];   
    }
    printf("\n\nThe Trace of the given matrix is: %d", sum);
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}