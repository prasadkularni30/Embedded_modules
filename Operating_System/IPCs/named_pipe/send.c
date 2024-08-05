#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#define PATH "/home/desd/pmarch_2024/Prasad_K/OS/Assi2/Q3/pipe_file"


int main()
{
	int ret,fd;
	char buff[50]={0};
	if(mkfifo(PATH,0666)<0)
	{
		printf("File Creatin failed\n");
		exit(0);
	}
	
	fd=open(PATH, O_WRONLY);
	
	printf("Enter Message: ");
	scanf("%[^\n]s",buff);
	
	write(fd,buff,strlen(buff));
	
	close(fd);
	
	unlink(PATH);

}
