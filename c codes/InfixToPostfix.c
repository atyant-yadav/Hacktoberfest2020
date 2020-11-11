#include <stdio.h>
#include <ctype.h>
//code
char s[100],infix[100],postfix[100];
int final=1;
int top=-1;
void push(char ch){
  s[top+1]=ch;
  top++;
}
char pop(){
  if(top<0)
  {
    printf("\ncannot pop from empty stack\n");
    return '\0';
  }
  return s[top--];
}
int isOperator(char ch){
  if(ch=='+' || ch=='-' || ch=='*' || ch=='/'  )
    return 1;
  else
    return 0;
}
int prefunc(char ch){
  if(ch=='*' || ch=='/')
   return 3;
  else if(ch=='+' || ch=='-')
   return 2;
  else if(ch=='(' )
   return 1;
}
void postmake(){
  int i=0,k=0;
  while(infix[i]!='\0'){
    char ch=infix[i];
    if(ch=='('){
      push(ch);
    }
    else if(isalnum(ch))
    {
      postfix[k++]=ch;
    }
    else if(ch==')')
    {
      if(top==-1){
        final=0;
        break;
      }
      else{
      while(s[top]!='('){
        postfix[k++]=pop();
        if(top==-1){
          final=0;
          break;
        }
      }
      pop();
      }
    }
    else if(isOperator(ch)==1){
      if(top!=-1){
        while(prefunc(ch)<=prefunc(s[top])){
            postfix[k++]=pop();
            if(top==-1)
            break;
        }
      }
      push(ch);
    }
    else{
      final=0;
      break;
    }
    i++;
  }
  if(!isalnum(infix[i-1]) && infix[i-1]!=')' ){
    final=0;
    return;
  }
  while(top!=-1)
  {
    if(s[top]=='(')
    {
      final=0;
      break;
    }
    postfix[k++]=pop();
  }
  postfix[k]='\0';
}
int main(){
  printf("enter the expression : ");
  scanf("%s",infix);
  postmake();
  if(final)
    printf(" the postfix expression : %s",postfix);
  else
    printf("\nwrong expression\n");
  return 0;
}
