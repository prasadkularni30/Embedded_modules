#include<stdio.h>
int fun(int);
int main()
{
	int sum,n,i,j;
	printf("Enter a number for recursive sum: ");
	scanf("%d",&n);
	printf("%d\n",fun(n));
	return 0;
}

int fun(int n)
{
	if(n>9)
	{
		int temp=n;
		int sum=0;
		while(temp!=0)
		{
			sum=sum+(temp%10);
			temp=temp/10;
		}

		n=fun(sum);
	}
	return n;
}
		 
