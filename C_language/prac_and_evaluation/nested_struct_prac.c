/*Q3: Create a nested structure, access members of inner structure from outer one.
(Structure inside structure), write a small program to implement the same.*/


#include<stdio.h>

struct structure{
	int x;
	struct st1{
		int y;
		int sum;
	}a1;
}m1;

int main()
{
	m1.a1.y=10;
	m1.x=20;

	struct st1 a2;

	a2.sum=m1.a1.y+m1.x;
	printf("sum=%d\n",a2.sum);

	return 0;
}

