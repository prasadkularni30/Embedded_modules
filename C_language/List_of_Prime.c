#include<stdio.h>
int main()
{
	int n,b,c,d, flag;
	flag=0;
	printf("enter a number");
	scanf("%d",&n);
	
	for(b=2;b<=n;b++)
	{
		flag=0;
		for(c=2;c<=b/2;c++)//will check number is prime or not 
		{
		if((b%c)==0)
		{
			flag++;
			break;
		}
		}
		if(flag==0)//print if prime
		{
			printf("%d,",b);
		}

	}
	return 0;
}
