#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
       #include <unistd.h>

#define KEY 1000

struct shm_memory
{
	int x;
	int y;
	int z;
};


int main()
{
	struct shm_memory *shm;
	int ret,id;
	
	id=shmget(KEY,sizeof(struct shm_memory),IPC_CREAT | 0666);
	if(id<0)
	{
		perror("shmget");
		exit(0);
	}
	
	shm=shmat(id,0,0);
	
	shm->x=10;
	shm->y=20;

	while(1);
	
	sleep(1);
	shmctl(id,IPC_RMID,0);

}
