#include<stdio.h>
#include<stdlib.h>


int main()
{
	
	
	//initializing var arr1 
	//arr1 1 is a pointer to arrays having 4 interger
	int (*arr1)[4];
	
	//allocating dyanmic memory to arr1
	arr1=(int (*)[])malloc(48);
	
	
	
	*(arr1+0)[0]=11;
	*(arr1+1)[0]=22;
	*(arr1+2)[0]=33;
	
	printf("*(arr1+0)[0]=%d \n*(arr1+1)[0]=%d \n*(arr1+2)[0]=%d \n",*(arr1+0)[0],*(arr1+1)[0],*(arr1+2)[0]);
	
	
	// initializing arr2
	//arr2 is a array of 4 having pointer to interger arrays 
	int *arr2[4];
	
	
	//allocating dyanmic memory to arr2
	for(int i=0;i<4;i++){
		arr2[i]=(int *)malloc(sizeof(int)*4);
	}
	
	arr2[0][0]=10;
	arr2[1][0]=20;
	arr2[2][0]=30;
	
	printf("*arr2[0][0]=%d \n*arr2[1][0]=%d \n*arr2[2][0]=%d \n",arr2[0][0],arr2[1][0],arr2[2][0]);
	
	//freeing the memory allocated to arr1
	free(arr1);
	
	//freeing the memory allocated to arr2
	for(int i=0;i<4;i++)
	free(arr2[i]);
	
	
	
	
	/*
	
	//initializing arr3
	//arr3 is a pointer to array
	int *arr3;
	//allocating dynamic memory of 4 integers to arr3 
	arr3=(int *)malloc(sizeof(int)*4);
	
	printf("Input: \n");
	for(int i=0;i<4;i++)
	{
		printf("arr3[%d]: ",i);
		scanf("%d",&arr3[i]);
	}
	
	printf("Display: \n");	
	for(int i=0;i<4;i++)
		printf("arr3[%d]: %d\n",i,arr3[i]);
	
	//freeing memory allocated to arr3
	free(arr3);
		*/
}


