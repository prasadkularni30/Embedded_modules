#include<stdio.h>
void fun1();
void fun2();
int main()
{
	printf("fun2 using --n \n");
	fun2(3);
	printf("fun1 using n-- \n");
	//fun1(3); segmentation fault with this function
	return 0;
}
void fun1(int n)
{
	if(n>0)
	{
		fun1(n--);
		printf("%d/n",n);
		fun1(n--);
	}
	return ;
}
void fun2(int n)
{
	if(n>0)
	{
		fun2(--n);
		printf("%d\n",n);
		fun2(--n);
	}
	return ;
}
