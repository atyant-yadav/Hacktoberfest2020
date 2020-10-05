/*
 * Autor: EnryBarto GitHub: https://github.com/EnryBarto
 * Date: 05/09/2020 dd/mm/yyyy
 * Relase: 1
 */


#include <stdio.h>
#include <stdlib.h>

float a;
float b;
float result;
int operator;

void main(){
	printf("CALCULATOR IN C - by EnryBarto:\n\n");

	printf("Insert the first number: ");
	scanf("%f",&a);

	printf("Insert the second number: ");
	scanf("%f",&b);

	printf("\nInsert: 1 - to do a sum;\nInsert: 2 - to do a subtraction;\nInsert: 3 - to do a multiplication;\nInsert: 4 - to do a division.\nInsert operator: ");
	scanf("%d",&operator);
	printf("\n");

	if (operator == 1){
		result = a + b;
		printf("Result: %f \n", result);
	} else if (operator == 2){
		result = a - b;
		printf("Result: %f \n", result);
	} else if (operator == 3){
		result = a * b;
		printf("Result: %f \n", result);
	} else if (operator == 4){
		if (b != 0){
			result = a / b;
			printf("Result: %f \n", result);
		} else if (b == 0){
			if (a != 0){
				printf("Can't divide by 0\n");
			} else if (a == 0){ 
				printf("Undefined\n");
			}
		}	
	} 
}
