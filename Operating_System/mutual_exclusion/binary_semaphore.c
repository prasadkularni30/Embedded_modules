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
#include <sys/sem.h>




struct shm_mem
{
	unsigned long x;
	unsigned long y;
	unsigned long z;
};

union semun
{
	int v;
	
	unsigned short *array;
}u;


int main()
{
	struct shm_mem *shm;
	
	struct sembuf sbuf;
	
	int ret,shm_id,status,sem_id;
	
	unsigned long i=0;
	
	key_t KEY=ftok("Q2.c",11);
	
	//allocated shared memory block
	shm_id=shmget(KEY,sizeof(struct shm_mem),IPC_CREAT | 0666);
	if(shm_id<0){ perror("shmget"); exit(0);}
	
	printf("Shared Memory ID: %d\n",shm_id);
	
	//attached allocated shared memory to the pointer
	if((shm=shmat(shm_id,0,0))<0){perror("shmat"); exit(1);}
	
	shm->x=10;
	shm->y=20;
	shm->z=30;
	
	//getting semaphore variable
	sem_id=semget(KEY,1,IPC_CREAT | 0600);
	if(sem_id<0){perror("semget"); exit(2);}
	
	u.v=1;
	
	//Initializing semaphore variable with 1
	ret=semctl(sem_id,0,SETVAL,u);
	if(ret<0){perror("semctl"); exit(1);}
	
	//getting semaphore var values in ret
	ret=semctl(sem_id,0,GETVAL);
	
	printf("Initialized Value of semaphore: %d",ret);
	
	//created a new(child) process
	if((ret=fork())<0){ perror("shmget"); exit(3);}
	
	if(ret>0)
	{
		printf("In Parent Process |PID: %d,PPID: %d\n",getpid(),getppid());
		
		
		sbuf.sem_num=0;	//semaphore index
		sbuf.sem_op=-1;	//operation we have to perform
		sbuf.sem_flg=0;	
		
		//fuction to perfom openration  on semaphore variable
		semop(sem_id,&sbuf,1);
		
		while(i++<90000000)
		{
			shm->x++;
			shm->y++;
			shm->z++;
		}
		
		sbuf.sem_num=0;
		sbuf.sem_op=+1;
		sbuf.sem_flg=0;
		
		semop(sem_id,&sbuf,1);
	}
	if(ret==0)
	{
		
		
		sbuf.sem_num=0;
		sbuf.sem_op=-1;
		sbuf.sem_flg=0;
		
		semop(sem_id,&sbuf,1);
		
		while(i++<90000000)
		{
			shm->x--;
			shm->y--;
			shm->z--;
			printf("In Child Process |PID: %d,PPID: %d\n",getpid(),getppid());
			while(1);
		}
		
		sbuf.sem_num=0;
		sbuf.sem_op=+1;
		sbuf.sem_flg=0;
		
		semop(sem_id,&sbuf,1);
	}
	
	if(ret>0)
	{
		waitpid(-1,&status,0);
		
		printf("In Parent Process |PID: %d,PPID: %d\n",getpid(),getppid());
		
		printf("After modidication value\nshm->x: %ld\nshm->y: %ld\nshm->z: %ld\n",shm->x,shm->y,shm->z);
		
		shmctl(shm_id,IPC_RMID,NULL);

	}
		 
}
