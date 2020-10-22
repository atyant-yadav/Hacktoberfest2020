// CPP code to rotate an array 
// and answer the index query 
#include <bits/stdc++.h> 
using namespace std; 

// Function to compute the element at 
// given index 
int findElement(int arr[], int ranges[][2], 
			int rotations, int index) 
{ 
	for (int i = rotations - 1; i >= 0; i--) { 

		// Range[left...right] 
		int left = ranges[i][0]; 
		int right = ranges[i][1]; 

		// Rotation will not have any effect 
		if (left <= index && right >= index) { 
			if (index == left) 
				index = right; 
			else
				index--; 
		} 
	} 

	// Returning new element 
	return arr[index]; 
} 

// Driver 
int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5 }; 

	// No. of rotations 
	int rotations = 2; 

	// Ranges according to 0-based indexing 
	int ranges[rotations][2] = { { 0, 2 }, { 0, 3 } }; 

	int index = 1; 

	cout << findElement(arr, ranges, rotations, index); 

	return 0; 

} 
