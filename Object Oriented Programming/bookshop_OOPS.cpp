#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class book	{
private:
	char *author,*title,*publisher;
	float *price;
	int *stock;
	void editprice(){
		cout<<"\nEnter the new details: ";
		cout<<"\nEnter Author Name: ";    cin.getline(author,20);
		cout<<"Enter Title Name: ";       cin.getline(title,20);
		cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
		cout<<"Enter Price: ";            cin>>*price;
		cout<<"Enter number of copies: "; cin>>*stock;   
	}
public:	
	book()	{
	author= new char[20];
	title=new char[20];
	publisher=new char[20];
	price= new float;
	stock=new int;
	}
	void feeddata();
	void editdata();
	void showdata();
	int search(char[],char[]);
	void buybook();
	
	// static data members
	static int successful_tran_count;
	static int unsuccessful_tran_count;
	
	// static member funcction
	static int getCount() {
         cout<<"\nSuccessful transactions : "<<successful_tran_count;
         cout<<"\nUnsuccessful transactions : "<<unsuccessful_tran_count;
         cout<<endl;
      }
	
};

// initializing static counters
int book::successful_tran_count=0;
int book::unsuccessful_tran_count=0;


void book::feeddata()	{
	cin.ignore();
	cout<<"\nEnter Author Name: ";    cin.getline(author,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Number of copies: ";   cin>>*stock;   
	
}

void book::editdata()	{
	
	editprice(); // private member function of class book to change price
}

void book::showdata()	{
	cout<<"\nAuthor Name: "<<author;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nPublisher Name: "<<publisher;
	cout<<"\nPrice: "<<*price;
	cout<<"\nNumber of copies available: "<<*stock;   
	
}

int book::search(char tbuy[20],char abuy[20] )	{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return 1;
	else return 0;
		
}

void book::buybook()	{
	int count;
	cout<<"\nEnter Number Of Books to buy: ";
	cin>>count;
	if(count<=*stock)	{
		*stock=*stock-count;
		cout<<"\nBooks Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(*price)*count;
		successful_tran_count++;
	}
	else
	{
		cout<<"\nRequired Copies not in Stock";
		unsuccessful_tran_count++;
	}
		
}

int main()	{
	book *B[20];
	int i=0,r,t,choice;
	char titlebuy[20],authorbuy[20];
	cout<<"\tWELCOME USER\n";
	while(1)	
	{
		cout<<"\n\nCHOOSE YOUR OPTION\n";
		cout<<"\n1. Entry of New Book";
		cout<<"\n2. Buy Book";
		cout<<"\n3. Search For Book";
		cout<<"\n4. Edit Details Of Book";
		cout<<"\n5. Transactions details";
		cout<<"\n6. Exit";
		cout<<"\n\nEnter your Choice: ";
		cin>>choice;
		
		switch(choice)
		{
		case 1:	
		B[i] = new book;
		B[i]->feeddata();
		i++;	break;
				
		case 2: 
		cin.ignore();
		cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
		cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
		for(t=0;t<i;t++)
		{
			if(B[t]->search(titlebuy,authorbuy))
			{
			B[t]->buybook();
			break;
			}
		}
		if(t==i)
		cout<<"\nThis Book is Not in Stock";
				
		break;
		
		case 3: cin.ignore();
		cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
		cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				
		for(t=0;t<i;t++)
		{
			if(B[t]->search(titlebuy,authorbuy))
			{
			cout<<"\nBook Found Successfully";
			B[t]->showdata();
			break;
			}
		}
		if(t==i)
		cout<<"\nThis Book is Not in Stock";
		break;
			
    	case 4: cin.ignore();
		cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
		cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				
		for(t=0;t<i;t++)
		{
			if(B[t]->search(titlebuy,authorbuy))
			{
			cout<<"\nBook Found Successfully";
			B[t]->editdata();
			break;
			}
		}
		if(t==i)
		cout<<"\nThis Book is Not in Stock";
		break;
		
		case 5: cin.ignore();
		{
			book::getCount();  //accessing static member function using class name
			break;
		}
			
		case 6: exit(0);
		default: cout<<"\nChoice Entered is Incorrect";
			
		}
	}
	
	return 0;
}
