// C++ program to print largest contiguous array sum 

#include<iostream> 
#include<climits> 
using namespace std; 
  
int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0, 
       start =0, end = 0, s=0; 
  
    for (int i=0; i< size; i++ ) 
    { 
        max_ending_here += a[i]; 
  
        if (max_so_far < max_ending_here) 
        { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        } 
  
        if (max_ending_here < 0) 
        { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    } 
    cout << "Maximum contiguous sum is "
        << max_so_far << endl; 
    cout << "Starting index "<< start 
        << endl << "Ending index "<< end << endl; 
} 

int main() 
{ 
    int n;
    cout << "Enter number of elements in array \n";
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << " -\n";
        cin >> a[i]; 
    }
    int max_sum = maxSubArraySum(a, n); 
    return 0; 
} 
