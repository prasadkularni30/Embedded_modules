#include<stdio.h>

void display(int [][20],int);
void input(int [][20],int);
void null(int [][20],int);


int main()
{
int matrix[20][20],n;
	
	printf("Enter the size of square Matrix:\n");
	scanf("%d",&n);

	
	input(matrix,n);
	printf("\n");

	display(matrix,n);
	printf("\n");
	
	null(matrix,n);
	printf("\n");

	
	return 0;
	
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

void null(int arr[20][20],int n)
{

int flag=0;
	for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
		{
			if(arr[i][j]==0)
				flag++;
		}
	}
	if(flag==9)
	{
		printf("the matrix is null matrix\n");
	}else
		printf("the matrix is not null matrix");
}
