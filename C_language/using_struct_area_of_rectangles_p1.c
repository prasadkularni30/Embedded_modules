/*Q2: Using structure, write a C program to find the area of a given rectangle. Store the
dimensions of rectangle and calculated area in the structure itself. (User Input);*/

#include<stdio.h>

typedef struct AreaofRectangle{
	int lenght;
	int width;
	int area;
}area;

int main()
{
	area a1;

	printf("Lenght of Rectangle in cm: ");
	scanf(" %d",&a1.lenght);
	printf("\nWidth of Rectangle in cm: ");
	scanf(" %d",&a1.width);

	a1.area=a1.lenght*a1.width;
	printf("\nArea of Rectangle= %d",a1.area);

}

