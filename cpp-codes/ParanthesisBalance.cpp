#include<bits/stdc++.h>
using namespace std;
bool bpair(char open , char close) //a boolean function to check for pair of braces (), {},[]
{
	if(open =='(' && close == ')') return true;
	if(open == '{' && close=='}') return true;
	if(open == '[' && close == ']') return true;
	return false; 
}
bool balance(string exp)
{
	stack<char>S;
	for(int i=0;i<exp.length();i++)
	{
		if(exp[i]=='(' || exp[i]== '{' ||exp[i]=='[')
		{
			S.push(exp[i]);
		}
		else if(exp[i]==')' || exp[i]== '}' ||exp[i]==']')
		{
			if(S.empty() || (!bpair(S.top(), exp[i])))
			{                        
				return false;
			}
			else
			{
				S.pop();
			}
		}
	}
	return S.empty()? true : false;
}
int main()
{
	cout<<"Enter the paranthesis expression"<<endl;
	string exp;
	cin>>exp;
	if(balance(exp))
	{
		cout<<"balanced"<<endl;
	}
	else
	{
		cout<<"not balanced"<<endl;
	}
}
