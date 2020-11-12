#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])

{
	float C;
	float F;

	printf("Enter a degree of Centigrade: ");
	scanf("%f", &C);
	
	F=(C * 9.0/5.0)+32.0;	
	
	printf("Centigrade = %f Fahrenheit",F);

	return 0;
}
