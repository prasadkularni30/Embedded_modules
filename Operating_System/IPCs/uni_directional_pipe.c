/*>>1 Create a program, have 2 child created from the parent
    process and establish pipe ipc between 2 childs.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<string.h>




int main()
{
	int ret,ret1,status,pfd[2];
	char buff[50];

	if((ret=pipe(pfd))<0)
	{
		printf("Pipe creation failed\n");
		exit(0);
	}

	if((ret=fork())<0)
	{
		printf("Fork creation failed\n");
		exit(0);
	}

	if(ret==0)
	{
		printf("In child process 1|PID: %d,PPID: %d\n",getpid(),getppid());
		
		close(pfd[1]);

		ret1=read(pfd[0],buff,512);
		write(STDOUT_FILENO,buff,ret1);
		printf("\n");
		
		printf("read success\n");
		close(pfd[0]);
	}
	else if(ret>0)
	{
		
		if((ret1=fork())<0)
		{
			printf("Fork creation failed\n");
			exit(0);
		}
		if(ret1==0)
		{
			printf("In child process 2|PID: %d,PPID: %d\n",getpid(),getppid());
		
			close(pfd[0]);
			
			printf("Enter Message: ");
			scanf("%[^\n]s",buff);
			
			write(pfd[1],buff,strlen(buff));

			close(pfd[1]);
		}
		else if(ret1>0)
		{
			printf("In Parent Process |PID: %d,PPID: %d\n",getpid(),getppid());

			waitpid(ret,&status,0);
			//waitpid(ret,&status,0);
			
			printf("Pipe Successful\n");
			
		}
	}
}
