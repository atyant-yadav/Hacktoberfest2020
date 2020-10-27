/*
Computer Graphics and Design
Homework 1
Tushar Tyagi	-	B17106
Aman Saxena		-	B17034
*/

//This program can handle lines of any slope.//

/*
Bresenham's Algorithm:
Case 1:
for m > 0 & m<1
//pk=dx*(d1-d1) to decide xk+1 and yk+1

initial pk= 2*dy - dx
pk+1 = pk + 2*dy - 2*dx*(yk+1 - yk)

if pk>=0 : xk+1 = xk + 1, yk+1 = yk + 1
else: xK+1 = xK + 1, yk+1 = yk

Case2:
for m=>1:
pk + 1 = pk + 2dx − 2dy((xk+1) − xk)
p0 = 2dx − dy

if pk>=0:	xk+1 = xk + 1, yk+1 = yk + 1
else:		xk+1 = xk, yk+1 = yk + 1

Case3:
for m<0 & m>-1:
same as case 1, x1 to x2 where x2 < x1

case4:
p is negetive of that of case 2
m<=-1
same as case 3, but has to decrease x.


*/

#include <bits/stdc++.h>
#include "EasyBMP.cpp"

using namespace std;

void swap(float &i, float &j);
float slope(float x1,float y1, float x2, float y2);
void toWhite(BMP &bm, int x, int y);
void drawLine(float x1,float y1, float x2, float y2, char* fileNameToSaveBitmap);

int main(){
cout<<"In EasyBMP, positive axis is downwards\n"<<endl;

float x1,x2,y1,y2;
char* fileName;
	cout<<"Enter the Coordinates of first point: ";
	cin>>x1>>y1;
	cout<<"Enter the Coordinates of second point: ";
	cin>>x2>>y2;
	cout<<"Enter the file name to be saved: ";
	cin>>fileName;

	drawLine(x1,y1,x2,y2,fileName);

	return 0;
}

void drawLine(float x1, float y1, float x2, float y2, char* fileNameToSaveBitmap){

	//Input check:
	if(x1<0 || x2<0 || y1<0 || y2<0 || x1>100 || x2>100 || y1>100|| y2>100){
		cout<<"Coordinates out of bound, please enter Coordinates between 0 and 100 [included]"<<endl;
		return;
	}

	if(y2<y1){
		swap(x1,x2);	swap(y1,y2);
	}

	BMP bm;
	bm.SetSize(101, 101);


	if(y2==y1){
		if(x1<x2){
		for(int x=x1; x<=x2; ++x)	toWhite(bm,x,y1);
		bm.WriteToFile(fileNameToSaveBitmap);
		}
	else{
		for(int x=x1; x>=x2; --x)	toWhite(bm,x,y1);
		bm.WriteToFile(fileNameToSaveBitmap);}
	return;
	}

	
	if(x2==x1){
		for(int y=y1; y<=y2; ++y) toWhite(bm,x1,y);
			bm.WriteToFile(fileNameToSaveBitmap);
			return;
	}

	float m=slope(x1,y1,x2,y2);

	cout<<m<<endl;

	if(m>0 && m<1){
		cout<<"case1"<<endl;
		int p= 2*(y2-y1) - (x2-x1);
		toWhite(bm,x1,y1);
		int yk=y1;
		int yk1=0;

		for(int x=x1; x<x2; ++x){
			if(p>=0){ yk1=yk+1;
			}
			else{
				 yk1=yk;
			}

			toWhite(bm,x+1,yk1);

			p+=2*(y2-y1) -2*(x2-x1)*(yk1-yk);
			yk=yk1;
		}
	}


	else if(m>=1){
		cout<<"case 2"<<endl;
		int p=2*(x2-x1)-(y2-y1);
		toWhite(bm,x1,y1);
		int xk=x1;
		int xk1=0;

		for(int y=y1; y<y2; ++y){
			if(p>=0){
				xk1=xk+1;
			}
			else xk1=xk;

			toWhite(bm,xk1,y+1);
			p+=2*(x2-x1) - 2*(y2-y1)*(xk1-xk);
			xk=xk1;
		}
	}
	else if(m<0 && m>-1){
		cout<<"case3"<<endl;
		int p= 2*(y2-y1) - (x2-x1);
		toWhite(bm,x1,y1);
		int yk=y1;
		int yk1=0;

		for(int x=x1; x>x2; --x){
			if(p>=0)	yk1=yk+1;
			else		yk1=yk;

			toWhite(bm,x-1,yk1);
			p+=2*(y2-y1) -2*(x2-x1)*(yk1-yk);
			yk=yk1;
		}
	}
	else{
		cout<<"case4"<<endl;
		int p=2*(x2-x1)-(y2-y1);
		cout<<"p:"<<p<<endl;
		toWhite(bm,x1,y1);
		int xk=x1;
		int xk1=0;

		for(int y=y1; y<y2; ++y){
			if(p<0){
				xk1=xk-1;
			}
			else xk1=xk;

				toWhite(bm,xk1,y+1);
			p+=2*(x2-x1) - 2*(y2-y1)*(xk1-xk);
			xk=xk1;
		}
	}

	bm.WriteToFile(fileNameToSaveBitmap);
			return;
}

void swap(float &i, float &j){
	float temp=i;
	i=j;
	j=temp;
}

float slope(float x1,float y1, float x2, float y2){
	float m=(y2-y1)/(x2-x1);
	return m;
}

void toWhite(BMP &bm,int x, int y){
	cout<<"to white "<<x<<" "<<y<<endl;

	bm(x,y)->Red=0;
	bm(x,y)->Green=0;
	bm(x,y)->Blue=0;
}