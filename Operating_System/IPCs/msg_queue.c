#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#define KEY 1552

struct message
{
	long type;
	char buff[50];

};


int main()
{
	int ret,ret1,id,status;
	
	id=msgget(KEY,0600 | IPC_CREAT);
	
	if(id<0){ printf("Que allocation failed\n"); exit(0); }
	
	ret=fork();
	
	if(ret<0)
	{
		printf("Fork failed\n");
		exit(0);
	}
	
	if(ret==0)
	{
		struct message msg;
		
		printf("In child process |PID: %d, PPID: %d\n",getpid(),getppid());
		
		printf("Enter Message: ");
		scanf("%s",msg.buff);
		msg.type=5;
		
		ret1=msgsnd(id,&msg,sizeof(struct message),0);
		
		
	}
	
	if(ret>0)
	{
		struct message msg;
		
		wait(&status);
		
		printf("In parent process |PID: %d, PPID: %d\n",getpid(),getppid());
		
		ret1=msgrcv(id,&msg,sizeof(struct message),5,0);
		
		printf("Received message: %s\n",msg.buff);
	
	}
}
