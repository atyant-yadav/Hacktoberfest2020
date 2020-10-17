#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// Intilizing the header file and std type


//Main function
int main()
{
    int sum; // integer variable sum
    cin>>sum;. // Taking the input as sum
    int m; // integer variable m

    cin>>m; // taking the input of m
    int coins[m]; // selecting the m element in integer
    for(int i=0;i<m;i++) //taking the input as looping order 
    cin>>coins[i];
    int arr[m+1][sum+1]; // incrementing the m variable and sum variable
    for(int i=1;i<=sum;i++)
    {
        arr[0][i]=0; // selecting element in array
    }
    for(int i=0;i<=m;i++) // looping throw the array and declare I variable
    {
        arr[i][0]=1;
    }
    for(int i=1;i<=m;i++) // looping through the array again for sum 
    {
        for(int j=1;j<=sum;j++) // comparing sum and incrementing the sum
        {
            if(j>=coins[i-1]) // comparing the j variable and I variable
            arr[i][j]=arr[i-1][j]+arr[i][j-coins[i-1]]; // swapping and incrementing the value
            else
            arr[i][j]=arr[i-1][j];
        }
    }
    cout<<arr[m][sum]<<endl; // printing the answer
}
