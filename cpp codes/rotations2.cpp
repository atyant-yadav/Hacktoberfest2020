// C++ program to count all rotation divisible 
// by 4. 
#include <bits/stdc++.h> 
using namespace std; 

// Returns count of all rotations divisible 
// by 4 
int countRotations(string n) 
{ 
	int len = n.length(); 

	// For single digit number 
	if (len == 1) 
	{ 
		int oneDigit = n.at(0)-'0'; 
		if (oneDigit%4 == 0) 
			return 1; 
		return 0; 
	} 

	// At-least 2 digit number (considering all 
	// pairs) 
	int twoDigit, count = 0; 
	for (int i=0; i<(len-1); i++) 
	{ 
		twoDigit = (n.at(i)-'0')*10 + (n.at(i+1)-'0'); 
		if (twoDigit%4 == 0) 
			count++; 
	} 

	// Considering the number formed by the pair of 
	// last digit and 1st digit 
	twoDigit = (n.at(len-1)-'0')*10 + (n.at(0)-'0'); 
	if (twoDigit%4 == 0) 
		count++; 

	return count; 
} 

//Driver program 
int main() 
{ 
	string n = "4834"; 
	cout << "Rotations: " << countRotations(n) << endl; 
	return 0; 
} 
