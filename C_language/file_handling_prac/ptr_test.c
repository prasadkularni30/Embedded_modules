#include<stdio.h>
int main(){
	int x=10;
	int *p;
	int **q,**r;
	p=&x;
	q=&x;
	r=&p;
	printf("x=%d\n",x);
	printf("&x=%u\n",&x);
	//printf("p=%d\n",p);
	printf("p=%u\n",p);
	printf("&p=%u\n",&p);
	printf("*p=%u\n",*p);
	//printf("q=%d\n",q);
	printf("q=%u\n",q);
	printf("&q=%u\n",&q);
	printf("*q=%u\n",*q);
	//printf("**q=%u\n",**q);
	//printf("r=%d\n",r);
	printf("r=%u\n",r);
	printf("&r=%u\n",&r);
	printf("*r=%u\n",*r);
	printf("**r=%u\n",**r);
}


