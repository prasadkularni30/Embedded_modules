#include<stdio.h>
void fun1(int);

int main(){
	int a=3;

	
	fun1(a);
	//printf("fun1 using n-- \n");
	//fun1(3); segmentation fault with this function
	return 0;
}
void fun1(int n)
{
	if(n>0)
	{
		fun1(--n);
		printf("%d\n",n);
		fun1(--n);
	}
	
}
