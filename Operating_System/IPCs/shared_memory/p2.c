#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>	
       #include <unistd.h>

#define KEY 1000
	

struct memory
{
	int x;
	int y;
	int z;
};

int main()
{
	struct memory *shm;
	int id,ret;
	
	id=shmget(KEY,sizeof(struct memory),IPC_CREAT | 0666);
	if(id<0)
	{
		perror("shmget");
		exit(0);
	}

	shm=shmat(id,0,0);
	
	printf("shm->x= %d,shm->y= %d\n",shm->x,shm->y);
	shm->z=shm->x+shm->y;
	
	printf("Addition: %d\n",shm->z);
	
}
