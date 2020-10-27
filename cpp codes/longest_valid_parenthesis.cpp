#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    stack<int>st;
	    int i;
	    int n=s.size();
	    for(i=0;i<n;i++)
	    {
	        if(s[i]=='(')
	        st.push(i);
	        else if(st.empty())
	        continue;
	       else if(s[i]==')')
	        st.pop();
	    }
	    while(!st.empty())
	    {
	        s[st.top()]='/';
	        st.pop();
	    }
            int c=0,ans=0,k=0;
            stack<char>stk;
        for(i=0;i<n;i++)
        {
            
            if(s[i]=='/')
            {
                ans=max(ans,k);
                k=0;
                c++;
                continue;
            }
            if(s[i]=='(')
            {
                stk.push('(');
            }
            else if(stk.empty())
            {ans=max(ans,k);k=0;continue;}
            else if(s[i]==')')
            {
                
                stk.pop();
                k+=2;
            }
        }
        ans=max(ans,k);
	    cout<<ans<<endl;
	}
	return 0;
}