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
	
	msg.type=1;
	printf("Enter message: ");
	scanf("%[^\n]",msg.buff);
	int id;
	
	
	id=msgget(KEY1, 0666| IPC_CREAT);
	if(id<0)
	{
		printf("Failed to create M_que");
		exit(0);
	}
	
	
	if((msgsnd(id,&msg,sizeof(struct message),0))<0)
	{
		perror("msgsnd");
		exit(0);	
	}
	
	printf("Message sent successfully\n");
	
	return 0;
}
