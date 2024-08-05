/*Display the area and perimeter of a rectangle, take required input from user?
Hint : 
Area = width * height
Perimeter = 2 * ( width + height)*/

#include<stdio.h>
int main()
{
	float Area, Parameter, H, W;
	printf("*Note Unit of Height and Widht should be same*\n");
	printf("Enter the Height(lenght) of rectangle:\n");
	scanf("%f",&H);
	printf("Enter Widht of rectangle:\n");
	scanf("%f",&W);
	
	Area= H*W;
	Parameter= 2*H*W;
	
	printf("Area of Rectangle is %0.2f\n",Area);
	printf("Parameter of rectangle is %0.2f\n",Parameter);
}