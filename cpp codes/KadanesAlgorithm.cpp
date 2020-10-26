//Program to calculate largest sum of contiguous sub array in the given array (Kadane's algorithm)

#include<iostream.h>
#include<bits/stdc++.h>
using namespace std;

int maxSumOfSubarray(int arr[], int size){
    int max_so_far=INT_MIN;
    int max_curr=0;
    for(int i=0;i<size;i++){
         max_curr+=arr[i];
         if (max_curr < 0) 
           max_curr = 0; 
       else if(max_curr>max_so_far)
           max_so_far=max_curr;
    }
    return max_so_far;
}

int main(){
    int arr[] = {-4, -2, 4, 0, -2, 1, 5, -2}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    int max_sum = maxSumOfSubarray(arr, size); 
    cout << "Maximum sum of contiguous subarray is " << max_sum; 
    return 0; 
}