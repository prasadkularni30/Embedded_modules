#include<stdio.h>

//WAP to Check the endianness (little or big) of your current system.



int main(){


        int a = 0x11223344;

        char *cp;

        cp=(char*)&a;

	if(*cp==0x44)
		printf("little endian\n");
	else
		printf("Big Endian\n");

        for(int i=0;i<4;i++){
                printf("cp=%d,*(cp+%d)=%x\n",i,i,*(cp + i));    //littl endian
        }


}
