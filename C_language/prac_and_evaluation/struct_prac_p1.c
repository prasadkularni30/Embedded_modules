/*Q1: Write a C program to create a structure named “addition”, with 3 data members, num1,
num2 and sum of type int.
Taking user input, initialize the num1 and num2 and then store the result of num1+ num2 in
the sum data member;*/

#include<stdio.h>

typedef struct addition{
	int num1;
	int num2;
	int sum;
}add;

int main()
{

	add b1;

	printf("Num1: ");
	scanf(" %d",&b1.num1);
	printf("\nNum2: ");
	scanf(" %d",&b1.num2);

	b1.sum=b1.num1+b1.num2;
	printf("\nSum= %d",b1.sum);

}

