#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
   		map<char, int> mp1;
   		map<char, int> mp2;
   		map<char, int>:: iterator it;
   		map<char, int>:: iterator it2;
   		int count = 0;
   		int count2 = 0;
   		for(int i = 0; i < s.size(); i++){
   			mp1[s[i]] = count;
   			count++;
   		}
   		for(int i = 0; i < t.size(); i++){
   			mp2[t[i]] = count2;
   			count2++;
   		}
   		for(it = mp1.begin(), it2 = mp2.begin(); it != mp1.end(), it2 != mp2.end(); ++it, ++it2){
   			if(it->second != it2->second){
   				count = -1;
   			}
   		}
   		if(count == -1){
   			return false;
   		} else {
   			return true;
   		}
   }
};

int main(){
	string s, t;
	Solution sol;
	cin >> s >> t;
	cout<<sol.isIsomorphic(s, t)<<endl;
	return 0;
}