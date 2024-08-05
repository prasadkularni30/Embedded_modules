/*Q4: Using structures in C, write a program to find the area of a given rectangle, and store the
dimensions and result in the structure data member. Make sure to use another function for
the calculation of area (passing structure variable to a function).*/

#include<stdio.h>

typedef struct AreaofRectangle{
	int lenght;
	int width;
	int area;
}area;

void Area_of_rect(area *);
int main()
{
	area a1;
	area *p;
	p=&a1;

	printf("Lenght of Rectangle in cm: ");
	scanf(" %d",&a1.lenght);
	printf("\nWidth of Rectangle in cm: ");
	scanf(" %d",&a1.width);

	Area_of_rect(p);


}

void Area_of_rect(area *a1)
{

	a1->area=a1->lenght*a1->width;
	printf("\nArea of Rectangle= %d",a1->area);
}

