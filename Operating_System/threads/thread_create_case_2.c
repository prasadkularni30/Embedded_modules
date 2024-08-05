/*
2>> Write a program to have two child process from a parent process
    and create a thread from each child.
3>> In the above program have one shared resource or a global structure
    and try to update the structure from one thread and read from other
    thread.
*/

#include<stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>


typedef struct {
	unsigned long x;
	char y;
	char *z;
}parameter;

//global structure variable declaration 
parameter para;

//function declaration
void* thread_fun( void *);

int ret=1,ret1=1;


int main()
{
	pthread_t thread1,thread2;
	void* (*f_ptr)() = thread_fun;
	int shm_id;
	//function to generate an IPC key
	key_t KEY=ftok("Q2.c",12);
	
	para.x=10;
	para.y='a';
	para.z="Hello World";
	
	//pointer declaration
	parameter *shm;
	
	//function to allocate a shared memory segment
	shm_id=shmget(KEY,sizeof(parameter),IPC_CREAT | 0666);
	
	if(shm_id<0){ perror("shmget"); exit(4);}
	
	//function to attach shared memory to a pointer
	shm=shmat(shm_id,0,0);
	
	if(shm<0){ perror("shmat"); exit(5);}
	
	shm->x=10;
	
	//created a new(child) process
	if((ret=fork())<0){ perror("fork"); exit(0);}
	
	if(ret==0)
	{
		
		printf("In Child Process 1| PID: %d,PPID: %d\n",getpid(),getppid());
		
		//thread creation and passing a pointer to shared memory 
		int val1=pthread_create(&thread1,NULL,f_ptr,shm);
			
		if(!val1)
			printf("Thread1 created successfully\n");
		else
		{
			printf("Thread1 creation failed\n");
			exit(2);
		}
			
		//waiting for the specified thread to finish execution
		pthread_join(thread1,NULL);
			
	}
	if(ret>0)
	{
		
		//created a new(child) process
		if((ret1=fork())<0){ perror("fork"); exit(1);}
			
		if(ret1==0)
		{
			printf("In Child Process 2 | PID: %d,PPID: %d\n",getpid(),getppid());
			
			//thread creation and passing a pointer to shared memory 
			int val2=pthread_create(&thread2,NULL,f_ptr,shm);
			if(!val2)
				printf("Thread2 created successfully\n");
			else
			{
				printf("Thread2 creation failed\n");
				exit(3);
			}
			
			//waiting for the specified thread to finish execution
			pthread_join(thread2,NULL);
		}
		if(ret>0)
		{
			printf("In Parent Process| PID: %d,PPID: %d\n",getpid(),getppid());
			printf("Shared memory ID: %d\n",shm_id);
			
			//waits until any process terminates
			wait(NULL);
			
			//destroys the shared memory block
			shmctl(shm_id,IPC_RMID,0);
			
			
			
		}
	}
	//void **x;
	
	
}

/*
In this program we have created two child process from 1 parent and we are creating thread in each child
In both thread we aretring to access global structure variable ann shared memory structure
Threads from same process shares same memory but we have two threads in two diffent process so they have diffent memory of their calling process so the modification on globally defined structure variable in one thread wont be visible in other thread but the for shared memory same ley is used so modification on shared memory done in one thread will visible to other thread
*/

void* thread_fun(void *arg1)
{
	int i=0;
	//parameter *para_1=(parameter *)arg;
	
	parameter *shm=(parameter *)arg1;
	
	printf("before\n");
	printf("Shared Memory struct shm->x: %ld\n",shm->x);
	printf("Structure variable x= %ld\n",para.x);
	printf("Structure variable y= %c\n",para.y);
	printf("Structure variable z= %s\n",para.z);
	
		para.x=90;
		para.y='z';
		para.z="Prasad";
		
	printf("after\n");
	printf("Structure variable x= %ld\n",para.x);
	printf("Structure variable y= %c\n",para.y);
	printf("Structure variable z= %s\n",para.z);
	
	shm->x=20;
	printf("Shared Memory struct shm->x: %ld\n",shm->x);


}

