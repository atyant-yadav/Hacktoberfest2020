#include<stdio.h>
int recursion(int n){
  if(n==0||n==1)
    return 1;
  else
    return n*recursion(n-1);
}
int main(){
  int n, result;
  printf("Enter the number: ");
  scanf("%d", &n);
  result = recursion(n);
  printf("%d \n", result);
}
