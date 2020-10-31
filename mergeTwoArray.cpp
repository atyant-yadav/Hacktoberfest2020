
// C++ program to implement 
// the above approach 
  
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to perform min heapify 
// on array brr[] 
void minHeapify(int brr[], int i, int M) 
{ 
  
    // Stores index of left child 
    // of i. 
    int left = 2 * i + 1; 
  
    // Stores index of right child 
    // of i. 
    int right = 2 * i + 2; 
  
    // Stores index of the smallest element 
    // in (arr[i], arr[left], arr[right]) 
    int smallest = i; 
  
    // Check if arr[left] less than 
    // arr[smallest] 
    if (left < M && brr[left] < brr[smallest]) { 
  
        // Update smallest 
        smallest = left; 
    } 
  
    // Check if arr[right] less than 
    // arr[smallest] 
    if (right < M && brr[right] < brr[smallest]) { 
  
        // Update smallest 
        smallest = right; 
    } 
  
    // if i is not the index 
    // of smallest element 
    if (smallest != i) { 
  
        // Swap arr[i] and arr[smallest] 
        swap(brr[i], brr[smallest]); 
  
        // Perform heapify on smallest 
        minHeapify(brr, smallest, M); 
    } 
} 
  
// Function to merge two sorted arrays 
void merge(int arr[], int brr[], 
           int N, int M) 
{ 
  
    // Traverse the array arr[] 
    for (int i = 0; i < N; ++i) { 
  
        // Check if current element 
        // is less than brr[0] 
        if (arr[i] > brr[0]) { 
  
            // Swap arr[i] and brr[0] 
            swap(arr[i], brr[0]); 
  
            // Perform heapify on brr[] 
            minHeapify(brr, 0, M); 
        } 
    } 
  
    // Sort array brr[] 
    sort(brr, brr + M); 
} 
  
// Function to print array elements 
void printArray(int arr[], int N) 
{ 
  
    // Traverse array arr[] 
    for (int i = 0; i < N; i++) 
        cout << arr[i] << " "; 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 2, 23, 35, 235, 2335 }; 
    int brr[] = { 3, 5 }; 
    int N = sizeof(arr) / sizeof(arr[0]); 
    int M = sizeof(brr) / sizeof(brr[0]); 
  
    // Function call to merge 
    // two array 
    merge(arr, brr, N, M); 
  
    // Print first array 
    printArray(arr, N); 
  
    // Print Second array. 
    printArray(brr, M); 
  
    return 0; 
} 
