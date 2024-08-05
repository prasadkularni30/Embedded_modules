#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<pthread.h>
#include<unistd.h>

void *jiffies_read(void*);
void *ID_read_write(void*);
void *foo_write(void*);

#define PRN_SIZE 13

int main(int argc, char *argv[])
{	
	if(argc<3)
	{
		printf("provide all data to store\n");
		exit(0);
	}
	pthread_t jiffies_thread;
	pthread_t ID_thread;
	pthread_t foo_thread;
	
	if( pthread_create(&jiffies_thread, NULL, jiffies_read, NULL) < 0)
	{
		printf("Jiffies Thread Not Created\n");
	}

	if( pthread_create(&ID_thread, NULL, ID_read_write, (void*)argv[1]) < 0)
	{
		printf("ID thread Not created\n");
		exit(0);
	}

	if( pthread_create(&foo_thread, NULL, foo_write, (void*)argv[2]) < 0)
	{
		printf("foo thread not created\n");
		exit(0);
	}
	
	pthread_join(jiffies_thread, NULL);
	pthread_join(ID_thread, NULL);
	pthread_join(foo_thread, NULL);

	return 0;
}


void *jiffies_read(void *parameter)
{
	printf("In Jiffies Read\n");
	unsigned long long jiffies;
	int file_desc = open("/sys/kernel/my_sysfs/jiffies", O_RDONLY);

	if(file_desc<0)
	{
		printf("Could not open jiffies\n");
		return NULL;
	}

	if( read(file_desc, &jiffies, sizeof(jiffies)) < 0)
	{
		printf("Read Failed\n");
	}
	else
	{
		printf("Jiffies = %lld\n", jiffies);
	}
	close(file_desc);
}

void *ID_read_write(void *write_data)
{
	char *data = (char*)write_data;
	printf("Data to write = %s\n", data);
	
	int file_desc = open("/sys/kernel/my_sysfs/ID", O_WRONLY);
	if(file_desc < 0)
	{
		printf("Id file failed\n");
		return NULL;
	}
	if(write(file_desc, data, strlen(data)) < 0)
	{
		printf("Write ID \n");
	}
	else
	{
		printf("Write ID Successful\n");
	}
	close(file_desc);


	printf("Now Reading ID\n");
	file_desc =  open("/sys/kernel/my_sysfs/ID", O_RDONLY);
	if(file_desc < 0)
	{
		printf("Could not open ID to read\n");
		return NULL;
	}
	if(read(file_desc, data, PRN_SIZE) < 0)
	{
		printf("Could not read ID\n");
	}
	else
	{
		printf("ID = %s\n", data);
	}
	close(file_desc);
}

void *foo_write(void* data)
{
	char *write_data = (char*) data;
	int file_desc = open("/sys/kernel/my_sysfs/foo", O_WRONLY);
	if(file_desc < 0)
	{
		printf("Open foo failed\n");
		return NULL;
	}

	if( write(file_desc, write_data, strlen(write_data)) < 0)
	{
		printf("Write foo Failed\n");
	}
	else
	{
		printf("Wrote Data foo\n");
	}
	close(file_desc);
}

