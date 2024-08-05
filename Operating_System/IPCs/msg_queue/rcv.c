
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define KEY1 1550
#define KEY2 1551


struct message
{
	long type;
	char buff[50];

}msg,msg1;


int main()
{
	int id,id1,ret;

	id=msgget(KEY1,0666|IPC_CREAT);
	id1=msgget(KEY2,0666|IPC_CREAT);

	ret=msgrcv(id,&msg,sizeof(struct message),1,0);

	printf("Message receive: %s\n",msg.buff);

	msg1.type=2;
	strcpy(msg1.buff,"received");
	
	ret=msgsnd(id1,&msg1,sizeof(struct message),0);

}
