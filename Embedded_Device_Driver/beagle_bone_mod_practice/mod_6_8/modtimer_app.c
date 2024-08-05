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

#define DEV	"/dev/cdac_dev"
#define BUF_SZ	(10)

int main()
{
	int fd = open(DEV, O_RDWR);
	if (fd<0)
	{
		perror("Cannot open device file");
		exit(EXIT_FAILURE);
	}

	int ans = ioctl(fd, START_TIMER, NULL);
	if (ans<0)
	{
		perror("IOCTL START TIMER failure");
		exit(EXIT_FAILURE);
		close(fd);
	}
	
	sleep(60);
	
	ans = ioctl(fd, STOP_TIMER, NULL);
	if (ans<0)
	{
		perror("IOCTL STOP TIMER failure");
		exit(EXIT_FAILURE);
		close(fd);
	}
	close(fd);


	return (EXIT_SUCCESS);
}

