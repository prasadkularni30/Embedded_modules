#include<stdio.h>
void display(int [][20],int);
void input(int [][20],int);
void transpose(int [][20],int n);


int main()
{
	int matrix1[20][20],n;
	
	printf("Enter the size of square Matrix:\n");
	scanf("%d",&n);

	input(matrix1,n);
	printf("\n");

	printf("first matrix is:\n");
	display(matrix1,n);

	printf("\n");
	transpose(matrix1,n);
}

void input(int arr[20][20],int n)
{

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("Enter element mat1[%d][%d]: ",i,j);
			scanf("%d", &arr[i][j]);
		}
	}
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


void transpose(int a[20][20],int n)
{
	int transpose[20][20];
	int i,j;
	for(i=0;i<n;i++,j++)
	{
		for(j=0;j<n;j++)
		{
			transpose[i][j]=a[j][i];
		}

	}

	printf("Transpose matrix:\n");
	display(transpose,n);

}
