#include <iostream>
#include <algorithm>

using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

int main() {

    int arr[] {99,10,9,8,7,6,5,4,3,2,1,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<",";
    return 0;
}