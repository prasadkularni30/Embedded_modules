/*
1>> Using the shared memory IPC try to see race condition. Have one
    shared structure. Modify that in two different process.
*/

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

//defining KEY with unique no
#define KEY 1001


struct shm_mem
{
	unsigned long x;
	unsigned long y;
	unsigned long z;
};


int main()
{
	struct shm_mem *shm;
	int ret,id,status;
	unsigned long i=0;
	//function to allocate a shared memory segment
	id=shmget(KEY,sizeof(struct shm_mem),IPC_CREAT | 0666);
	if(id<0){ perror("shmget"); exit(0);}
	
	printf("Shared Memory ID: %d\n",id);
	
	//function to attach shared memory to a pointer
	shm=shmat(id,0,0);
	
	shm->x=10;
	shm->y=20;
	shm->z=30;
	
	//created a new(child) process
	if((ret=fork())<0){ perror("shmget"); exit(0);}
	
	if(ret>0)
	{
		printf("In Parent Process |PID: %d,PPID: %d\n",getpid(),getppid());
		
		while(i++<90000000)	//modifitons on shared memory variables
		{
			shm->x++;
			shm->y++;
			shm->z++;
		}
	}
	if(ret==0)
	{
		printf("In Child Process |PID: %d,PPID: %d\n",getpid(),getppid());
		
		while(i++<90000000)	//modifitons on shared memory variables
		{
			shm->x--;
			shm->y--;
			shm->z--;
		}
	}
	
	if(ret>0)
	{
		//waits until any process changes its state
		waitpid(-1,&status,0);
		
		printf("In Parent Process |PID: %d,PPID: %d\n",getpid(),getppid());
		
		printf("After modidication value\nshm->x: %ld\nshm->y: %ld\nshm->z: %ld\n",shm->x,shm->y,shm->z);
	
		//destroys the shared memory block		
		shmctl(id,IPC_RMID,NULL);

	}
		 
}
