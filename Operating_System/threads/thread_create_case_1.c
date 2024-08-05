/*
1>> Write a program to create a thread in main thread and see the O/P
    of top and ps corresponding to that thread and state your observtion.
*/


#include<stdio.h>
#include <pthread.h>
#include<stdlib.h>


typedef struct {
	int x;
	char y;
	char *z;
}parameter;

//function declaration
void* thread_fun(void *arg);


int main()
{
	pthread_t thread1;
	
	//global structure variable declaration 
	parameter para;
	para.x=10;
	para.y='a';
	para.z="thread";
	
	//thread creation and passing a pointer to shared memory 
	if(!pthread_create(&thread1,NULL,thread_fun,&para))
		printf("Thread1 created successfully\n");
	else
	{
		printf("Thread1 creation failed\n");
		exit(0);
	}
	
	//waiting for the specified thread to finish execution
	pthread_join(thread1,NULL);
}

int flag=1;

void* thread_fun(void *arg)
{
	
	parameter *para_1=(parameter *)arg;
	//int temp=((parameter *)arg)->x;
	
	printf("==============================================\n");
	printf("Alphabets: ");
	for(int i=65;i<=90;i++)
		printf("%c ",i);
	printf("\n");
	
	printf("==============================================\n");
	
	
	printf("Structure variable x= %d\n",para_1->x);
	printf("Structure variable y= %c\n",para_1->y);
	printf("Structure variable z= %s\n",para_1->z);
	
	while(1);
	

}



