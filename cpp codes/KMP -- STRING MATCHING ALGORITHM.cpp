#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

			
		
	   
int main() {
			fast
			#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
			#endif	

			string s,pat;
			cin>>s>>pat;

			ll lpx[pat.size()]={0};
			ll i=1,j=0;
			while(i<pat.size())
			{
				if(pat[i]==pat[j])
				{
					lpx[i]=j+1;
					i+=1;
					j+=1;
				}
				else
				{
					if(j==0)
					{
						lpx[i]=0;
						i+=1;
					}
					else
					{
						j=lpx[j-1];
					}
					
				}
				
			}
			// for(ll i=0;i<pat.size();i++)
			// cout<<lpx[i]<<" ";

			ll count=0;
			i=j=0;
			
			while(i<s.size())
			{
				if(s[i]==pat[j])
				{
					i+=1;
					j+=1;
				}
				if(j==pat.size())
				{
					count=1;
					cout<<"Found at index "<<i-(ll)pat.size()<<endl;
					break;
				}
				if(i<s.size() and pat[j]!=s[i])
				{
					if(j!=0)
					j=lpx[j-1];
					else
					i+=1;
				}
				
			}
				
			if(count==0)
			cout<<"Not Found!"<<endl;


			return 0;
		 }	
