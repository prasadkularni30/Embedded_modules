#include<stdio.h>

void display(int [],int);
void input(int [],int);



int main()
{
int arr[20],n;
	
	printf("Enter the size of array:\n");
	scanf("%d",&n);

	
	input(arr,n);
	printf("\n");

	display(arr,n);
	printf("\n");
	

	printf("reverse array:");
	for (int i=0,j=n-1;i<j;i++,j--)
	{
		arr[i]=arr[i]^arr[j];
		arr[j]=arr[i]^arr[j];
		arr[i]=arr[j]^arr[i];
	}
	display(arr,n);
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

