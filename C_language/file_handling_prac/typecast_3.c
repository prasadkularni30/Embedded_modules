

#include<stdio.h>
int main()
{

int arr[5]={10, 20, 30, 40, 50};
	
	int a[3][4]= {{1,2,3,4},{4,3,2,1},{7,8,9,0}};

	printf("a %u\n", a);// 2000, 2004
	printf(" *a=%u\n", *a);// 2000, 2004
	printf(" **a=%u\n",**a);// 2000, 2004
	printf("*a[0]=%u\n",*a[0]);
	printf("*a[0]+0=%u", *a[0]+0); // 5000, 5016 
					 // in case of 2D array; array name represent ptr
					 // to 1st 1D array (array ptr

					 }
