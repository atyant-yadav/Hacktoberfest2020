//Implementation of bubble sort using c++
#include <iostream>
#include <algorithm>

using namespace std;
//function for bubble sort
void bubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        //i elements are already in place
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

int main() {
    //array which is going to be sorted
    int arr[] {99,10,9,8,7,6,5,4,3,2,1,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    //calling of bubble sort function
    bubbleSort(arr,n);
    //printing the sorted array
    for(int i=0;i<n;i++)
        cout<<arr[i]<<", ";
    return 0;
}
