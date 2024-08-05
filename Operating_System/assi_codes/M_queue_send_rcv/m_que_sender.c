#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

#define KEY 1001

struct message {
    long mtype;
    char mesg[100];
};

int main()
{
	int msgq_id, ret1;
	struct message msg;


	// Create or get the message queue
    	msgq_id = msgget(KEY, 0666 | IPC_CREAT);
	if(msgq_id<0){ perror("msgget"); exit(1); }

	// Prepare the message to send
	msg.mtype = 1;	//message type, must be > 0
	printf("Enter Message: ");
	scanf("%[^\n]s",msg.mesg);
	//strcpy(msg.mesg,"Hello, from sender via message queue!");

	// Send the message
	ret1 = msgsnd(msgq_id, &msg, sizeof(struct message), 0); 
	if(ret1<0){ perror("msgsnd"); exit(1); }

	printf("Message sent successfully.\n");

	return 0;
}
