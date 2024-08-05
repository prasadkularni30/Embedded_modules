#include<stdio.h>
void dtob(int);
void dtoO(int);
void dtoh(int);

int main()
{
	int n;
	scanf("%d",&n);
	printf("Entered num: %d\n",n);
	printf("Binary: ");
	dtob(n);
	printf("\n");
	printf("Octal: ");
	dtoO(n);
	printf("\n");
	printf("Hexadecimal: ");
	dtoh(n);
	return 0;

}
void dtob(int n)
{
	if(n==0)
	{ 
		return ;
	}
	dtob(n/2);
	printf("%d ",n%2);
	return ;

}
void dtoO(int n)
{
	if(n==0)
	{ 
		return ;
	}
	dtoO(n/8);
	printf("%d",n%8);
	return ;

}
void dtoh(int n)
{
	if(n==0)
	{ 
		return ;
	}
	dtoh(n/16);
	if(n>9&&n<16)
	{
		printf("%c",(n%16)+55);
	}
	else
	printf("%d",n%16);
	return ;

}
