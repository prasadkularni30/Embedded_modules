/* User space app to test IOCTL */

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include <errno.h>

#include "my_ioctls.h"

#define DEV	"/dev/linked_list_dev"
#define LEN	"/sys/module/mod_ioctl_link/parameters/list_length"
#define BUF_SZ	(10)

int main()
{
	int fd = open(DEV, O_RDWR);
	FILE *fd1;
	fd1 = fopen(LEN,"r");
	if (fd<0)
	{
		perror("Cannot open device file");
		exit(EXIT_FAILURE);
	}
	
	int to_send=10;
	int ans,i;
	for(i=0;i<10;i++)
	{
		
		ans = ioctl(fd, WRITE_TO_LIST, (unsigned int *)&to_send);
		if (ans<0)
		{
			perror("IOCTL read failure");
			exit(EXIT_FAILURE);
			close(fd);
		}
		printf("Send value: %d to kernel via IOCTL\n", to_send);
		to_send = to_send+10;
	}
	
	//while(1);
	unsigned int len = 0;
	ans=0;
	//ans=read(fd1,(void *)&len,sizeof(int));
	fscanf(fd1,"%d",&len);
	
	printf("len is: %d\n",len);
	
	int *uarr=(int *)calloc(len,sizeof(int));
	
	ans = ioctl(fd, READ_FROM_LIST,(unsigned int *)uarr);
	if (ans<0)
	{
		perror("IOCTL read failure");
		exit(EXIT_FAILURE);
		close(fd);
	}
	printf("Read success!!\n");
	for(i=0;i<len;i++)
	{
		printf("Node [%d]: %d\n",i+1,uarr[i]);
	}
	printf("\n");
		
	ans = ioctl(fd, DELETE_LIST, NULL);
	if (ans<0)
	{
		perror("IOCTL read failure");
		exit(EXIT_FAILURE);
		close(fd);
	}
	
	printf("Received !!\n");
	free(uarr);
	close(fd);
	fclose(fd1);
	return (EXIT_SUCCESS);
}

