
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <arpa/inet.h>


int main(int argc, char *argv[])
{
	if (argc < 3)
	{	
		printf("Usage: %s <serv_ip> <serv_port>\n", argv[0]);
		exit(1);
	}

	int cfd, serv_port;
	serv_port = strtoul(argv[2], NULL, 10);
	
	if ((cfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket");
		exit(2);
	}

	struct sockaddr_in saddr = {0};
	saddr.sin_family = AF_INET; 
	saddr.sin_port = htons(serv_port); 
	saddr.sin_addr.s_addr = inet_addr(argv[1]);

	
	
	 if (connect(cfd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
	{
		perror("connect");
		close(cfd);
		exit(3);
	}

	if (send(cfd, "Hello", strlen("Hello"), 0) < 0)
	{
		perror("send");
		close(cfd);
		exit(4);
	}

	char buf[20] = {0};
	if (recv(cfd, buf, sizeof(buf), 0) < 0)
	{
		perror("recv");
		close(cfd);
		exit(5);
	}

	printf("Data received: %s\n", buf);

	close(cfd);

	return 0;
}
