#include<fcntl.h>
#include<stdio.h>
int main()
{
	int fd;
	fd = open("example.txt",O_RDONLY);
	printf("%d\n",fd);
	return 0;
}
