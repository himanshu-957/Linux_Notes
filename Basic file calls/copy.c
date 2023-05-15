#include<stdio.h>
#include<fcntl.h>
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
	int inputFd, outputFd, openFlags;
	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE];

	inputFd = open(argv[1],O_RDONLY);
	if(inputFd == -1)
	{
		printf("Open Error\n");
		return;
	}

	outputFd = open(argv[2],O_RDWR, 777);
	if(outputFd == -1)
	{
		printf("Opening file\n");
		return;
	}

	while((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
	{
		if(write(outputFd, buf, numRead) != numRead)
		{
			printf("Write Error\n");
			return;
		}
		printf("%d\n",numRead);
	}
	if(numRead == -1)
	{
		printf("Read Error\n");
		return;
	}
	if(close(inputFd) == -1)
	{
		printf("Close input\n");
		return;
	}
	if(close(outputFd) == -1)
	{
		printf("Close output\n");
		return;
	}
}
