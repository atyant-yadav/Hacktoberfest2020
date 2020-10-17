#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main() {
 string str;
 cin>>str;
 stack<char> mystack;
 int l=str.size();
 int ref;
 for (int i=0; i<l; i++) {
  if (mystack.size()==0) {
   mystack.push(str[i]);
   continue;
  }
  ref=(int)str[i];
  if (ref>(int)mystack.top()) {
   if (ref-mystack.top() <=2) {
    mystack.pop();
   }
   else {
    cout << "NO\n";
    return 0;
   }
  }
  else {
   mystack.push(str[i]);
  }
 }
 if (mystack.size()==0) {
  cout << "YES\n";
 }
 else {
  cout << "NO\n";
 }
 return 0;
}
