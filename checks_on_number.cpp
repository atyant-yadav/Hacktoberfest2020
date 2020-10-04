#include "bits/stdc++.h"
using namespace std;

bool prime_check(long int n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  	if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  	for (long int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  	return true; 
}
void composite_check(long int n,int flag)
{
	if(n==1)
	{
		if(flag)
			cout<<"Number is not Composite\n";
		else
			cout<<"Number is not Prime\n";
		return;
	}
	if(prime_check(n))
		if(!flag)
			cout<<"Number is Prime\n";
		else
			cout<<"Number is not Composite\n";
	else
		if(!flag)
			cout<<"Number is not Prime\n";
		else
			cout<<"Number is Composite\n";
}
void palindrome_check(long int n)
{
	long int r=0,m=n;
	int d=0;
	while(m)
	{
		d=m%10;
		r=r*10+d;
		m/=10;
	}
	if(r==n)
		cout<<"Number is Palindrome\n";
	else
		cout<<"Number is not Palindrome\n";
}
void pSquare_check(long int n)
{
	long int r=sqrt(n);
	if(r*r==n)
		cout<<"Number is Perfect Square\n";
	else
		cout<<"Number is not Perfect Square\n";
}
int main() 
{
	int option;
	long int n;
	cout<<"Please choose one of the following options-\n";
	cout<<"Enter 1 to check if Number is Palindrome\n";
	cout<<"Enter 2 to check if Number is Prime\n";
	cout<<"Enter 3 to check if Number is Composite\n";
	cout<<"Enter 4 to check if Number is Perfect Square\n";
	cin>>option;
	cout<<endl;
	while(option<1||option>4)
	{
		cout<<"Please Enter Valid Option\n";
		cout<<"Please choose one of the following options-\n";
		cout<<"Enter 1 to check if Number is Palindrome\n";
		cout<<"Enter 2 to check if Number is Prime\n";
		cout<<"Enter 3 to check if Number is Composite\n";
		cout<<"Enter 4 to check if Number is Perfect Square\n";
		cin>>option;
		cout<<endl;
	}
	cout<<"Enter the Number on which the check is to be performed\n";
	cin>>n;
	cout<<endl;
	switch(option)
	{
		case 1:palindrome_check(n);
		break;
		case 2:composite_check(n,0);
		break;
		case 3:composite_check(n,1);
		break;
		case 4:pSquare_check(n);
		break;
	}

}
 