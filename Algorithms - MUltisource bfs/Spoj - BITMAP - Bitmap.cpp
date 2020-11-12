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
 ll dx[]={-1,1,0,0};
 ll dy[]={0,0,1,-1};

    ll valid(ll x,ll y,ll n,ll m)
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
            
                    queue<ll>q;
                     

                     //taking input and make distance of black =-1
                	for(ll i=1;i<=n;i++){
                    for(ll j=1;j<=m;j++)
                    {
                        char c;
                        cin>>c;
                	    arr[i][j]=c-'0';
                  
                    if(arr[i][j]==1)
                    {
                        q.push(i);
                        q.push(j);
                        dist[i][j]=0;
                    }
                    else
                        dist[i][j]=-1;
                    }
                    }
                   

                    //push all the source node as starting nodes and at every step find nearest node and update the distance of nearest node
                    //after this visit all neighbour if ther are not visted already then push them into queues
                    while(!q.empty())
                    {
                        ll ci=q.front();

                        q.pop();
                        ll cj=q.front();
                        q.pop();

                        //In matrix if we want to visit all neighbour nodes then make dx and dy array and by the help of loop visit all nodes and also check position is valid or not

                        for(ll i=0;i<4;i++)
                        {
                            if(valid(ci+dx[i],cj+dy[i],n,m) and dist[ci+dx[i]][cj+dy[i]]==-1)
                            {
                                dist[ci+dx[i]][cj+dy[i]]=dist[ci][cj]+1;
                                q.push(ci+dx[i]);
                                q.push(cj+dy[i]);
                            }
                        }
                    }




                    for(ll i=1;i<=n;i++){
                    for(ll j=1;j<=m;j++)
                    {
                        cout<<dist[i][j]<<" ";
                    }
                    cout<<endl;
                    }

                }

                return 0;
            }