#include<stdio.h>

int main(){
	int arr[5]={10,20,30,40,50};
	int (*parr)[5];
	parr=&arr;

	printf("parr: %ld\n",sizeof(parr));
	printf("*parr: %ld\n",sizeof(*parr));
	printf("**parr: %ld\n",sizeof(**parr));
	for(int i=0;i<sizeof(*parr)/sizeof(**parr);i++)
		printf("**parr+%d: %d\n",i,**parr+i); // using dereferancing operator
		printf("\n");
	for(int i=0;i<sizeof(parr[i])/sizeof(*parr[i]);i++)
		printf("(*parr)[%d]: %d\n",i,(*parr)[i]); // using normal array as well as dereferancing operator
		printf("\n");

	
	return 0;
}
