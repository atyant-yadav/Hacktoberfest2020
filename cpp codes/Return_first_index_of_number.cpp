/*
Given an array arr[] of N integers and the number x, the task is to find the first occurrence of x in arr[]. If the element is not present then return -1.

example: 
         
         Input: 7
                1 2 3 2 5 4 2
                2
         Output: 1
         
         Here, I used simply recursive approach
*/

#include <iostream>
using namespace std;

int first_index(int* arr,int n,int x){  // Function gives first index where we found x element in a given array
    // Base case
    if(n==0){
        return -1;
    }

    if(arr[0]==x){  //if element x is present at 0th index then we simply return 0
        return 0;
    }
    // recursive call
    int index=first_index(arr+1,n-1,x);
    if(index!=-1){
        return index+1;
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;            // Element of which we have to find first index
    cin>>x;
    cout<<first_index(arr,n,x);
}
