#include <iostream> 
using namespace std; 

int josephus(int n, int k) 
{ 
	if (n == 1) 
		return 0; 
	else
		return (josephus(n - 1, k) + k) % n; 
} 

int main() 
{ 
	int n, k;
    cin >> n >> k;
	cout << "The chosen place is " << josephus(n, k) + 1; 
	return 0; 
} 
