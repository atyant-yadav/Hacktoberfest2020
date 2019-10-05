#include<iostream>
#include<cmath>
using namespace std;
int findSum( int A[], int N) ;
int main() {
    long int n, k;
    cin>>n;
    k=(sqrt(1+8*n)-1)/2;
    cout<<k<<endl;
    int a[k];
    for(long int i=1;i<=k;i++)
        a[i]=0;
    for(long int i=1;i<=k-1;i++)
        a[i]=i;
    int sum = findSum(a, k);
    a[k] = n-sum;
    for(long int i=1;i<=k;i++)
        cout<<a[i]<<" ";
    return 0;
}
int findSum(int A[], int N) 
{ 
    if (N <= 1) 
        return 0; 
    return (findSum(A, N - 1) + A[N - 1]); 
}

//code by Mallikarjun Katakam