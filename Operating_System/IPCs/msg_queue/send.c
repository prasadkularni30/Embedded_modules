/*
>>3 Write a program to implement the message-queue IPC.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define KEY1 1550
#define KEY2 1551

struct message{
	long type;
	char buff[50];

}msg,msg1;


int main()
{
	int ret,id,id1;
	char buff[50];
	id=msgget(KEY1,0666|IPC_CREAT);
	id1=msgget(KEY2,0666|IPC_CREAT);
	
	printf("Enter Message: ");
	scanf("%[^\n]s",msg.buff);
	msg.type=1;

	ret=msgsnd(id,&msg,sizeof(struct message),0);	
	
	printf("Message sent\nWaiting for aknowledgement\n");
	ret=msgrcv(id1,&msg1,sizeof(struct message),2,0);
	
	printf("ACK received \nMessage Sent successfully\n");
}
