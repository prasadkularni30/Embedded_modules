#include<stdio.h>
#define size 20
void sum_avg(int [],int);
void min_max(int [],int);

int main()
{
	int i,n;
	int arr[size]={0};
	printf("Enter size of array\n");
	scanf("%d",&n);
	printf("Enter %d inputs \n",n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("input is: ");
	for(i=0;i<n;i++)
	{
		printf("%d,",arr[i]);
	}
	printf("\n");


	sum_avg(arr,n);
	min_max(arr,n);
	return 0;
}

void sum_avg(int arr[],int n)
{
	int sum=0,avg;
	for(int i=0;i<n;i++)
	{
		sum=sum+arr[i];
	}
	printf("sum is %d\n",sum);
	avg=sum/n;
	printf("average is %d\n",avg);
}

void min_max(int arr[],int n)
{
	int min,max;
	min=arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	printf("minimun is %d\n",min);

	max=arr[0];
	for(int i=0;i<size;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	printf("maximum is %d\n",max);
}






