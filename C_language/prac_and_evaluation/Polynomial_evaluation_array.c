#include<stdio.h>
#include<stdio_ext.h>

int main()
{
	int n;
	printf("enter value");
	scanf("%d",&n);
	__fpurge(stdin);

	int power;
	printf("\nenter power value=");
	scanf("%d",&power);
	__fpurge(stdin);


	int arr[power+1];
	__fpurge(stdin);


	for(int i=0;i<=power;i++)
	{
		scanf("%d",&arr[i]);
	
	}
	__fpurge(stdin);

	int size=power+1;
	int sum=0;
	
	for(int i=power,j=0;j<size;j++)
	{
		
	
		if(i==0)
		{		
			sum=sum+arr[j];
			break;
		}
		int temp=1;
		for(int k=i;k>0;k--)
		{
			temp=temp*n;
		}
		sum=sum+(temp*arr[j]);
		i--;

	}
	printf("ans:%d\n",sum);
	return 0;
}
