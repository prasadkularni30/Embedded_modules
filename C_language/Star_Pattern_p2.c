//pattern using nested for
#include<stdio.h>
int main()
{
	int n,i,j;
	printf("enter a number");
	scanf("%d",&n);
	for(i=1;i<=n;i++)//for rows
	{
		for(j=n;j>=i;j--)//for columns and spaces
		{
			printf(" ");
		}
		for(j=1;j<=i;j++)//for columns and reccuring number
		{
			printf("%d",i);
		}
			
		printf("\n");
	}
	return 0;
}
