#include <stdio.h>
#include <stdlib.h>

float sum(float,float);
float sub(float,float);
float mul(float,float);
float divi(float,float);
 int opera();
 int opera(){ int op;
 printf("Calculator Menu\n");
printf("Enter 1,2,3,4,5.\n 1 - Addition\n 2 - Substraction\n 3 - Multiplication\n 4 - Division\n 5 - Exit\n");
scanf("%d",&op);

return op;

}
float sum(float x,float y)
{
float sum= x+y;
printf("Result = %.2f\n",sum);
}

float divi(float x,float y){
float result;
result = (x/y)*1.0;
printf("Result = %.2f\n",result);
}

float sub(float x,float y)
{
float sub = x-y;
printf("Result = %.2f\n",sub);
}


float mul(float x,float y){
float mul = x*y;
printf("Result = %.2f\n",&mul);

}

int main()
{

float a,b;
int op;
op = opera();

while(op!= 5){
printf("Enter First NO.");
scanf("%f",&a);
printf("Enter Second NO.");
scanf("%f",&b);
switch(op){
case 1 : sum(a,b);
break;
case 2 : sub(a,b);
break;
case 3 : mul(a,b);
break;
case 4 : divi(a,b);
break;
default : printf("Wrong Input");};

op = opera();
}
    return 0;
}
