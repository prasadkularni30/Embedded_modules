//Printing pattern using nested for loop
#include<stdio.h>
int main()
{
	int n;
	printf("enter number");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)//for rows
	{
		for(int j=1;j<=i;j++)//for columns
			printf("%d",i);
		printf("\n");
	}
}
