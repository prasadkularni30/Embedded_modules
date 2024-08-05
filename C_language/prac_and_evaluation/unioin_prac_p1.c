/*Q1:
Analyze the following code*/

#include<stdio.h>

union A
{
	int y;
	struct demo{
		short int x;
		short int w;
	}a;
	double z;
	int arr[2];
}a1;


union B
{
	int x;
	short int y;
	char ch;
	char carr[4];
} b1;

int main(){
	char *ch;
	ch=(char *)&a1;
	a1.y=0x41424344;
	for(int i=0;i<8;i++)
	{
		printf("%p= %c\n",ch+i,*(ch+i));
	}
	printf("y=%f\n",a1.y);
	//a1.x=0x11223344;
	printf("x=%x\n",a1.a.x);
	printf("w=%x\n",a1.a.w);
	a1.z=156342234234234225.15625;
	printf("a1.arr[1]: %x\na1.arr[0]: %x\n",a1.arr[1],a1.arr[0]);
	
	printf("union b\n");
	
	b1.x=0x41424344;
	printf("y=%x\n",b1.y);
	printf("ch hex=%x\n",b1.ch);
	printf("ch char=%c\n",b1.ch);
	for(int i=0;i<4;i++)
	{
		printf("hex carr[%d]=%x\n",i,b1.carr[i]);
		printf("char carr[%d]=%c\n",i,b1.carr[i]);
	}
}

//Analyze the output of above code.


/*
Analyze the values of b1. y,, print all elements of b1.carr
Modify b1.y =0x1122 or b1.ch= 0 and check the value of b1.x
*/
