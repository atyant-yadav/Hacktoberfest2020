#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,odd,even,tp,a;
    cin>>t;
    while(t--)
    {
        tp=0;
        even=0;
        odd=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a%2==0)
            {
                even++;
            }
            else
            {
                tp+=even;
                odd++;
            }
        }
        cout<<tp<<endl;
    }
    return 0;
}
