#include<stdio.h>
int main()
{
	int a,b,c;
	printf("enter 3 numbers\n");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);

	(a>b&&a>c)?printf("%d is greater",a):((b>c&&b>a)?printf("%d is greater",b):printf("%d is greater",c));

}
