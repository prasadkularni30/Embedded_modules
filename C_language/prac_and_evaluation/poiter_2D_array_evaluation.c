#include<stdio.h>
/*
Access 2D array using pointers
int arr[3][4]; int (*p)[4]; p=arr;
sizeof(p), sizeof(*p), sizeof(**p) , values of p, p+1
Check equivalence of arr[i][j], (*(p+i))[j], *(*(p+i)+j)
*/

int main()
{
	int arr[3][4]={10,20,30,40,50,60,70,80,10,20,30,40};
	int (*p)[4];
	p=arr;

	printf("%d\n",sizeof(p));	// size of pointer =8byte
	printf("%d\n",sizeof(*p));	//size of 1D array=16byte
	printf("%d\n",sizeof(**p));	//size of integer=4byte
	printf("%p\n",p);		//address of first 1D array
	printf("%p\n",p+1);		//jump by 1D array and adress of 2nd array
	

	
	// All Values printed and all are same
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%d ",arr[i][j]);
		}
	}
	printf("\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%d ",(*(p+i))[j]);
		}
	}
	printf("\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%d ",*(*(p+i)+j));
		}
	}
}
