#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fd,len;
	int x;
	char write_buff[] = "Linux";

	fd = open("example.txt", O_CREAT | O_RDWR, 0777);
	write(fd, write_buff, strlen(write_buff));
	close(fd);
	return 0;
}
