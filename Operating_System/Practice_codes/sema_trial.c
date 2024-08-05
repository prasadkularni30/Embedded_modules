#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include <sys/sem.h>
#include<sys/shm.h>

// defining unique keys (vales) for context allocation
//#define KEY1 1551	//for semaphore
//#define KEY2 1555	//for shared memory

struct sha_mem
{
	unsigned long x;
	unsigned long y;
	unsigned long z;
};

union semun		//always give same union type 
{
	int a;
};


int main()
{
	struct sha_mem *smem_Ptr;
	int id, sem_id,ret1, ret2,ret3,status;
	
	long j=0;
	struct sembuf s1;
	
	int KEY1=ftok("sema_trial.c",10);
	int KEY2=ftok("sema_trial.c",10);
	
	printf("KEY1: %d,KEY2: %d\n",KEY1,KEY2);
	
	
	id= shmget(KEY1, sizeof(struct sha_mem), IPC_CREAT | 0666);
	smem_Ptr=shmat(id, 0, 0);
	
	if(smem_Ptr<0){ printf("Failed\n");exit(0);}
	
	sem_id=semget(KEY2,1,IPC_CREAT | 0666);
	
	union semun var;
	
	var.a=1;
	
	ret1=semctl(sem_id,0,SETVAL,var);
	
	if(ret1<0){ printf("Failed\n");exit(0);}
	
	ret2=semctl(sem_id,0,GETVAL);
	
	printf("GETVAL: %d\n",ret2);
	
	smem_Ptr->x=10;
	smem_Ptr->y=20;
	smem_Ptr->z=30;
		
	
	printf("Before Operation\nsmem_ptr->x: %lu ,smem_ptr->y: %lu ,smem_ptr->z: %lu\n",smem_Ptr->x,smem_Ptr->y,smem_Ptr->z);

	if((ret3=fork())<0){ printf("Failed\n");exit(0);}
	
	if(ret3==0)
	{
	
		printf("in child process .. ppid: %d, pid :%d\n",getppid(),getpid());
		
		s1.sem_num=0;
		s1.sem_op=-1;
		s1.sem_flg=0;
		
		ret2=semop(sem_id,&s1,1);
		if(ret2<0){ printf("Failed\n");exit(0);}
		
		while(j++<60000000)
		{
			smem_Ptr->x--;
			smem_Ptr->y--;
			smem_Ptr->z--;
		}
		
		s1.sem_num=0;
		s1.sem_op=+1;
		s1.sem_flg=0;
		
		
		
		
		ret2=semop(sem_id,&s1,1);
		if(ret2<0){ printf("Failed\n");exit(0);}
		
	}
	else  if(ret3>0)
	{
		printf("in parent process .. ppid: %d, pid :%d\n",getppid(),getpid());
		
		s1.sem_num=0;
		s1.sem_op=-1;
		s1.sem_flg=0;
		
		ret2=semop(sem_id,&s1,1);
		
		while(j++<60000000)
		{
			smem_Ptr->x++;
			smem_Ptr->y++;
			smem_Ptr->z++;
		}
		
		s1.sem_num=0;
		s1.sem_op=+1;
		s1.sem_flg=0;
		
		printf("After Dec Output\nsmem_ptr->x: %lu ,smem_ptr->y: %lu ,smem_ptr->z: %lu\n",smem_Ptr->x,smem_Ptr->y,smem_Ptr->z);
		
		ret2=semop(sem_id,&s1,1);
	}
	
	if(ret3>0)
	{
		wait(&status);
		
		printf("Final Output\nsmem_ptr->x: %lu ,smem_ptr->y: %lu ,smem_ptr->z: %lu\n",smem_Ptr->x,smem_Ptr->y,smem_Ptr->z);
		
	}
}
