#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd3;
	fd3 = creat("add.c", 777);
	printf("fd returned by kernel for add.c =  %d\n", fd3);
	close(fd3);

}
