//Factorial of given numbers
#include<stdio.h>
int main()
{
	int n;
	printf("Enter number=");
	scanf("%d",&n);
	int fac=1;
	for(int i=1;i<=n;i++) 
	{
		fac=fac*i; 
	}
	printf("Factorial of %d is %d",n,fac);
	return 0;
}
