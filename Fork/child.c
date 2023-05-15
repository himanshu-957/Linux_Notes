#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;
	int pid;
	char buf[100];
	fd = open("linux.txt",O_RDWR | O_CREAT, 0777);
	write(fd, "linux kernel technology",23);
	pid = fork();
	if(pid==0)
	{
		lseek(fd,0,SEEK_SET);
		read(fd,buf,23);
		printf("Readed: %s\n",buf);
		printf("Child Terminating\n");
	}
	else
	{
		wait(5);
		printf("Parent terminating\n");
	}
	return 0;
}
