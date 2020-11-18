#include<iostream>

using namespace std;

int main() 
{
    long long unsigned int n,term_1=1,term_2=1,nextTerm = 0;
    cout << "Enter the number of terms : ";

    cin >> n;

    cout << "---Fibonacci Series : ---\n";

    for(int i=1;i<=n;i++) {
        if (i == 1) {
            cout << term_1 << "\n";
            continue;
        }
        if (i == 2) {
            cout << term_2 << "\n";
            continue; 
        }
        nextTerm = term_1+term_2;
        term_1 = term_2;
        term_2 = nextTerm;

        cout<< nextTerm << "\n";
    }
    return 0;
}