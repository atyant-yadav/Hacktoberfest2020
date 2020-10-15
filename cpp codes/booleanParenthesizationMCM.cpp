#include<bits/stdc++.h>
#define BATMAN ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vs vector<string>
#define pii pair<int,int>
#define uii unordered_map<int,int>
#define FOR(i,n) for(int i=0;i<n;i++)
#define forit(it,g) for(auto it=g.begin();it!=g.end();it++)
#define finder(x,val) return x.find(val)!=x.end() 
#define int long long int
using namespace std;

int t[205][205][2];
int eett(string s, int i, int j, int want){
    if(i > j)
        return 0;
    if(i == j){
        if((s[i] == 'T' && want == 1) || (s[i] == 'F' && want == 0))
            return t[i][j][want] = 1;
        else return t[i][j][want] =  0;
    }
    if(t[i][j][want] != -1)
        return t[i][j][want];
    int ans = 0;
    for(int k = i + 1; k < j; k += 2){
        int lf = eett(s, i, k - 1, 0);
        int lt = eett(s, i, k - 1, 1);
        int rf = eett(s, k + 1, j, 0);
        int rt = eett(s, k + 1, j, 1);
        if(s[k] == '|'){
            if(want == 1)
                ans = (ans + lf*rt + lt*rf + lt*rt)%1003;
            else ans = (ans + (lf*rf))%1003;
        }
        if(s[k] == '&'){
            if(want == 1)
                ans = (ans + (lt*rt))%1003;
            else
                ans = (ans+ (lt*rf + lf*rt + lf*rf))%1003;
        }
        if(s[k] == '^'){
            if(want == 1){
                ans = (ans+ (lt*rf + lf*rt))%1003;
            }            
            else 
                ans = (ans + (lt*rt + lf*rf))%1003;
        }
    }
    return t[i][j][want] = ans%1003;
    
}

int32_t main()
{
	BATMAN
	int T;
	cin>>T;
	while(T--){
	    memset(t,-1,sizeof(t));
	    int N;
	    cin>>N;
	    string s;
	    cin>>s;
	    cout<<eett(s, 0, N - 1, 1)%1003<<"\n";
	}
	return 0;
}