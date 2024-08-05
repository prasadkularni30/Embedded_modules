#include<stdio.h>
int *fun();
int main()
{
	int *t;
	t=fun();
	
		printf("%d\n",*t);
		*t=*t+20;
		printf("tempvalueinmain%d\n",*t);
		fun();
	return 0;

}
int *fun()
{
	static int  temp=10;
	printf("tempinfun%d\n",temp);
	return &temp;
}
