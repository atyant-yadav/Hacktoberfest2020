#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printt(int open,int close, string op) {
	if(open==0 && close==0) {
		cout<<op<<endl;
		return;
	}
	if(op=="") {
		printt(open-1,close,op+"(");
	}
	else if(open==0) {
		printt(open,close-1,op+")");
	}
	else if(open==close) {
		printt(open-1,close,op+"(");
	}
	else {
		printt(open-1,close,op+"(");
		printt(open,close-1,op+")");
	}
}

void print(int n) {
	printt(n,n,"");
	return;
}

int main() {
	//n = total number of complete(open and closed) brackets
	//print() prints all the combinations of balanced parenthesis
	int n;
	cin>>n;
	print(n);
	
	return 0;
}
