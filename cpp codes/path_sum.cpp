// C++ program to find maximum path sum 
// in a 2D matrix when exactly two 
// left moves are allowed 
#include <bits/stdc++.h> 
#define N 3 
#define M 3 
using namespace std; 

// Function to return the maximum path sum 
int findMaxSum(int arr[][M]) 
{ 
	int sum = 0; 
	int b[N][M]; 
	
	// Copy last column i.e. starting and 
	// ending columns in another array 
	for (int i = 0; i < N; i++) { 
		b[i][M - 1] = arr[i][M - 1]; 
	} 
	
	// Calculate suffix sum in each row 
	for (int i = 0; i < N; i++) { 
		for (int j = M - 2; j >= 0; j--) { 
			b[i][j] = arr[i][j] + b[i][j + 1]; 
		} 
	} 
	
	// Select the path we are going to follow 
	for (int i = 1; i < N; i++) { 
		for (int j = 0; j < M; j++) { 
			sum = max(sum, b[i][j] + b[i - 1][j]); 
			
			b[i][j] = max(b[i][j], b[i - 1][j] + arr[i][j]); 
		} 
	} 
	
	return sum; 
} 

// Driver Code 
int main() 
{ 
	int arr[N][M] = {{ 3, 7, 4 }, 
					{ 1, 9, 6 }, 
					{ 1, 7, 7 }}; 
					
	cout << findMaxSum(arr) << endl; 

	return 0; 
} 
