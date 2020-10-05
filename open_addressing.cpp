#include<bits/stdc++.h>
using namespace std;

struct hashing {
    int size;
    list<int> *table;

    hashing(int s) {
        size = s;
        table = new list<int> [size];
    }

    void insert(int x) {
        int i = x % size;
        table[i].push_back(x);
    }

    void remove(int x) {
        int i = x % size;
        table[i].remove(x);
    }

    bool search(int x) {
        int i = x % size;
        for(auto &it:table[i]) {
            if(it == x) return true;
        }
        return false;
    }
}h(7);

int main() {
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(7);
    h.insert(22);
    cout<<"Searching 22 "<<h.search(22)<<endl;
    cout<<"Searching 15 "<<h.search(15)<<endl;
    cout<<"Searching 14 "<<h.search(14)<<endl;
    h.remove(7);
    cout<<"Searching 7 "<<h.search(7)<<endl;
    return 0;
}