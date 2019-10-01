#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string r;
		cin>>s;
		cin>>r;
		int len_s = s.size();
		int len_r = r.size();

		int arrs[26] = {0};
		int arrr[26] = {0};
		for(int i=0; i<len_s; i++){
			int te = (int)s[i]-97;
			arrs[te]+=1;
		}	
		for(int i=0; i<len_r; i++){
			int te = (int)r[i]-97;
			arrr[te]+=1;
		}		
		int fla = 1;
		for(int i=0; i<26; i++){
			arrr[i] = arrr[i]-arrs[i];
			if (arrr[i]<0)
			{
				fla = 0;
				break;
			}
		}
		if (fla==0)
		{
			cout<<"Impossible"<<endl;
		}
		else{
			string ans = "";
			int flagg = 1;
			for(int i=0; i<26; i++){
				string tempo = "";
				char teei = (char)(i+97);
				tempo+=teei;
				if(s<tempo && flagg==1){
					ans+=s;
					flagg = 0;
				}
				for (int j = 0; j < arrr[i]; ++j)
				{
					char tee = (char)(i+97);
					ans+=tee; 
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}