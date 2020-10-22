// C++ program to find the Length of the 
// longest alternating even odd subarray 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find the longest subarray 
int longestEvenOddSubarray(int a[], int n) 
{ 
	// Length of longest 
	// alternating subarray 
	int longest = 1; 
	int cnt = 1; 

	// Iterate in the array 
	for (int i = 0; i < n - 1; i++) { 

		// increment count if consecutive 
		// elements has an odd sum 
		if ((a[i] + a[i + 1]) % 2 == 1) { 
			cnt++; 
		} 
		else { 
			// Store maximum count in longest 
			longest = max(longest, cnt); 

			// Reinitialize cnt as 1 consecutive 
			// elements does not have an odd sum 
			cnt = 1; 
		} 
	} 

	// Length of 'longest' can never be 1 
	// since even odd has to occur in pair or more 
	// so return 0 if longest = 1 
	if (longest == 1) 
		return 0; 

	return max(cnt, longest); 
} 

/* Driver code*/
int main() 
{ 
	int a[] = { 1, 2, 3, 4, 5, 7, 8 }; 

	int n = sizeof(a) / sizeof(a[0]); 

	cout << longestEvenOddSubarray(a, n); 
	return 0; 
} 

/*Output:
5
*/
