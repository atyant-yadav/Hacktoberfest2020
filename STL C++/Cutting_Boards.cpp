#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int row,col,t,a,cost=0,sc=0,sr=0;
    vector<long long int> r,c;
    cin >> t;
    while(t--)
    {
        sc=1,sr=1,cost=0;
        cin>>row>>col;

        for (int i=1;i<row;++i)
        {
            cin>>a;
            r.push_back(a);
        }
        for (int i=1;i<col;++i) 
        {
            cin>>a;
            c.push_back(a);
        }

        sort(r.begin(),r.end());
        sort(c.begin(),c.end());

        long long int valr=0,valc=0;
        long long int s1=r.size()-1;
        long long int s2=c.size()-1;
        for (int i=0;i<r.size()+c.size();++i) 
        {
            valr=0,valc=0;

            if(s1>=0)
            valr=r[s1];

            if(s2>=0)
             valc=c[s2];

            if(valc>valr)
            {         
                cost+= valc*sr;
                s2--;
                sc++;
            }
            else 
            {
                cost+=valr*sc;
                s1--;
                sr++;
            }   
        }
        cout<<cost % 1000000007<<endl;
        r.clear();
        c.clear();
    }
    return 0;
}