Minimum bracket Reversal
Send Feedback
Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals which are required to make the expression balanced.
Return -1 if the given expression can't be balanced.
Input Format :
String S
Output Format :
Required count
Sample Input 1 :
{{{
Sample Output 1 :
-1
Sample Input 2 :
{{{{}}
Sample Output 2 :
1



				PRACTICE

int countBracketReversals(char input[]){
	// Write your code here

}


				SOLUTION


#include<stack>
int countBracketReversals(char input[]){
	int count=0;
    stack<char> s;
    int i=0;
    while(input[i]!='\0')
    {
        if(input[i]=='{')
        {
            s.push(input[i]);
        }
        else if(input[i]=='}' && !s.empty())
            
        {
            if(s.top()=='{')
            s.pop();
            else
            {
                s.push(input[i]);
            }
        }
        else if(input[i]=='}' && s.empty())
        {
            s.push(input[i]);
        }
        i++;
    }
    int a=s.size();
    if(a%2!=0)
    {
        return -1;
    }
    while(s.size()!=0)
    {
        char c1=s.top();
        s.pop();
        char c2=s.top();
        s.pop();
        if(c1==c2)
        {
            count=count+1;
        }
        else
        {
            count+=2;
        }
    }
    
    return count;

}


#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}
