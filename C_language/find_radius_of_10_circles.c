/*Q8: Using array of structure and loops, write a C program to store radius and area of 10 circles,take
user input to initialize the circles, (make sure that user can see that for which circle he’s entering the
data), at the end display the area of all the circles.
example:

message: ======= Circle 1 =======

Enter Radius:
======= Circle 2 =======
---goes on ---*/


#include<stdio.h>

typedef struct area{
	int radius;
	float area;
}a;

int main(){
	a arr[10];

	for(int i=0;i<10;i++)
	{
		printf("============================================ Circle %d ============================================\n",i+1);
		printf("Enter radius in cm:");
		scanf(" %d",&arr[i].radius);
		printf("\n");

		arr[i].area=3.14*(arr[i].radius*arr[i].radius);
	}

	for(int i=0;i<10;i++)
	{
		printf("============================================ Circle %d ============================================\n",i+1);
		printf("Area: %f\n",arr[i].area);
	}
}

