/*
4>> Try to synchronize the threads using MUTEX.
*/

#include<stdio.h>
#include <pthread.h>
#include<stdlib.h>


//struct declaration with typedef
typedef struct {
	unsigned long x;
	char y;
	char *z;
	int flag;
}parameter;

//global parameters
parameter para;


void* thread_fun( void *);	//function declaration

pthread_mutex_t mutex;		//Initializing a mutex object pointed to by mutex


int main()
{
	pthread_t thread1,thread2;
	void* (*f_ptr)() = thread_fun;

	pthread_mutex_init(&mutex,NULL);
	
	para.x=10;
	para.y='a';
	para.z="Hello World";
	para.flag=0;
	
	//created a new threads using pthread_create function
	int val1=pthread_create(&thread1,NULL,f_ptr,NULL);
	int val2=pthread_create(&thread2,NULL,f_ptr,NULL);
	
	
	if(!val1)
		printf("Thread1 created successfully\n");
	else
	{
		printf("Thread1 creation failed\n");
		exit(2);
	}
			
	if(!val2)
		printf("Thread2 created successfully\n");
	else
	{
		printf("Thread2 creation failed\n");	
		exit(3);
	}
	
	//waiting for the specified thread to finish execution
	pthread_join(thread2,NULL);
	pthread_join(thread1,NULL);
	pthread_mutex_destroy(&mutex);
	
	
}

void* thread_fun(void *arg1)
{
	unsigned int i=0;
	//parameter *para_1=(parameter *)arg;
	
	//pthread_mutex_lock function attempts to acquire mutex object pointed to by mutex and if other thread has already acquired it will block the other pthread 		//until first thread releases the mutex object 
	pthread_mutex_lock(&mutex);
	printf("before\n");
	printf("Structure variable x= %ld\n",para.x);
	printf("Structure variable y= %c\n",para.y);
	printf("Structure variable z= %s\n",para.z);
	
	para.y='z';
	para.z="Prasad";
		
	if(para.flag==0)
	{
		while(i++<600000)
		{
			para.x++;
		}
		para.flag=1;
	}
	else
	{
		while(i++<600000)
		{
			para.x--;
		}
	}
		
	printf("after\n");
	printf("Structure variable x= %ld\n",para.x);
	printf("Structure variable y= %c\n",para.y);
	printf("Structure variable z= %s\n",para.z);
	
	//function to release the acquired mutex object
	pthread_mutex_unlock(&mutex);

}

