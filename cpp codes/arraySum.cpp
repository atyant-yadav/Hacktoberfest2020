#include <iostream>
int RowColSum(float A[4][4]);
using namespace std;

int main()
{   float A[4][4];
    cout<<"Enter array elements :"<<endl;
    for(int i = 0; i<4;i++){
    for(int j = 0; j<4; j++){
    cout<<"\t";
    cin>>A[i][j];
    }
    cout<<endl;
    }
    cout<<"Output : "<<endl;
    RowColSum(A);
    return 0;
}

int RowColSum(float A[4][4]){
int i,j;
float RS[4],CS[4];
//find Row Sum
for(i = 0 ; i<4; i++){
RS[i] = 0;
    for(j = 0;j<4;j++){
    RS[i]+=A[i][j];
    }
}
//find column sum
for(j = 0 ; j<4; j++){
CS[j] = 0;
    for(i = 0;i<4;i++){
    CS[j]+=A[i][j];
    }
}
//display 2d array with rowsum and colsumm

for(i = 0;i<4;i++){
    for(j = 0;j<4;j++)
        cout<<A[i][j]<<"\t";
    cout<<RS[i]<<endl;
}
    for(j = 0;j<4;j++){
       cout<<CS[j]<<"\t";
    cout<<endl;
}
return 0;
