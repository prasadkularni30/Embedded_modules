#include<stdio.h>
#include <pthread.h>


typedef struct {
	int x;
	char y;
	char *z;
}parameter;

int flag=1;

void* thread_fun(void *arg)
{
	
	parameter *para_1=(parameter *)arg;
	//int temp=((parameter *)arg)->x;
	
	int a=5,b=6;
	printf("A= %d\n",a);
	printf("B= %d\n",b);
	printf("Addition= %d\n",a+b);
	printf("==============================================\n");
	printf("Alphabets: ");
	for(int i=65;i<=90;i++)
		printf("%c ",i);
	printf("\n");
	
	printf("==============================================\n");
	
	
	printf("Structure variable x= %d\n",para_1->x);
	printf("Structure variable y= %c\n",para_1->y);
	printf("Structure variable z= %s\n",para_1->z);
	printf("Flag= %d\n",flag);
	
	if(flag==1)
	{
		para_1->x=90;
		para_1->y='z';
		para_1->z="Prasad";
		flag=0;
	}
	
	
	/*printf("Structure variable temp= %d\n",temp);
	printf("Structure variable y= %c\n",((parameter *)arg)->y);
	printf("Structure variable z= %s\n",((parameter *)arg)->z);*/
	while(1);

}





int main()
{
	pthread_t thread1,thread2;
	void* (*f_ptr)() = thread_fun;
	parameter para;
	para.x=10;
	para.y='a';
	para.z="Hello World";
	
	int val1=pthread_create(&thread1,NULL,f_ptr,&para);
	int val2=pthread_create(&thread2,NULL,f_ptr,&para);
	
	//void **x;
	
	if(!val1)
		printf("Thread1 created successfully\n");
	else
		printf("Thread1 creation failed\n");
		
	
	if(!val2)
		printf("Thread2 created successfully\n");
	else
		printf("Thread2 creation failed\n");
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	//printf("Exiting..\n");
	//printf("%d\n",*(int *)*x);
}
