using namespace std;
#include<bits/stdc++.h>
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int size1=str1.size();
    int size2=str2.size();
    int mat[size1+1][size2+1];
    for(int i=0;i<=size1;i++)
    {
        for(int j=0;j<=size2;j++)
        {
            if(i==0||j==0)
            {
                mat[i][j]=max(i,j);
            }
        }
    }
    for(int i=1;i<=size1;i++)
    {
        for(int j=1;j<=size2;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                mat[i][j]=mat[i-1][j-1];
            }
            else
            {
                mat[i][j]=min(mat[i-1][j-1],min(mat[i-1][j],mat[i][j-1]))+1;
            }
        }
    }
    cout<<mat[size1][size2]<<endl;
}
