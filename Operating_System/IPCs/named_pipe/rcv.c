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
	int fd;
	char buff[50];
	
	fd=open(PATH, O_RDONLY);
	
	read(fd,buff,sizeof(buff));
	
	printf("Received Message: %s\n",buff);
	
	close(fd);
}
