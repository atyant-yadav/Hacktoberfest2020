#include<iostream>
#include "ClientA.h"

using namespace std;
int main()
{
	extern int answer;
	int choice;
	double a, b;
	cout << "Press \n 1.Addition \n 2.Subtraction \n 3.Division \n 4.Multiplication \n 5.Modulus \n 6.Power \n 7.Square Root \n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "Enter two numbers(separated by space)\t";
		cin >> a >> b;
		Add(a, b);
		cout << "The sum is equal to " << answer;
		break;
	}
	case 2:
	{
		cout << "Enter two numbers(separated by space)\t";
		cin >> a >> b;
		Subtract(a, b);
		cout << "The difference is equal to " << answer;
		break;
	}
	case 3:
	{
		cout << "Enter two numbers(separated by space)\t";
		cin >> a >> b;
		Divide(a, b);
		cout << "The division is equal to " << answer;
		break;
	}
	case 4:
	{
		cout << "Enter two numbers(separated by space)\t";
		cin >> a >> b;
		Multiply(a, b);
		cout << "The multiplication is equal to " << answer;
		break;
	}
	case 5:
	{
		cout << "Enter two numbers(separated by space)\t";
		cin >> a >> b;
		takeMod(a, b);
		cout << "The Modulus is equal to " << answer;
		break;
	}
	case 6:
	{
		cout << "Enter two numbers(separated by space)\t";
		cin >> a >> b;
		takePower(a, b);
		cout << "The Power is equal to " << answer;
		break;
	}
	case 7:
	{
		cout << "Enter a number\t";
		cin >> a;
		takeSquareRoot(a);
		cout << "The square root is equal to " << answer;
		break;
	}
	
	default:
		cout << "Kindly choose from above.";
	}
}