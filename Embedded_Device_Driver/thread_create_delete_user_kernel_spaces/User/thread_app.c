/* User space app to test IOCTL */

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include <errno.h>

#include "../Kernel/my_ioctls.h"

#define DEV	"/dev/threads_dev"


int main()
{
	int fd = open(DEV, O_RDWR);
	if (fd<0)
	{
		perror("Cannot open device file");
		exit(EXIT_FAILURE);
	}

	int ans = ioctl(fd, START_DEVICE, NULL);
	if (ans<0)
	{
		perror("IOCTL START TIMER failure");
		close(fd);
		exit(EXIT_FAILURE);
		
	}
	
	sleep(10);
	
	ans = ioctl(fd, STOP_DEVICE, NULL);
	if (ans<0)
	{
		perror("IOCTL STOP TIMER failure");
		close(fd);
		exit(EXIT_FAILURE);
		
	}
	close(fd);


	return (EXIT_SUCCESS);
}

