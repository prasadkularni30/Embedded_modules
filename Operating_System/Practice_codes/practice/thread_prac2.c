#include<stdio.h>
#include<pthread.h>

struct node
{
	int a;
	char b;
};

void *fun(void *w)
{
	struct node *q=(struct node *)(w);
	printf("Integer a=%d\n",q->a);
	printf("Char b=%c\n",q->b);
	
	q->a=2;
	q->b='e';
	
	printf("Aftewr Modification\n");
	printf("Integer a=%d\n",q->a);
	printf("Char b=%c\n",q->b);
	
}

pthread_t thread1,thread2;

int main()
{
	struct node arg;
	arg.a=5;
	arg.b='w';
	
	int ret1=pthread_create(&thread1,NULL,fun,&arg);
	if(ret1==0)
	{
		printf("thread 1  created\n");
	}
	else
	{
		printf("Failed\n");
	}
	pthread_join(thread1,NULL);
	int ret2=pthread_create(&thread2,NULL,fun,&arg);
	if(ret2==0)
	{
		printf("thread 2 created\n");
	}
	else
	{
		printf("Failed\n");
	}
	pthread_join(thread2,NULL);		
}
