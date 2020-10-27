// Thanks 🇸 ♻️ ♏ 🌱 🇦 for helping
/* Simple output
   9 => 1 num
   9 => 2 num
   + => char
*/

#include <iostream>
using namespace std;

int main()
{
    float a;
    cin >> a;
    float b;
    cin >> b;
    char c;
    cin >> c;
    switch (c) {
        case '+':
            cout << a + b;
            break;
        case '-':
            cout << a - b;
            break;
        case '*':
            cout << a * b;
            break;
        case '/':
        if(b == 0) {
            cout << "Can't divide by 0"; 
       } else {
           cout << a / b;
       }
    };
    return 0;
}
