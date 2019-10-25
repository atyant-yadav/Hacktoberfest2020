#include<bits/stdc++.h>
typedef unsigned long long int ull;
typedef long long int ll;
using namespace std;
int main()
{
    ll t,n,x,y,cnt;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt=0;
        ll a[n],b[n];
        vector<pair<ll,ll>> s;
        vector<pair<ll,ll>> k;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            
        }
        for(int i=0;i<n;i++)
        {
            s.push_back(make_pair(a[i],b[i]));
        }
        
        if(s[0].second>s[n-1].first && s[0].second>s[1].first)
        {
            if(s[0].second>(s[1].first+s[n-1].first))
            {k.push_back(make_pair(s[0].second,0));cnt++;
            }
        }
        for(int i=1;i<n-1;i++)
        {
            if(s[i].second>s[i-1].first && s[i].second>s[i+1].first)
            {
                if(s[i].second>(s[i-1].first +s[i+1].first))
                {k.push_back(make_pair(s[i].second,i));cnt++;}
            }
        }
        if(s[n-1].second>s[0].first && s[n-1].second>s[n-2].first)
        {
            if(s[n-1].second>(s[0].first + s[n-2].first))
            {k.push_back(make_pair(s[n-1].second,n-1));cnt++;}
        }
        sort(k.begin(),k.end());
        if(k.empty())
        cout<<-1<<endl;
        else
        {
            cout<<k[cnt-1].first<<endl;
        }
    }
    return 0;
}
