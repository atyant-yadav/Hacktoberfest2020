	/**
	*    author:  accesss_denied
	**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define translow transform(s.begin(),s.end(),s.begin(),::tolower);
#define transup transform(s.begin(),s.end(),s.begin(),::toupper);
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll mod=1e9+7;
 
 
int main() {
				fast
                #ifndef ONLINE_JUDGE
                freopen("input.txt","r",stdin);
                freopen("output.txt","w",stdout);
                #endif

               ll n,m;
               cin>>n>>m;
               queue< ll >q;
               map< ll,pair<ll,ll> >check;
               // vector<ll>dist(n+1,0);
               for(ll i=0;i<n;i++)
               {
                  ll x;
                  cin>>x;
                  q.push(x);
                  check[x]={1,0};
               }

               vector<ll>ans;
             
               ll ans2=0;
               while(!q.empty())
               {
                    ll x=q.front();
                    
                    q.pop();
                    // cout<<x<<" "<<check[x].second<<endl;
                    if(ans.size()!=m and check[x].first==0)
                    {
                        ans.pb(x);
                        ans2+=check[x].second;
                        check[x].first==1;
                        
                    }
                    if(ans.size()==m)
                        break;

                    if(check.find(x+1)==check.end())
                    {
                        q.push(x+1);
                        check[x+1]={0,check[x].second+1};
                    }
                    if(check.find(x-1)==check.end())
                    {
                        q.push(x-1);
                        check[x-1]={0,check[x].second+1};
                    }
                    
               }
               cout<<ans2<<endl;

               for(ll i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";

                return 0;
            }