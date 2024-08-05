#include<stdio.h>

int main()
{
	int arr[4]={10,20,30,40};
	

	printf("last value is %d",*(*(&arr+1)-1));
}
