/*(with or without loop)
Q3: Using array of structure, write a C program to find the area of 3 rectangles. Store the
dimensions of rectangle and calculated area in the structure itself. (User Input);*/

#include<stdio.h>

typedef struct AreaofRectangle{
	int lenght;
	int width;
	int area;
}area;

int main()
{
	area arr[3];

	for(int i=0;i<3;i++)
	{
	printf("Lenght of Rectangle %d in cm: ",i+1);
	scanf(" %d",&arr[i].lenght);
	printf("Width of Rectangle %d in cm: ",i+1);
	scanf(" %d",&arr[i].width);
	printf("\n");


	arr[i].area=arr[i].lenght*arr[i].width;
	}


	for(int i=0;i<3;i++)
	printf("\nArea of Rectangle= %d\n",arr[i].area);

}

