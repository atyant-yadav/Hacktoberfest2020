/**********************************************************************
 * a program to print out the multiplication table.
 **********************************************************************/

#include <stdio.h>

void print_tables (int max_limit)
{
	int x_axis;                 /* x-axis of the table */
	int y_axis;                 /* y-axis of the table */

	printf("\n    ");
	for (x_axis = 1; x_axis <= max_limit; ++x_axis) 
	{
		printf("%4d", x_axis);
	}
	printf("\n");
	printf("   +-----------------------------------------------\n");

	for (y_axis = 1; y_axis <= max_limit; ++y_axis) 
	{
		printf("%2d |", y_axis);

		for (x_axis = 1; x_axis <= max_limit; ++x_axis) 
		{
		    printf("%4d", x_axis * y_axis);
		}
		printf("\n");
	}

}


int main(void) 
{
	int max;

	printf ("Key in the higher limit:");
	scanf ("%d", &max);
	print_tables (max);
	return 0;
}
