#include<bits/stdc++.h>
typedef unsigned long long int ull;
typedef long long int ll;
using namespace std;
int main()
{
    ll t;
    cin>>t;
    string s,e,day[7];
    int a,b,d,j,k;
    day[0]="saturday";
    day[1]="sunday";
    day[2]="monday";
    day[3]="tuesday";
    day[4]="wednesday";
    day[5]="thursday";
    day[6]="friday";
    int l,r;
    while(t--)
    {
        cin>>s>>e>>l>>r;
        for(int i=0;i<7;i++)
        {
            if(day[i].compare(s)==0)
                a=i;
            if(day[i].compare(e)==0)
                b=i;
        }
        if(b>=a)
            d=b-a+1;
        else
            d=8-abs(b-a);
        j=0;
        for(int i=l;i<=r;i++){
			if(i==d||(i%7)==d||((i%7)==0&&d==7&&i!=0)){
				j++;
				k=i;
			}
		}
		if(j==1)
		    cout<<k<<endl;
		else if(j>0)
		    cout<<"many"<<endl;
		else
		    cout<<"impossible"<<endl;
		
		
    }
    return 0;
}
