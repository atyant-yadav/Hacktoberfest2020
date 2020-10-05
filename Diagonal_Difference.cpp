#include <bits/stdc++.h>
using namespace std;

int diff(int a, int b){
    if(a>b)
    return a-b;

    else
    return b-a;
}

int main()
{
    int n,sum1=0,sum2=0;
    cin>>n;

    int a[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0; i<n; i++){
        sum1=sum1+a[i][i];
    }

    for(int i=0; i<n; i++){
        sum2=sum2+a[i][n-i-1];
    }

    cout<<diff(sum1,sum2);
    return 0;
}
