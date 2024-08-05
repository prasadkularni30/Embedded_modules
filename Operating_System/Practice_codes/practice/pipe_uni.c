#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int pfd[2];
	int ret1;
	char buff[512];
	int ret=pipe(pfd);
	if(ret<0){ printf("Pipe failed\n"); exit(0); }
	
	ret=fork();
	if(ret<0){ printf("Fork failed\n"); exit(0); }
	
	if(ret==0)
	{
		close(pfd[1]);
		
		while((ret1=read(pfd[0],buff,512))>0)
		{
			write(STDOUT_FILENO,buff,ret1);
		}
		close(pfd[0]);
	}
	else if(ret>0)
	{
		close(pfd[0]);
		scanf("%[^\n]s",buff);
		write(pfd[1],buff,strlen(buff)+1);
		
		close(pfd[1]);
	}
}
