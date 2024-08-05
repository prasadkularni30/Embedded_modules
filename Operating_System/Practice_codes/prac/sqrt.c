#include<stdio.h>
#include <pthread.h>
#include<math.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdlib.h>
#include<string.h>

struct msg_que
{
	long mtype;
	char mesg[10];
};

double sqrr,numm;

void * thread1_fun(void *);
void * thread2_fun(void *);

int main()
{
	int id,ret;
	pthread_t thread1,thread2;
	void *retv1,*retv2;

	key_t KEY = ftok("exam_prac.c",11);
	id=msgget(KEY, 0666|IPC_CREAT);

	ret=pthread_create(&thread1,NULL,thread1_fun,(void *)&id);
	ret=pthread_create(&thread2,NULL,thread2_fun,(void *)&id);

	pthread_join(thread1,&retv1);
	pthread_join(thread2,&retv2);

	printf("\nNumber: %.0lf\n",*(double *)retv2);
	printf("Square Root: %.2lf\n",*(double *)retv1);

	msgctl(id,IPC_RMID,NULL);
	return 0;
}

void * thread1_fun(void *arg)
{
	int *id=(int *)arg;
	int num;
	int ret;
	struct msg_que msg1,msg2;
	char buff[10];
	printf("Enter Integer: ");
	scanf("%d",&num);
	
	msg1.mtype=1;
	sprintf(msg1.mesg,"%d",num);
	ret=msgsnd(*id,&msg1,sizeof(struct msg_que),0);
	printf("Message sent by thread1\n");

	ret=msgrcv(*id,&msg2,sizeof(struct msg_que),2,0);
	printf("Message received by thread1\n");
//	printf("msg2 %s\n",msg2.mesg);

	sqrr=atof(msg2.mesg);
//	printf("convert t1 %f\n",sqr);

	pthread_exit((void *)&sqrr);
}
void * thread2_fun(void *arg)
{
	int *id=(int *)arg;
	int ret;
	double sqr;
	struct msg_que msg1,msg2;
	char buff[10];

	ret=msgrcv(*id,&msg1,sizeof(struct msg_que),1,0);
	printf("Message received by thread2\n");
//	printf("msg1 %s\n",msg1.mesg);
	numm=atof(msg1.mesg);
	
	sqr=sqrt(numm);
//	sqr=sqrtf(num);


	msg2.mtype=2;
	sprintf(msg2.mesg,"%lf\n",sqr);
	
	ret=msgsnd(*id,&msg2,sizeof(struct msg_que),0);
	printf("Message sent by thread2\n");
	
//	printf("convert t2 %f\n",num1);
	pthread_exit((void *)&numm);
}
