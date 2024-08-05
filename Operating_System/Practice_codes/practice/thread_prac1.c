#include<stdio.h>
#include<pthread.h>

struct node
{
	int a;
	char b;
};

void* fun(void* w)
{
	struct node *q=(struct node *)(w);
	printf("intger a=%d\n",q->a);
	printf("char b=%c\n",q->b);
	
	q->a=10;
	q->b='c';
	printf("After Modification\n");
	printf("intger a=%d\n",q->a);
	printf("char b=%c\n",q->b);
	
	
}

pthread_t thread1;

int main()
{
	struct node arg;
	arg.a=7;
	arg.b='v';
	int ret=pthread_create(&thread1,NULL,fun,&arg);
	if(ret==0)
	{
		printf("thread created\n");
	}
	else
	{
		printf("Fail\n");
	}
	pthread_join(thread1,NULL);
}
