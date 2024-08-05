#include<stdio.h>
#define size 5
void input_arr(int [][size]);
void display(int [][size]);

int main()
{
	int arr[size][size];

	input_arr(arr);
	printf("\n");
	display(arr);


}

void input_arr(int arr[size][size])
{
			printf("Enter elements of sq array size 5:\n");
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}

void display(int arr[size][size])
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			printf("%d ",arr[i][j]);
		}
			printf("\n");
	}
}
	

