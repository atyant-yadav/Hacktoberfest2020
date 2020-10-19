#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 void main()
{
    int X,Y,x,y,a,b,r;
    printf("*C program to find a Point lies Inside/Outside the Circle OR lies on the Circle.\n\nX-coordinate of centre of circle: ");
    scanf("%d",&a);
	printf("Y-coordinate of centre of circle: ");
	scanf("%d",&b);
	printf("Radius of the circle: ");
	scanf("%d",&r);
	printf("X-coordinate of the point: ");
	scanf("%d",&x);
	printf("Y-coordinate of the point: ");
    scanf("%d",&y);
    X=pow((x-a),2);
    Y=pow((y-b),2);
    if((X+Y)<(r*r))
        printf("The point (%d,%d) lies inside of the circle.",x,y);
    else
        if((X+Y)>(r*r))
        printf("The point (%d,%d) lies outside of the circle.",x,y);
    else
        if((X+Y)==(r*r))
        printf("The point (%d,%d) lies on the circle.",x,y);
}
