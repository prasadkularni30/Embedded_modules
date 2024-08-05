#include<stdio.h>
int main(){
	int n,i,j,k=1;
	printf("Enter number");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=(n-i);j++)//selected rows
		{
			printf(" ");
		}
		for(j=1;j<=(2*i-1);j++)//selected columns
		{

			printf("%d",i);
			k++;
		}
		printf("\n");
	}
	return 0;
}

