#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>



int main()
{
	int pfd1[2],pfd2[2];
	char buff1[100],buff2[100];
	
	int ret=pipe(pfd1);
	int ret1,ret2,flag1=1,flag2=1;
	
	if(ret<0){ printf("Pipe 1 failed\n"); exit(0); }
	
	ret=pipe(pfd2);
	if(ret<0){ printf("Pipe 2 failed\n"); exit(0); }
	
	ret=fork();
	if(ret<0){ printf("fork failed\n"); exit(0); }
	
	
	
	if(ret==0)
	{
		close(pfd1[1]);
		close(pfd2[0]);
		
		//printf("In Child process PID=%d, PPID= %d\n",getpid(),getppid());
		printf("Enter Input from child process:\n");
		scanf("%[^\n]s",buff2);
		
		write(pfd2[1],buff2,strlen(buff2));
		
		close(pfd2[1]);
		
		//while(()>0)
		//{
			//if(flag2==1)
			//{
			printf("child\n");
			//flag2=0;
			//}
			ret1=read(pfd1[0],buff2,100);
			write(STDOUT_FILENO,buff2,ret1);
		//}
		printf("\n");
		//printf("In Child process 2\n");
		close(pfd1[0]);
		
		//while(1);
		
	}
	else if(ret>0)
	{
		close(pfd1[0]);
		close(pfd2[1]);
		//printf("In Parent process PID=%d, PPID= %d\n",getpid(),getppid());
		while((ret2=read(pfd2[0],buff1,100))>0)
		{
			//if(flag1==1)
			//{
			printf("parent\n");
			//flag1=0;
			//}
			write(STDOUT_FILENO,buff1,ret2);
		}
		printf("\n");
		
		close(pfd2[0]);
		
		printf("Enter Input from parent process:\n");
		scanf("%[^\n]s",buff1);
		
		write(pfd1[1],buff1,strlen(buff1));
		//printf("In Parent process 2\n");
		
		close(pfd1[1]);
		//while(1);
	}
	
}
