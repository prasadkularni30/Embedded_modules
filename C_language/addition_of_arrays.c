#include<stdio.h>

void display(int [],int);
void input(int [],int);
void add(int[],int[],int);



int main()
{
int arr1[20],arr2[20],n;

	printf("Enter the size of arrays:\n");
	scanf("%d",&n);

	
	printf("Enter the first array:\n");
	input(arr1,n);
	printf("\n");
	
	printf("array1 :");
	display(arr1,n);
	printf("\n");

	printf("Enter the second array:\n");
	input(arr2,n);
	printf("\n");

	printf("array2:");
	display(arr2,n);
	printf("\n");

	add(arr1,arr2,n);
	printf("\n");

	
}
void input(int arr[20],int n)
{

	for(int i=0;i<n;i++){
		printf("Enter element arr[%d]: ",i);
		scanf("%d", &arr[i]);
		
	}
}
void display(int arr[20],int n)
{

	printf("array:");
	for(int i=0;i<n;i++)
	{
			printf("%d ",arr[i]);
	}
}


void add(int arr1[20],int arr2[20],int n)
{

	int ans[n];
	for (int i=0;i<n;i++)
	{
		ans[i]=arr1[i]+arr2[i];
	}

	printf("sum array:");
	display(ans,n);
	printf("\n");
}

