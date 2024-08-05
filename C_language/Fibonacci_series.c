#include<stdio.h>
int main()
{
//To print Numbers from Fibonacci series below n
	int i,j,n,k,num,count;
	printf("Enter a number for Fibonacci series: ");
	scanf("%d",&n);
	j=1;
	k=0;
	num=0;
	printf("Numbers from Fibonacci series below %d are: %d,",n,k);
	do
	{
		k=num+j;
		printf("%d,",j);
		num=j;
		j=k;
		
	}while(k<=n);
//To print first n numbers of Fibonacci series
	j=1;
	k=0;
	num=0;
	count=0;
	printf("\n first %d numbers of Fibonacci series are: %d,",n,k);
	while(count<=n)
	{
		k=num+j;
		printf("%d,",j);
		num=j;
		j=k;
		count++;
	}
	return 0;



}

