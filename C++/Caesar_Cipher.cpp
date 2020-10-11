/*Program to Encrypt and Decrypt a message using the Caesar Cipher 
which is define as "A substitution cipher in which each letter is shifted a certain 
number of places down the alphabet"*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){

  char letter[100], ch;
  int key, op;

  cout << "--MENU--" << endl;
  cout << "1- Encrypt message " << endl;
  cout << "2- Decrypt message " << endl;
  cout << "Option: ";
  cin >> op;

switch(op){
  case 1:
  cout << "Insert text to convert: ";
  cin >> letter;

  cout << "Insert number key: ";
  cin >> key;

  for(int i = 0; letter[i] != 0; i++)
  {
      ch = letter[i];

      if(ch >= 'a' && ch <= 'z'){
          ch += key;

          if(ch > 'z'){
            ch = ch - 'z' + 'a' - 1;
          }
      }
      letter[i] = ch;
  }
  cout << "Encrypted message: " << letter;
  return 0;
  break;

case 2:

cout << "Insert text to decrypt: ";
cin >> letter;

cout << "Insert number key: ";
cin >> key;

for(int j = 0; letter[j] != 0; j++)
{
    ch = letter[j];

    if(ch >= 'a' && ch <= 'z'){
        ch -= key;

        if(ch > 'z'){
          ch = ch + 'z' - 'a' + 1;
        }
      }
      letter[j] = ch;
    }
    cout << "Decrypted message: " << letter;
    return 0;
    break;
  }
}
