/* Infix expression to postfix expression.
 * Five operators: (*, /, +, -,^)
 * operands can be of single-digit/Integer/Char operands only. */

#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isdigit(char ) */
#include<string.h>

#define SIZE 100

char stack[SIZE]; /* global Value for stack */
int top = -1;

void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}
char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		/* underflow may occur for invalid expression */
		/* where ( and ) are not matched */
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}
int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' ||symbol=='%'||
	   symbol == '/' || symbol == '+' || symbol =='-') return 1;
	else return 0;
}



int precedence(char symbol)
{
	if(symbol == '^')return(3);
	else if(symbol == '*' || symbol == '/'|| symbol == '%')	return(2);
	else if(symbol == '+' || symbol == '-') return(1);
	else return(0);
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
	int i, j;
	char item;
	char x;
	push('(');                /* push '(' onto stack */
	strcat(infix_exp,")");    /* add ')' to infix expression */
	i=0;
	j=0;
	item=infix_exp[i];         /* initialize before loop*/

	while(item != '\0')        /* run loop till end of infix expression */
	{
		if(item == '(')	push(item);
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item; /* add operand symbol to postfix expr */
			j++;
		}
		else if(is_operator(item) == 1) /* means symbol is operator */
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x; /* pop all higher precendence operator and */
				j++;
				x = pop();       /* add them to postfix expresion */
			}
			push(x);
			/* because just above while loop will terminate we have popped one extra itemfor which condition fails and loop terminates, so that one*/
			push(item);     /* push current operator symbol onto stack */
		}
		else if(item == ')')    /* if current symbol is ')' then */
		{
			x = pop();                   /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{    /* if current symbol is not operand or operator */
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}
		i++;
		item = infix_exp[i]; /* go to next symbol of infix expression */
	} /* while loop ends here */
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}
	postfix_exp[j] = '\0'; /* add sentinel else puts() fucntion */

}
int main()
{
	char infix[SIZE], postfix[SIZE];
	printf("\nEnter Infix expression Single digit/char operand: ");
	gets(infix);

	InfixToPostfix(infix,postfix);
	printf("Postfix Expression: ");
	puts(postfix);
	return 0;
}
