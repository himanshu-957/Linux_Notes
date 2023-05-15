#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
int main()
{
	int fd;
	char *buf;
	fd = open("linux.txt", O_RDWR | O_CREAT, 0777);
	write(fd, "Linux Kernel Technology", 23);
	int pid = fork();
	if(pid == 0)
	{
		//wait(1);
		read(fd,buf,23);
		printf("%s\n",buf);
		printf("Child Terminating\n");
	}
	else
	{
		
		printf("Parent terminating\n");
	}
	while(1);
	return 0;

}
