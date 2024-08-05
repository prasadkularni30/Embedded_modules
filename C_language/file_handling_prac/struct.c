#include<stdio.h>

struct demo{
	int a;
	float b;
	char c;
};

int main(){
	struct demo v1;
	struct demo v2={100, 99.9, 'a'};

	printf("v2.a=%d\n", v2.a); // 100
	printf("v2.c=%c\n", v2.c); // a

	v2.a=111;

	printf("v2.a=%d\n", v2.a); // 100
				   //
				  
	printf("%d %f %c\n", v2.a, v2.b, v2.c); // 111 99.9 a

	v1.a=111;

	printf("v1.a=%d\n", v1.a); // 100

	v1=v2;
	printf("%d %f %c\n", v1.a, v1.b, v1.c); // 111 99.9 a
				   
	return 0;
}			

