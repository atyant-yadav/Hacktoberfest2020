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

//to move in all the 8 directions
    ll dx[]={-1,-1,-1,1,1,1,0,0};
    ll dy[]={-1,1,0,-1,0,1,-1,1};

        ll valid(ll x,ll y,ll n ,ll m)
        {
            if(x>=1 and x<=n and y>=1 and y<=m)
                return 1;
            return 0;
        }
 
int main() {
				fast
                #ifndef ONLINE_JUDGE
                freopen("input.txt","r",stdin);
                freopen("output.txt","w",stdout);
                #endif

                ll t;
                cin>>t;
                while(t--)
                {

                	ll n,m;
                    cin>>n>>m;
                    ll arr[n+1][m+1];
                    ll dist[n+1][m+1];
                    ll mx=LLONG_MIN;
                    for(ll i=1;i<=n;i++)
                    {
                        for(ll j=1;j<=m;j++)
                        {
                            cin>>arr[i][j];
                            mx=max(mx,arr[i][j]);
                        }
                    }

                    queue<ll>q;
                    for(ll i=1;i<=n;i++)
                    {
                        for(ll j=1;j<=m;j++)
                        {
                            if(arr[i][j]==mx)
                            {
                                q.push(i);
                                q.push(j);
                                dist[i][j]=0;
                            }
                            else
                                dist[i][j]=-1;
                        }
                    }


                    //multisource bfs
                    while(!q.empty())
                    {
                        ll ii=q.front();  q.pop();
                        ll jj=q.front();  q.pop();
                        for(ll i=0;i<8;i++)
                        {
                            if(valid(ii+dx[i],jj+dy[i],n,m) and dist[ii+dx[i]][jj+dy[i]]==-1)
                            {
                                dist[ii+dx[i]][jj+dy[i]]=dist[ii][jj]+1;
                                q.push(ii+dx[i]);
                                q.push(jj+dy[i]);
                            }
                        }
                    }

                    mx=-1;
                     for(ll i=1;i<=n;i++)
                    {
                        for(ll j=1;j<=m;j++)
                        {
                           mx=max(mx,dist[i][j]);
                        }
                       
                    }
                    cout<<mx<<endl;








                 }

                return 0;
            }