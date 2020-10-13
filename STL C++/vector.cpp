//vectors are dynamic array templates
//here template mean that they are defined for all data types

#include<iostream>
#include<vector>//header file for vectors
using namespace std;
int main()
{
vector<int> v1;    //a simple vector aka dynamic array of integer datatype
int n=10;
vector<int> v2(n,10);  //v2 will be of size n and will have all values initialised as 10
//intialisze a vector
vector<int> v3 {12,13,14,15};
//printing the values in the vector using for loop
for(int x:v3)
cout<<x<<" ";
cout<<endl;
//output willbe - 12 13 14 15
//way2 of initializing ie using an array
int a[]={12,15,16};
int sizeofa = sizeof(a)/sizeof(int);
vector <int> v4(a,a+sizeofa);
//printing the values in the vector  v4 using for loop
for(int x:v4)
cout<<x<<" ";
cout<<endl;
//output - 12 15 16
//way3 with the help of another vector
vector v5(v3.begin(),v3.end());// v3.begin() here begin() is a function which gives an iterator to beginning of the vector and end() gives an iterator to next location after the last element of vector
//printing the values in the vector using for loop
for(int x:v5)
cout<<x<<" ";
cout<<endl;
//output willbe - 12 13 14 15
//way 4 using push_back()
//push back function simply pushes the value to the vector 
v5.push_back(4);
v5.push_back(2);
v5.push_back(1);
v5.push_back(9);
//printing the values in the vector using for loop
for(int x:v5)
cout<<x<<" ";
cout<<endl;
//output willbe - 12 13 14 15 4 2 1 9
//way5 using fill();
vector<int>  v6(9);
fill(v6.begin(),v6.begin(),10);
//fill () will initilaize all 9 values of v6 with 10
//thank you
return 0;

}
