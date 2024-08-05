#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter two numbers:\n");
	scanf("%d",&a);
	scanf("%d",&b);

	printf("before swapping: a=%d b=%d\n",a,b);
	a=a^b;b=a^b;a=b^a;
	printf("after swapping: a=%d b=%d",a,b);
	return 0;
}

