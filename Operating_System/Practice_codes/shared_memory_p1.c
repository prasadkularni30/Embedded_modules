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
	
	
	int id,ret,j=0,status;
	
	
	if((ret=fork())<0)
	{
		printf("Process creation failed\n");
		exit(0);
	}
	
	if(ret==0)
	{
		sleep(1);
		printf("In child process \nPID: %d,PPID: %d\n",getpid(),getppid());
		
		execl("/home/desd/pmarch_2024/Prasad_K/OS/./shared_memory_p2.out","",NULL);
		//execl("/home/desd/pmarch_2024/Prasad_K/OS/./shared_memory_p2.out","",NULL);
	}
	else if(ret>0)
	{
		id = shmget(KEY1, sizeof(struct sh_mem),IPC_CREAT | 0600);
		
		if(id<0)
		{
			printf("memory allocation failed\n");
			exit(0);
		}
		
		shm=shmat(id,0,0);
		
		shm->x=10;
		shm->y=20;
		shm->z=30;
		
		printf("----------------------------------------------\n");
		printf("In Parent process (P1) \nPID: %d,PPID: %d\n",getpid(),getppid());
		printf("Before inc in process p1:\nshm->x: %d, shm->y: %d,shm->z: %d\n",shm->x,shm->y,shm->z);
		printf("----------------------------------------------\n");
		while(j++<600)
		{
			shm->x++;
			shm->y++;
			shm->z++;
		}
		
		//wait(&status);
		sleep(1);
		printf("----------------------------------------------\n");
		printf("After dec in process p2:\nOutput at p1\nshm->x: %d, shm->y: %d,shm->z: %d\n",shm->x,shm->y,shm->z);
		printf("----------------------------------------------\n");
		
		 shmctl(id,IPC_RMID,0);
		
	}
	
	
}
