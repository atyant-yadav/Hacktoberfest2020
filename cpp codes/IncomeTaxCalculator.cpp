/* Calculate your Income tax as per current Indian tax slabs under the NEW tax regime for FY 2020-21 */

#include <iostream>
using namespace std;

int main()
{

double income,tax,cess,surchrg;

cout << "Enter Income: ";
cin >> income;

// Tax brackets

if(income<=250000.00)
{tax=0;}

else if (250000.00<income && income<=500000.00)
{tax=(income-250000.00)*0.05;}

else if (500000.00<income && income<=750000.00)
{tax=(income-500000.00)*0.10 + 12500;}

else if (750000.00<income && income<=1000000.00)
{tax=(income-750000.00)*0.15 + 12500 + 25000;}

else if (1000000.00<income && income <=1250000.00)
{tax=(income-1000000.00)*0.20 + 12500 + 25000 + 37500;}

else if (1250000.00<income && income<=1500000.00)
{tax=(income-1250000.00)*0.25 + 12500 + 25000 + 37500 + 50000;}

else 
{tax=(income-1500000.00)*0.30 + 12500 + 25000 + 37500 + 50000 + 62500;}
 

// Surcharge

if (10000000>income && income>5000000.00)
surchrg=income*0.10;

if (20000000>income && income>10000000.00)
surchrg=income*0.15;

if (50000000>income && income>20000000.00)
surchrg=income*0.25;

if (income>50000000.00)
surchrg=income*0.37;

else
surchrg=0;

cess = tax*0.04;

 
cout<<"Income = "<<income<<"\n";
cout<<"TAX = "<<tax<<"\n";
cout<<"Cess = " << cess << "\n";
cout<<"Surcharge = "<<surchrg<<"\n";
cout<<"Total TAX Liability = " << tax + cess + surchrg<< "\n";


return 0;
}
