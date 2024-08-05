#include<stdio.h>

//WAP to Check the endianness (little or big) of your current system.



int main(){


        int a = 0x11223344;

        char *cp,*temp;
	

	printf("&a=%p,a=%x\n",&a,a);
	
        cp=(char *)&a;


        for(int i=3,j=0;i>1 ;i--,j++)
	{
                *temp=*(cp+i);
		*(cp+i)=*(cp+j);
		*(cp+j)=*temp;
        }
	

	
	printf("&a=%p,a=%x\n",&a,a);

}
