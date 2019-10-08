//Program to perform linear search on an array and print the index of first occurrence of the searched element

#include <iostream>
using namespace std;

int main()
{
   int n,s,i,A[1000];         //Assuming max size of array is 1000
   cout<<"Enter the no of elements";
   cin>>n;
   
   cout<<"Enter the elements";
   for(i=0;i<n;i++)
   {
       cin>>A[i];
       i++;
   }
   
   cout<<"Enter the element that you want to search";
   cin>>s;
   
   i=0;
   while(i<n)
   {
       if(A[i]==s)         //If current element of array is equal to the no that 
       break;             //we are searching, we can stop the searching process
       i++;
   }
   if(i<n)
   {
       cout<<"Element found at index"<<i;
   }
   else
   cout<<"Element is not present in the array";
   return 0;
}
