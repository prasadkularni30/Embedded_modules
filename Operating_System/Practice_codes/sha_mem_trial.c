#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
       #include <sys/ipc.h>
       #include <sys/shm.h>
       #include<stdlib.h>
       #include <sys/types.h>
       #include <sys/wait.h>


#define KEY 5555


struct shmemory
{
	unsigned long count1;
	unsigned long count2;
	unsigned long count3;
	int flag;
};

struct shmemory *smh;

int main()
{
	int id,i=0,status;
	pid_t ret;
	
	id=shmget(KEY,2*getpagesize(),IPC_CREAT | 0600);
	
	if(id<0){printf("Failed mem allocation\n"); exit(0);}
	
	
	smh=shmat(id,0,0);
	
	smh->count1=10;
	smh->count2=20;
	smh->count3=30;
	smh->flag=0;
	
	printf("smh->count1: %lu, smh->count2: %lu, smh->count3: %lu\n",smh->count1,smh->count2,smh->count3);
	printf("----------------------------------------\n");
	
	ret=fork();
	
	if(ret<0)
	{
		printf("Fork failed\n");
		exit(0);
	}
	
	if(ret==0)
	{
		printf("In child Process\nPID: %d,PPID: %d\n",getpid(),getppid());
		while(1)
		{
			if(smh->flag==0)
			{
				smh->flag=1;
				while(i++<60000000)
				{
					smh->count1++;
					smh->count2++;
					smh->count3++;
				}
				smh->flag=0;
				break;
			}
		}
		//printf("smh->count1: %lu, smh->count2: %lu, smh->count3: %lu\n",smh->count1,smh->count2,smh->count3);
	}
	if(ret>0)
	{
		printf("In parent process\nPID: %d,PPID: %d\n",getpid(),getppid());
		while(1)
		{
			if(smh->flag==0)
			{
				smh->flag=1;
				while(i++<60000000)
				{
					smh->count1--;
					smh->count2--;
					smh->count3--;
				}
				smh->flag=0;
				break;
			}
		}
		//printf("smh->count1: %lu, smh->count2: %lu, smh->count3: %lu\n",smh->count1,smh->count2,smh->count3);
		
		
	}
	
	if(ret>0)
	{
		
		
		wait(&status);
		printf("Status: %d\n",status);
		printf("Again In parent process\nPID: %d,PPID: %d\n",getpid(),getppid());
		printf("----------------------------------------\n");
		printf("smh->count1: %lu, smh->count2: %lu, smh->count3: %lu\n",smh->count1,smh->count2,smh->count3);
		
		
	}
	
	
}
