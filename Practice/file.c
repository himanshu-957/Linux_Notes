#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd,size,fd1;
	char buf[10] = "LINUX";
	char buf1[10];
	fd1 = open("outpput.txt",O_RDWR | O_CREAT, 0777);
	//fd = creat("linux.txt",0777);
	fd = open("linux.txt", O_RDWR, 0777);
	dup2(fd1,1);
	printf("%d\n",fd);
	size = write(fd, buf, 10);
	printf("%d written to file\n",size);
	lseek(fd,0,SEEK_SET);
	size = read(fd, buf1, 10);
	printf("%d size and %s is read\n",size,buf1);
	write(1,"Hello\n",6);
	close(fd);
	close(fd1);
	return 0;
}
