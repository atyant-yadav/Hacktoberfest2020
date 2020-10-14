/A program to illustrate the STL container for linked lists

#include <iostream>
#include <list>
using namespace std;

int main( )
{
list<int> intlist;
list<int>::iterator ptr;
int i;

//checking whether the list is empty
if (intlist.empty( )= =true)
{
cout<<endl<<"The list is empty";
}

//adding 5 values to the list (0 1 2 3 4)
for( i = 0; i<5; i++)
{
intlist.push_back( i );
}

//adding another element (4) to the list
intlist.push_back(4);

//initializing the iterator to the first node
//displaying the value held in the first node

ptr=intlist.begin( );
cout<<endl<<"First element has value: "<<*ptr;

//traversing through the list by incrementing the iterator
cout<<endl<<"Initial list contents are : ";
for (i = 0; ptr != intlist.end( ); i++)
{
cout<<" "<<*ptr; //displaying the value at that node
ptr++;
}

//removing duplicate elements from the list
intlist.unique( );

cout<<endl<<"Modified list contents are: ";
ptr = intlist.begin( );
for (i=0; ptr!=intlist.end( ); i++)
{
cout<<" "<<*ptr;
ptr++;
}

return 0;
}
