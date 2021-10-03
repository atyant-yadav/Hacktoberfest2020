#include <iostream>
using namespace std;

int main()
{
    int i, fact = 1, number;
    cout << "Enter any Number: ";
    cin >> number;
    if (number == 0)
        cout << "Factorial of 0 is always 1";
    else if (number < 0)
        cout << "Factorial of negative number does not exist";

    else
        for (i = 1; i <= number; i++)
        {
            fact = fact * i;
        }
    cout << "Factorial of " << number << " is: " << fact << endl;

    return 0;
}