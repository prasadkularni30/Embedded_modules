#include<stdio.h>

int main(){
	int x=10;
	int *p=&x;

	int arr[5]={10, 20, 30, 40, 50};
	
	p=(int *)(&arr+1 
			);

	int (*ap)[5];
	

	ap=(int (*)[5]) arr; // &arr == int (*)[5]
	printf("&arr=%u\n",&arr);
	printf("*ap=%u\n",**ap);
	printf("*(ap-1)=%u\n",*(*(ap+1)-1));
	printf("(ap+1)=%u\n",(ap+1));




						

	return 0;
}			

