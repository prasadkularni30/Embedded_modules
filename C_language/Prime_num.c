#include<stdio.h>
int main()
{
	int a,b,prime,flag;
	printf("enter a number");
	scanf("%d",&a);

	
	flag=0;
	for(b=2;b<=(a/2);b++)
	{
		
		if((a%b)==0)
		{
			printf("It is not a prime number\n");
			flag=1;
			break;
		}
	}
		if(flag==0)
		{
			printf("It is a prime number\n");
		}

		
	return 0;
	
}



