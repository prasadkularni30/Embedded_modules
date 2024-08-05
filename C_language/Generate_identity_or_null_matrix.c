#include<stdio.h>

void display(int [][20],int);
//void input(int [][20],int);
void null_matrix(int[][20], int);
void identity_matrix(int [][20], int);

int main()
{
int matrix[20][20],n;

	printf("Enter the size of square Matrix:\n");
	scanf("%d",&n);

	null_matrix(matrix,n);

	identity_matrix(matrix,n);

}

void display(int arr[20][20],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
}

void null_matrix(int arr[][20],int n)      
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		arr[i][j]=0;
		}
	}
	printf("Null matrix:\n");
	display(arr,n);
	printf("\n");
}


void identity_matrix(int arr[][20],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		   if(i==j)
		   {
			arr[i][j]=1;
		   }
		   else
		   {
			arr[i][j]=0;
		   }
		}
	}
	printf("Identity matrix:\n");	
	display(arr,n);
	printf("\n");
}
