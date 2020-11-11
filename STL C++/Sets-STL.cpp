// Link to the problem : https://www.hackerrank.com/challenges/cpp-sets/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int Q;
    set<int> vals;
    cin >> Q;
    while(Q--) {
        int y,x;
        cin >> y >> x;
        if(y == 1) {
            vals.insert(x);
        }
        else if(y == 2) {
            vals.erase(x);
        }
        else {
            set<int>::iterator itr;
            itr = vals.find(x);
            if(itr == vals.end()) {
                cout << "No" << endl;
            }
            else {
                cout << "Yes" << endl;
            }
        }
    }  
    return 0;
}
