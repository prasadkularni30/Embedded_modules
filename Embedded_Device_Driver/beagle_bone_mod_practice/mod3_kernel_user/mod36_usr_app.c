/* User space file to test userspace / kernelspace data exchange module */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <errno.h>

#include "mod36_header.h"

#define DEV	"/dev/cdac_dev"


struct common usr1,usr2;

int main()
{
	int fd = open(DEV, O_RDWR);
	if (fd<0)
	{
		perror("Cannot open device file");
		exit(EXIT_FAILURE);
	}
	strcpy(usr1.name,"Prasad");
	strcpy(usr1.address,"Beed India");
	usr1.phone=911956;


	ssize_t nwrite = write(fd, &usr1, sizeof(struct common));

	//char *buf1 = (char *)calloc((strlen(buf)+1), sizeof(char));
	
	int nread = read(fd, (void *)&usr2, sizeof(struct common));
	write(STDOUT_FILENO, usr2.name, strlen(usr2.name));
	printf("\n");
	write(STDOUT_FILENO, usr2.address, strlen(usr2.address));
	printf("\n");
	printf("%ld",usr2.phone);
	printf("\n");
	
	close(fd);


	return (EXIT_SUCCESS);
}

