#include<stdio.h>

void display(int [][20],int);
void input(int [][20],int);
void identity(int [][20],int);


int main()
{
int matrix[20][20],n;
	
	printf("Enter the size of square Matrix:\n");
	scanf("%d",&n);
	
	input(matrix,n);
	printf("\n");

	display(matrix,n);
	printf("\n");
	
	identity(matrix,n);
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

void identity(int arr[20][20],int n)
{
	int flag=0,count=0;
	 for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++){
			if(i==j){
				if(arr[i][j]==1)
					flag++;
			}
			else{
				arr[i][j]==0;
				count++;
			}
			}
        }
	if(flag==3&&count==6){
		printf("the matrix is identity matrix\n");
	}else
		printf("the matrix is not identity");
}

