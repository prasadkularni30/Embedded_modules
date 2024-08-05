#include<stdio.h>
       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/msg.h>
#include<stdlib.h>

#define KEY1 101


struct message
{
	long int type;
	char buff[100];
};


int main()
{
	struct message msg;
	int id;
	
	
	id=msgget(KEY1, 0666| IPC_CREAT);
	if(id<0)
	{
		printf("Failed to create M_que");
		exit(0);
	}
	
	
	if((msgrcv(id,&msg,sizeof(struct message),1,0))<0)
	{
		perror("msgsnd");
		exit(0);	
	}
	
	
	printf("Message received successfully\n");
	printf("Message : %s\n Type: %ld\n",msg.buff,msg.type);
	
	
	return 0;
}
