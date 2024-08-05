#include<stdio.h>
int main()
{
	int a[5]={10,20,30,40,50};
	int *p,*q;
	p=&a;
	q=a;


	printf("%u\n",(a+1));
	printf("%u\n",(a+1));
	printf("%u\n",*(a+1));
	printf("%u\n",*(1+a));
	printf("%u\n",*(p+1));
	printf("%u\n",1[p]);
	

	 return 0;
}

