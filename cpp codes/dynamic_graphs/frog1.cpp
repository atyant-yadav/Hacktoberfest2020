#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		ll A[n],B[n];
		map<ll,ll>m1;
		map<ll,ll>m2;
		for(int i=0;i<n;i++)
			{ 
				cin>>A[i];
				m1[A[i]]++;
				
			}
		for (int i = 0; i <n; i++)
		{
			cin>>B[i];	
			m2[B[i]]++;
			
				}
		sort(A,A+n);
		sort(B,B+n);
		
		ll mini=B[0];
		ll maxi=B[n-1];

		
		ll cost=0;
		int flag=0;
		int count=0;
		int j=0;
		int k=n-1;
		for(int i=0;i<n;i++)
		{
			if(A[i]!=B[i] && m1[A[i]]==1 && m2[A[i]]==0)
			{
				flag=1;
				break;
			}
			if(m1[A[i]]==m2[A[i]] || m1[A[i]]<m2[A[i]])
				continue;
			else
			{
				
				if((abs(A[i]-mini)>=abs(A[i]-maxi) && m2[mini]>0) || m2[maxi]==0)
				{
					cost+=min(mini,A[i]);
					
					m1[A[i]]--;
					m1[mini]++;
					m2[A[i]]++;
					m2[mini]--;
					if(m2[mini]==0)
						{
							mini=B[++j];
							
						}
                    
				}
				else
				{

                  cost+=min(A[i],maxi);
                  
                  m1[A[i]]--;
					m1[maxi]++;
					m2[A[i]]++;
					m2[maxi]--;
					if(m2[maxi]==0)
						maxi=B[--k];
				}
			}
		}
			if(flag==1)
			{
				cout<<-1<<endl;
			}
			else
				cout<<cost<<endl;
	}
	return 0;
}