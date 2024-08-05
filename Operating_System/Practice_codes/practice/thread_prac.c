#include<stdio.h>
#include<pthread.h>

void* fun()
{
	printf("In thread\nHeloo\n");
	printf("Heloo\n");
	printf("Heloo\n");
	printf("Heloo\n");
//	while(1);
}

pthread_t thread1,thread2;

int main()
{ 
//	void* (* f_ptr)()=fun;
	
	int x;
	void *z;
	
	int ret1=pthread_create(&thread1,NULL,fun,NULL);
	if(ret1==0)
	{
		printf("Thread Created Succesfully\n");
	}
	else
	{
		printf("G=AFil\n");
	}
	int ret2=pthread_create(&thread2,NULL,fun,NULL);
	if(ret2==0)
	{
		printf("Thread Created Succesfully\n");
	}
	else
	{
		printf("G=AFil\n");
	}
	//printf("before z: %p\n",*z);
	pthread_join(thread1,&z);
	printf("z thread 1: %p\n",((int *)z));
	pthread_join(thread2,&z);
	
	printf("z thread 2: %p\n",((int *)z));
	printf("Exiting..\n");
	
}
