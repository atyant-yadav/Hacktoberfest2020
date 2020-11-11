/*
A solution to codechef problem
Question link: https://www.codechef.com/JAN20B/problems/BRKBKS/
*/

#include <iostream>
using namespace std;

int calc(){
    int w1,w2,w3,s;
    cin>>s>>w1>>w2>>w3;
    if(s>=w1+w2+w3)
        return 1;
    else if(s>=w1+w2 || s>=w2+w3)
        return 2;
    else
        return 3;
}

int main() {
	int N;
	cin>>N;
	for(N;N>0;N--){
	    cout<<calc()<<endl;
	}
	return 0;
}
