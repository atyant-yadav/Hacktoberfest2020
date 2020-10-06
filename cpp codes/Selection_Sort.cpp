#include <iostream>
#include <algorithm>
using namespace std;

void selectionSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIdx=i;
        for(int j=minIdx+1;j<n;j++)
        {
            if(arr[j]<arr[minIdx])
                minIdx=j;
        }
        swap(arr[i],arr[minIdx]);
    }
}

int main() {

    int arr[] {99,10,9,8,7,6,5,4,3,2,1,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<",";
    return 0;
}