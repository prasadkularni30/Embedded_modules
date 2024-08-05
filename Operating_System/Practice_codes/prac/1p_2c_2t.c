/*
Write an user-space application, which will do the following:

a. create 2 children processes, from a common parent

b. create a thread, from each child process

c. create a shared-memory and use it, as user-space pipe IPC

e. one thread must be a producer and another must be a consumer
*/
#include<stdio.h>
#include <pthread.h>
#include<math.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdlib.h>
#include<string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
       #include <unistd.h>
       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/sem.h>


struct shm_mem
{
	int x;
	int y;
};

pthread_mutex_t mutex;
int sem_id;
struct sembuf sb;

void * thread1_fun(void *);
void * thread2_fun(void *);

int main()
{
	int ret1,ret2,id;
	pthread_t thread1,thread2;
	struct shm_mem *shm;
	
	key_t KEY=ftok("exam_q2.c",12);
	id=shmget(KEY,sizeof(struct shm_mem),IPC_CREAT|0666);
	if(id<0){perror("shmget");exit(0);}
	
	shm=shmat(id,0,0);
	if(shm<0){perror("shmat");exit(1);}
	
	sem_id=semget(KEY,1,IPC_CREAT|0666);
	
	ret1=semctl(sem_id,0,SETVAL,0);
	if(ret1<0){perror("semctl");exit(0);}
	
	ret1=semctl(sem_id,0,GETVAL);
	
	printf("sem_id val: %d\n",ret1);
	
	shm->x=0;
	shm->y=0;	
	//printf("Hii\n");
	pthread_mutex_init(&mutex,NULL);
	
	//printf("Hiiz\n");
	if((ret1=fork())<0){perror("fork"); exit(0);}

	//printf("Hiiy\n");
	if(ret1==0)
	{
	
		printf("I am child1\n");
		
		//printf("Hii1\n");
		pthread_create(&thread1,NULL,thread1_fun,(void *)shm);
			
		pthread_join(thread1,NULL);
	
	}
	if(ret1>0)
	{
	
		printf("I am parent\n");
		if((ret2=fork())<0){perror("fork"); exit(1);}

		if(ret2==0)
		{
		
			printf("I am child2\n");
			//printf("Hii2\n");

			pthread_create(&thread2,NULL,thread2_fun,(void *)shm);
		
			pthread_join(thread2,NULL);
		}
		if(ret2>0)
		{
			wait(NULL);
			wait(NULL);
			shmctl(id,IPC_RMID,NULL);
			pthread_mutex_destroy(&mutex); 

		}
	}
}


void * thread1_fun(void *arg)
{
	
	struct shm_mem *shm=(struct shm_mem *)arg;

	int a=0,b=0;

 
	for(int i=0;i<10;i++)
	{
	/*	sb.sem_num=0;
		sb.sem_op=-1;
		sb.sem_flg=0;
		
		semop(sem_id,&sb,1);*/
		
		pthread_mutex_lock(&mutex);
		shm->x=a;
		shm->y=b;
		pthread_mutex_unlock(&mutex);
		
		sb.sem_num=0;
		sb.sem_op=+1;
		sb.sem_flg=0;
		
		semop(sem_id,&sb,1);
		a++;
		b++;
		sleep(1);
		//printf("A t1: %d\nB t2: %d\n\n",a,b);
	}
	
	pthread_exit(NULL);

}
void * thread2_fun(void *arg)
{
	struct shm_mem *shm=(struct shm_mem *)arg;

	int a=0,b=0;


	for(int i=0;i<10;i++)
	{
		sb.sem_num=0;
		sb.sem_op=-1;
		sb.sem_flg=0;
		
		semop(sem_id,&sb,1);
		
		pthread_mutex_lock(&mutex);
		a=shm->x;
		b=shm->y;
		pthread_mutex_unlock(&mutex);
		/*sb.sem_num=0;
		sb.sem_op=+1;
		sb.sem_flg=0;
		
		semop(sem_id,&sb,1);*/
		
		
		printf("A: %d\nB: %d\n\n",a,b);
		sleep(1);
	
	}
	
	pthread_exit(NULL); 
		

}
