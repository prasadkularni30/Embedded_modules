#include<stdio.h>

void display(int [][20],int);
void input(int [][20],int);
void add(int [][20],int [][20],int );
void sub(int [][20],int [][20],int );
void mul(int [][20],int [][20],int );


int main()
{
	int matrix1[20][20], matrix2[20][20],n;
	printf("Enter the size of square Matrix:\n");
	scanf("%d",&n);


	printf("matrix 1:");

	input(matrix1,n);

	printf("\n");
	display(matrix1,n);

	printf("\n");
	printf("matrix 2:");

	input(matrix2,n);

	printf("\n");
	display(matrix2,n);

/*	
	printf("Enter the Matrix1 of 3x3:\n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("Enter element mat1[%d][%d]: ",i,j);
			scanf("%d", &matrix1[i][j]);
		}
	}
	
	// print mat1 via function
	printf("Matrix 1 is \n");
	print(matrix1);
	
	printf("Enter the Matrix2 of 3x3:\n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("Enter element mat2[%d][%d]: ",i,j);
			scanf("%d", &matrix2[i][j]);
		}
	}
	// print matrix2 via function
	printf("Matrix 2 is \n");
	print(matrix2);

	int matrix1[3][3]={{1,2,3},
		           {4,5,6},
			   {7,8,9}
	                  };
	int matrix2[3][3]={{1,2,3},
		           {4,5,6},
			   {7,8,9}
	                  };
	
	arrays=sizeof(matrix1)/sizeof(matrix1[0]);
	eles=sizeof(matrix1[0])/sizeof(matrix1[0][0]);
*/
	printf("\n");
	add(matrix1,matrix2,n);
	printf("\n");
	sub(matrix1,matrix2,n);
	printf("\n");
	mul(matrix1,matrix2,n);
	printf("\n");

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



void add(int matrix1[][20],int matrix2[][20],int n)
{	int add[20][20];
	int i,j;
	//Addition
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			add[i][j]=matrix1[i][j]+matrix2[i][j];
		}
	}
	printf("Addition of matrix:\n");
	display(add,n);

}

void sub(int matrix1[20][20],int matrix2[20][20],int n)
{
	int sub[20][20];
	int i,j;
	//Subtraction
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sub[i][j]=matrix1[i][j]-matrix2[i][j];
		}
	}
	printf("Subtraction of matrix:\n");
	display(sub,n);
}





void mul(int matrix1[20][20],int matrix2[20][20],int n)
{	//multiplication
	int mull=0,add,i,j,k;
	int mul[20][20];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			add=0;
			for(k=0;k<n;k++)
			{
			mull=matrix1[i][k]*matrix2[k][j];
			add=add+mull;
			}
			
			mul[i][j]=add;
		}
	}

	printf("multiplication of matrix:\n");
	display(mul,n);
}
