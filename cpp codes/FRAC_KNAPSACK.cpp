#include<iostream>
#include<iomanip>
using namespace std;
int partition (float a[],float p[],float w[], int low, int high)
{
	int i=low;
	int j=high;
	float pivot1= a[low];
	float pivot2= p[low];
	float pivot3= w[low];
	while(i<j)
	{
		while(a[i]<=pivot1 && i<high)
			i++;
		while(a[j]>pivot1 && j>low)
			j--;
		
		if(i<j){					
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
			
			temp=w[i];
			w[i]=w[j];
			w[j]=temp;
		}
	}
	a[low]=a[j];
	a[j]=pivot1;
	
	p[low]=p[j];
	p[j]=pivot2;
	w[low]=w[j];
	w[j]=pivot3;
	return j;
}
void QS (float a[],float p[],float w[], int low, int high)
{
	int partitionIndex;
	if(low < high)
	{
		partitionIndex = partition(a, p, w, low, high);
		QS(a, p, w, low, partitionIndex-1);
		QS(a, p, w, partitionIndex+1, high);
	}
}
int main(){
	int n=4;
	float p[]={320, 150, 120, 120};
	float w[]={40, 10, 20, 50};
	float a[n];
	for(int i=0;i<n;i++){
		a[i]=w[i]/p[i];
	}
	QS(a,p,w,0,n-1);
	float solution[n];
	int m=60;
	cout<<"PROFIT : ";
	for(int i=0;i<n;i++){
		cout<<p[i]<<"  ";
	}
	cout<<endl;
	cout<<"\nWEIGHT : ";
	for(int i=0;i<n;i++){
		cout<<w[i]<<"  ";
	}
	cout<<endl;
	cout<<"\nw/p : ";
	for(int i=0;i<n;i++){
		cout << setprecision(2);
		cout<<a[i]<<"  ";
	}
	cout<<endl;
	
	for(int i=0;i<n;i++){
		solution[i]=0.0;
	}
	int i=0;
	float t=m;
	for(i=0;i<n;i++){
		if(w[i]>t)
			break;
		else{
			solution[i]=1;
			t=t-w[i];
		}
	}
    cout<<endl;
	if(i<n)
		solution[i]=t/w[i];
	cout<<"\nSOLUTION : ";
	for(int i=0;i<n;i++){
		cout<<solution[i]<<"  ";
	}
    cout<<endl<<endl;
}