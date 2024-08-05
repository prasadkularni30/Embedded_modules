/*MI Calculator:
Build a program that calculates the Body Mass Index (BMI) 
based on the user's weight and height input. 
Then, categorize the BMI into 
underweight, normal weight, overweight, or obese.

Hint:
BMI = weight / (height * height)
BMI Measurement	Weight Category
Below 18.5	Underweight
18.5 – 24.9	Normal weight
25.0 – 29.9	Overweight
30.0 and above	Obese



1. start
2. read weight and height
3. BMI= weight/(height*height)
4. if BMI<18.5
		print "You are Underweight"
	else if 18.5<=BMI<25
		print"you weight is normal"
	else if 25<=BMI<30
		print"you are overweight"
	else if BMI>30
		print"Obese"
	else 
		print"enter proper height and weight"
5.stop */

#include<stdio.h>
int main()
{ 
double Height, Weight, BMI;

printf("This is BMI calculator\n Please Enter your Height in Meters: ");
scanf("%lf",&Height);
printf(" Please Enter your WEIGHT in KG: ");
scanf("%lf",&Weight);
BMI= Weight/(Height*Height);
if(BMI<18.5)
{ printf("You are Underweight");
}
else if(18.5<=BMI && BMI<25)
{ printf("You weight is Normal");
}
else if(25<=BMI && BMI<30)
{ printf("You are Overweight");
}
else if(BMI>30)
{printf("You have Obese");
}
else
{printf("Please enter proper height and weight");
}
}