// Link to the problem : https://www.hackerrank.com/challenges/cpp-maps/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    map<string, int> vals;
    int Q;
    cin >> Q;
    while(Q--) {
        int a, marks;
        string name;
        cin >> a >> name;
        if(a == 1) {
            cin >> marks;
            map<string,int>::iterator itr = vals.find(name);
            if(itr == vals.end()) {
                vals.insert(make_pair(name, marks));
            }
            else {
                vals[name] += marks;
            }
        }
        else if(a == 2) {
            vals.erase(name);
        }
        else {
            map<string,int>::iterator itr = vals.find(name);
            if(itr == vals.end()) {
                cout << 0 << endl;
            }
            else {
                cout << vals[name] << endl; 
            }
        }
    } 
    return 0;
}
