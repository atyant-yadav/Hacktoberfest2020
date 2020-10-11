/*Iterative binary search algorithm*/ 
/*It is a divide and conquer algorithm that finds the
index of an element in a sorted array in O(log(N)).*/ 

#include <iostream>

using namespace std;

// This function returns the index of the element.
int binarySearch(int arr[], int length, int value)
{
    int left = 0, right = length-1, middle;
    //Break when the left bound is bigger than the right.
    while (right >= left)
    {
        //Get the middle of the array
        middle = (left + right)/2;
        
        //If the required value is smaller than the middle
        if (arr[middle] > value)
            //Work on the left part of the array
            right = middle-1;
        
        //If the required value is bigger than the middle
        else if (arr[middle] < value)
            //Work on the right part of the array
            left = middle+1;
        
        //Else: the element is found
        else return middle;
    }
    //The element doesn't exist.
    return -1;
}

int main()
{
    int arr[] = {120, 230, 250, 370, 400, 500};
    cout << binarySearch(arr, 6, 120) << endl;
    cout << binarySearch(arr, 6, 250) << endl;
    cout << binarySearch(arr, 6, 400) << endl;
    cout << binarySearch(arr, 6, 230) << endl;
    cout << binarySearch(arr, 6, 500) << endl;
}

