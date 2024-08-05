#include<stdio.h>
int main()
{
	int n,temp,sum,num,power,i,j;
	printf("Enter a number to check if number is armstrong or not: ");
	scanf("%d",&n);
	power=0, sum=0;
	
	for(j=n;j>0;) // to count power number
	{
		power++;
		j=j/10;
	}
	for(i=n;i>0;i=i/10)
	{
		temp=i%10;
		num=temp;
		for(j=1;j<power;j++) // counts perticular power
		{
			temp=temp*num;
		}
		sum=sum+temp;

	}
	if(sum==n)
	{
		printf("The number %d is a armstrong number\n",n);
	}
	else
	{
		printf("The number %d is not a armstrong number\n",n);
	}

	
}	
