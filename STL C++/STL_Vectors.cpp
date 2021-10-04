#include<iostream>
#include<vector>
using namespace std;
void printvec(vector<int>v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int main(){
	vector<int>v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
		printvec(v);
		
	vector<int>p(10,5);//vector of size 10 with each element as 5
	printvec(p);
	//v.size is used to get size of vector
	//pop_back to remove last element of vector
	v.pop_back();
	printvec(v);
	//to create copy of a vector
	vector<int>v2=p;
	v2.push_back(10);
	printvec(v2);
	//reference of vector use &
	vector<int>&v3=p;

	printvec(v3);
}
