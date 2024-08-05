//Find biggest out of three numbers
#include<stdio_ext.h>
int main()
{
	int a,b,c;
	printf("Enter three numbers the find out biggest\n");
	scanf("%d",&a);
	__fpurge(stdin);
	scanf("%d",&b);
	__fpurge(stdin);
	scanf("%d",&c);
	__fpurge(stdin);
	if(a>b&&a>c)           // if a is greater
		printf("%d is greater",a);
	else if(b>c&&b>a)      //if b is greater
		printf("%d is greater",b);
	else                   // c will be greater
		printf("%d is greater",c);
	return 0;
}
