#include<stdio.h>
int main()
{
	int a,b,c,d;

	a=10;
	b=20;
	c=30;

	d=++a,++b,++c,a+5; //here','acts as operator with associativity left to right and so the incremented value of a will be added to d and then other equations will			   // be performed.
	printf("d=%d\n",d);
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	printf("c=%d\n",c);

	a=10;
	b=20;
	c=30;

	d=(++a,++b,++c,a+5); //because of brackets the expressions inside it will be perfomed first and then the last expressions value will be assigned to a
	printf("d=%d\n",d);
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	printf("c=%d\n",c);
	return 0;
}




