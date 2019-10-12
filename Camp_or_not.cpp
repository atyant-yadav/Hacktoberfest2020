#include <iostream>

using namespace std;

int main()
{
    int d[32];
    int t,n,a,q,de,p;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=31;i++)
        {
            d[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            cin>>a;
            cin>>d[a];
        }
        for(int i=2;i<=31;i++)
        {
            d[i]+=d[i-1];
        }
        cin>>q;
        for(int i=0;i<q;i++)
        {
            cin>>de>>p;
            if(d[de]>=p)
            {
                cout<<"Go Camp"<<endl;
            }
            else
                cout<<"Go Sleep"<<endl;
        }
    }
    return 0;
}
