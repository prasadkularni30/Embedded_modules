#include<stdio.h>
#include<stdio_ext.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/sem.h>



struct shm_mem
{
	char buff[50];
	int wr;
	int rd;
	int count;
	int max_size;
};

union semun
{
	int v;
	unsigned short *array;
}u;

int main()
{
	struct sembuf s_array[2];
	
	struct shm_mem *shm;
	
	char ch;
	int sem_id,shm_id,ret,choice;
	
	unsigned short arr1[3];
	
	key_t KEY=ftok("Q2.c",11);
	
	shm_id=shmget(KEY,sizeof(struct shm_mem),IPC_CREAT | 0666);
	if(shm_id<0){ perror("shmget"); exit(0);}
	
	printf("Shared Memory ID: %d\n",shm_id);
	
	if((shm=shmat(shm_id,0,0))<0){perror("shmat"); exit(1);}
	
	
	
	sem_id=semget(KEY,3,IPC_CREAT | 0600);
	if(sem_id<0){perror("semget"); exit(2);}
	
	
	u.array=arr1;
	
	ret=semctl(sem_id,0,GETALL,u);
	
	printf("Initialized Value of semaphore: free: %d,binary sem: %d,filled: %d\n",arr1[0],arr1[1],arr1[2]);
	
	while(1)
	{
	
		if(shm->count==0)
		{
			printf("Buffer is empty \n[1] To wait\n[2] Exit\nEnter Choice: ");
			scanf("%d",&choice);
			
			if(choice==2)
			{
				printf("Exiting..\n");
				shmctl(shm_id,IPC_RMID,NULL);
				exit(0);
			}
		}
		
		
		s_array[0].sem_num=2;
		s_array[0].sem_op=-1;
		s_array[0].sem_flg=0;
		
		s_array[1].sem_num=1;
		s_array[1].sem_op=-1;
		s_array[1].sem_flg=0;
			
		semop(sem_id,&s_array[0],2);
			
		if(shm->count<shm->max_size)
		{
			ch=shm->buff[shm->rd];
			shm->rd=(shm->rd+1)%shm->max_size;
			shm->count--;
		}
			
		s_array[0].sem_num=0;
		s_array[0].sem_op=+1;
		s_array[0].sem_flg=0;
		
		s_array[1].sem_num=1;
		s_array[1].sem_op=+1;
		s_array[1].sem_flg=0;
			
		semop(sem_id,&s_array[0],2);
		
		printf("Received: %c\n",ch);
		
	}
	
	
	
}
