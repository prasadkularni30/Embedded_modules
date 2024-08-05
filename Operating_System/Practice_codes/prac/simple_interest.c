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



float SI;
int p;
int r;
int t;

pthread_mutex_t mutex;


void * thread1_fun(void *);
void * thread2_fun(void *);


int main()
{
	float *shm;
	int ret1,ret2,shm_id;
	pthread_t thread1,thread2;
	
	key_t KEY=ftok("simple_interest.c",8);
	
	pthread_mutex_init(&mutex,NULL);
	
	printf("Enter Amount: ");
	scanf("%d",&p);
	
	shm_id=shmget(KEY,sizeof(float),IPC_CREAT|0666);
	if(shm_id<0){ perror("shmget"); exit(0); }

	shm=shmat(shm_id,0,0);
	if(shm<0){ perror("shmat"); exit(0); }
	
	
		
	if((ret1=fork())<0){ perror("fork"); exit(0); }
	if(ret1==0)
	{
		pthread_create(&thread1,NULL,thread1_fun,(void *)shm);
		
		pthread_join(thread1,NULL);
	}
	if(ret1>0)
	{
		//wait(NULL);
		if((ret2=fork())<0){ perror("fork"); exit(0); }
		if(ret2==0)
		{
			pthread_create(&thread2,NULL,thread2_fun,(void *)shm);
		
			pthread_join(thread2,NULL);
		}
		if(ret2>0)
		{
			wait(NULL);
			shmctl(shm_id,IPC_RMID,0);
			pthread_mutex_destroy(&mutex);
		}
	}
	
	
}

void * thread1_fun(void *arg)
{

	float *shm=(float *)arg;
	r=2;
	t=3;
	
	//printf("1");
	pthread_mutex_lock(&mutex);
	*shm=(float)(p*r*t)/100;
	pthread_mutex_unlock(&mutex);
	
	
	
	
}
void * thread2_fun(void *arg)
{
	float *shm=(float *)arg;
	//printf("2");
	pthread_mutex_lock(&mutex);
	printf("Simple Interest: %0.2f\n",*shm);
	pthread_mutex_unlock(&mutex);
}



