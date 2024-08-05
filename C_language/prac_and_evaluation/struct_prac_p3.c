/*Q2: Given the address of a member variable in a structure find the base address of it.
For eg:- struct A {
int x;
double y;
float z;
char ch;
} a1;

given address of any member x, y, z or ch , find address(base) of a1.
How will you do that, try finding the address of a1. Print to verify the same.*/


#include<stdio.h>

struct A{
	int x;
	double y;
	float z;
	char ch;
}a1;

int main()
{
	printf("&a1= %p ",&a1);
	printf("&a1.x=%p ",&a1.x);
	printf("&a1.y=%p ",&a1.y);
	printf("&a1.z=%p ",&a1.z);
	printf("&a1.ch=%p\n ",&a1.ch);
	printf("&a1+1=%p\n ",&a1+1);
	
	printf("\nsize\n");
	printf("a1=%d ",sizeof(a1));
	printf("a1.x=%d ",sizeof(a1.x));
	printf("a1.y=%d ",sizeof(a1.y));
	printf("a1.z=%d ",sizeof(a1.z));
	printf("a1.ch=%d ",sizeof(a1.ch));

	float *p;
	p=&a1.z;
	printf("\n");
	printf("by ptr &a1.y=%p\n ",p-2);
	printf("by ptr &a1.x=%p\n ",p-4);
	printf("by ptr &a1.ch=%p\n ",p+1);



}

