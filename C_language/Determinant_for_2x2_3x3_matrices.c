#include<stdio.h>
void print3(int [][3]);
void print2(int [][2]);
void three(int [][3]);
void two(int [][2]);



int main()
{
int matrix1[3][3], matrix2[2][2];
	
	printf("Enter the Matrix1 of 3x3:\n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("Enter element mat1[%d][%d]: ",i,j);
			scanf("%d", &matrix1[i][j]);
		}
	}
	printf("Enter the Matrix1 of 2x2:\n");
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("Enter element mat1[%d][%d]: ",i,j);
			scanf("%d", &matrix2[i][j]);
		}
	}
	
	// print mat1 via function
	printf("Matrix 1 is \n");
	print3(matrix1);
	printf("\n");
	printf("Matrix 2 is \n");
	print2(matrix2);
	printf("\n");
//	arrays=sizeof(matrix1)/sizeof(matrix1[0]);
//	eles=sizeof(matrix1[0])/sizeof(matrix1[0][0]);
	printf("\n");
	two(matrix2);
	three(matrix1);
}
void print3(int a[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		printf("%d ",a[i][j]);
		}

	printf("\n");
	}
}

void print2(int a[2][2])
{
	int i,j;
	for(i=0;i<2;i++,j++)
	{
		for(j=0;j<2;j++)
		{
		printf("%d ",a[i][j]);
		}

	printf("\n");
	}
}
void three(int a[3][3])
{
	int det,z,x;
	det=a[0][0]*((a[1][1]*a[2][2])-(a[1][2]*a[2][1]));
	z=det-(a[0][1]*((a[1][0]*a[2][2])-(a[1][2]*a[2][0])));
	x=z+(a[0][2]*((a[1][0]*a[2][1])-(a[1][1]*a[2][0])));
	printf("det 3X3: %d",x);
	printf("\n");
}

void two(int a[][2])
{
	int det;
	det=(a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
	printf("det 2X2: %d",det);
	printf("\n");
}
