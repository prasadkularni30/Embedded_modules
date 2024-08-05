#include<stdio.h>

//WAP to Check the endianness (little or big) of your current system.



int main(){


        short int a = 0x1122,b;

        char *cp,*cs;
	
	cp=(char *) &a;

	printf("&a=%p,a=%x\n",&a,a);

	int temp = *cp;
	*cp=*(cp+1);
	*(cp+1)=temp;

	printf("&a=%p,a=%x\n",&a,a);




}
