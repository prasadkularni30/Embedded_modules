#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_PATH "/home/desd/pmarch_2024/Prasad_K/OS/n_pipe_file/namepipe"

int main()
{
	int fp;
	char buff[100];
	
	mkfifo(FIFO_PATH,0666);
	
	fp=open(FIFO_PATH,O_WRONLY);
	
	scanf("%[^\n]s",buff);
	
	write(fp,buff,strlen(buff)+1);
	
	close(fp);
	
	//while(1);
	
	unlink(FIFO_PATH);
}
