#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include <sys/sem.h>
#include<sys/shm.h>

#define KEY1 1551

struct sh_mem
{
	int x;
	int y;
	int z;
};


int main()
{
	struct sh_mem *shm;
	
	
	int id,j=0,status;
		
	id= shmget(KEY1, sizeof(struct sh_mem),IPC_CREAT | 0600);
	
	printf("In process P2 \nPID: %d,PPID: %d\n",getpid(),getppid());
	if(id<0)
	{
		printf("memory allocation failed\n");
		exit(0);
	}
	
	printf("address id: %d\n",id);
	shm=shmat(id,0,0);
	printf("address: %p\n",shm);
	//while(1);
	printf("----------------------------------------------\n");
	printf("After inc in process p1:\nOutput Process P2\nshm->x: %d, shm->y: %d,shm->z: %d\n",shm->x,shm->y,shm->z);
	printf("----------------------------------------------\n");
	
        while(j++<600)
	{
		shm->x--;
		shm->y--;
		shm->z--;
	}
        
	
	//wait(&status);
	printf("----------------------------------------------\n");
	printf("After dec in process p2:\nshm->x: %d, shm->y: %d,shm->z: %d\n",shm->x,shm->y,shm->z);
	printf("----------------------------------------------\n");
		
	
	
}
