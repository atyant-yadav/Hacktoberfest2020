//Largest of Two numbers without using comparison operator
#include <iostream> 
using namespace std; 
int largestNum(int a, int b) 
{ 
	return a * (bool)(a / b) + b * (bool)(b / a); 
} 
int main() 
{ 
	int a = 22, b = 1231; 
	cout << largestNum(a, b); 
	return 0; 
} 
