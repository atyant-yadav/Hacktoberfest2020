#include <iostream>
using namespace std;

main(){

int c,i,pss;

int array[20]={3,2,4,10,20,1,5,8,7,9,6,5,11,12,14,13,16,15,17,19};

cout<<"Data array : ";

for(i=0;i<20;i++){

cout<<array[i]<<" ";}

cout<<endl;

cout<<endl;
cout<<"Data that will be searched : ";

cin>>c;

i=0;

pss=0;

while(i<19 && array[i]!=c){

i++;}

if (array[i]!=c){

cout<<endl;
cout<<"data not found";

}else if(pss=i+1)

cout<<endl;
cout<<"data found in :"<<pss;

}

