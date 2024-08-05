//swap two variables without using thried variable
#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter two numbers to swap\n");
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	// consider a=10 b=20
	a=a+b;// a=30
	b=a-b;// b=10 (a)
	a=a-b;// a=20 (b)
	printf("After swapping\n");
	printf("a=%d\nb=%d",a,b);
	return 0;
}
