/*Q12. What is the significance of following pointer
int (*q)[3][4];

What are the sizes of q, *q, **q, ***q*/

#include<stdio.h>

int main()
{
	int (*q)[3][4];//={{1,2,3,4},{5,6,7,8},{4,3,2,1}};


	printf("q=%ld\n",sizeof(q));		//size of pointer 8 bytes
	printf("*q=%ld\n",sizeof(*q));		//size of 2D array 48 byte
	printf("**q=%ld\n",sizeof(**q));	//size of first 1D array 16 bytes
	printf("***q=%ld\n",sizeof(***q));	//size of first element	4 bytes
}
