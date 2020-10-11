//CPP program toFind out whether N can be expressed as the sum of exactly M prime numbers
#include<bits/stdc++.h>
using namespace std;

bool prime(int a)
{
    for (int i=2; i<=sqrt(a); i++)
        if (a%i == 0)
            return false;
    return true;
}
bool ques(int N,int K)
{
    if(N<2*K)
    return false;
    if(K==1)
     return prime(N);
    if(K==2)
    {
        if(N%2==0)
        return true;
        return prime(N-2);
    }
    return true;

}
int main()
{
    int c,i, d,T;
    cin>>T;
    for(i=0;i<T;i++)
    {
    cin>>c>>d;
    if (ques (c, d))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}}
