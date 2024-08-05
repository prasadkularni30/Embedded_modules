/*
>>2 In the above question extend the program to have pipe to 
    have bi-directional communication.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>




int main()
{
	int ret,ret1,status,pfd1[2],pfd2[2];
	char buff[50];

	if((ret=pipe(pfd1))<0){ printf("Pipe 1 Failed\n"); exit(0);}
	
	if((ret=pipe(pfd2))<0){ printf("Pipe Failed\n"); exit(0);}
	
	if((ret=fork())<0){ printf("fork Failed\n"); exit(0);}

	if(ret==0)
	{

		close(pfd1[0]);
		close(pfd2[1]);

		ret1=read(pfd2[0],buff,512);

		write(STDOUT_FILENO,buff,ret1);

		printf("In Child Proces 1|PID: %d,PPID: %d\n",getpid(),getppid());
		printf("Received Message: %s\n",buff);
		
		bzero(buff,sizeof(buff));

		printf("Enter Message 2:");
		scanf("%[^\n]",buff);

		write(pfd1[1],buff,strlen(buff));

		close(pfd2[0]);
		close(pfd1[1]);

	}
	else if(ret>0)
	{
		
		if((ret1=fork())<0){ printf("Pipe 1 Failed\n"); exit(0);}
		
		if(ret1==0)
		{
			
			close(pfd1[1]);
			close(pfd2[0]);
			
			printf("Enter Message 1: ");
			scanf("%[^\n]s",buff);
			
			write(pfd2[1],buff,strlen(buff));
			
			bzero(buff,sizeof(buff));

			ret=read(pfd1[0],buff,512);
			//write(STDOUT_FILENO,buff,ret);
			printf("\n");
			printf("In Child Process 2|PID: %d,PPID: %d\n",getpid(),getppid());
			printf("Received Message: %s\n",buff);

			close(pfd1[0]);
			close(pfd2[1]);
		}
		else if(ret1>0)
		{
			printf("In Parent process | PID: %d,PPID: %d\n",getpid(),getppid());

			waitpid(ret1,&status,0);
			waitpid(ret1,&status,0);
			printf("Bi-directional Pipe Successfull\n");
		}

	}
}
