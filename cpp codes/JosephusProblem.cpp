#include <iostream>
#include <bits/stdc++.h>
using namespace std; 

int solve(vector<int> v,int n,int k, int index) {
	if(v.size()==1) {
		return v[0];
	}
	index = (k+index)%v.size();
	v.erase(v.begin()+index);
	return solve(v,n,k,index);
}

int find(int n,int k) {
	vector<int> v;
	for(int i=0;i<n;i++) {
		v.push_back(i+1);
	}
	int ans = solve(v,n,k-1,0);
	return ans;
}

int main() {
	//n = Total number of people
	//k = The first person will shoot the kth person and so on
	//ans = The position at which Josephus should stand so that we won't get shooted
	int n,k;
	cout<<"Enter the total number of people: ";
	cin>>n;
	cout<<"Enter the kth position at which the first person will shoot: ";
	cin>>k;
	int ans = find(n,k);
	cout<<"Josephus should stand at the position: "<<ans;
	return 0;
}
