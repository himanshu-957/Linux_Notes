#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
	int fd;
	char buff[300];
	int res;
	fd = open("sub.c", O_CREAT|O_RDWR, 664);
	printf("%d\n",fd);
	if(fd<0)
		printf("File is not opened or created\n");
	read(fd,buff,300);

	printf("data from buffer =\n%s\n",buff);
	close(fd);
	return 0;
}
