#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdlib.h>

#define KEY 1001


struct message
{
	long type;
	char buff[100];
};


int main()
{
	struct message msg;
	int msgq_id;
	
	//create of get the message que	
	msgq_id=msgget(KEY, 0666| IPC_CREAT);
	if(msgq_id<0){ perror("msgget"); exit(0); }
	
	//receive message with same type
	if((msgrcv(msgq_id,&msg,sizeof(struct message),1,0))<0)
	{
		perror("msgrcv");
		exit(0);	
	}
	
	
	printf("Message received successfully\n");
	printf("Message : %s\n",msg.buff);
	
	//after receiving message remove the message queue
	msgctl(msgq_id,IPC_RMID,NULL);
	return 0;
}
