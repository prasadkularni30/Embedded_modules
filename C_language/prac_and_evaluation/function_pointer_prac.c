/* Q4: Write a C program, to initialize a given structure data members by calling another function
from main, make sure the called function should not return anything to the caller.
Hint, use pointers to data members.*/

#include<stdio.h>

struct structure{
	int x;
	struct st1{
		int y;
		int sum;
	}a1;
}m1;

void fun(int, int);

int main()
{
	m1.a1.y=10;
	m1.x=20;

	fun(m1.a1.y,m1.x);


	return 0;
}

void fun(int x, int y)
{
	m1.a1.sum=x+y;
	printf("sum=%d\n",m1.a1.sum);
}
