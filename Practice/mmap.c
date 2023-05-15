#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/mman.h>
int main()
{
	char *c;
	int fd;
	struct stat st; 
	fd = open("linux.txt", O_RDWR | O_CREAT, 0777);
	write(fd, "linux kernel",12);
	fstat(fd, &st);
	int siz = st.st_size;
	c = mmap(0,siz, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	perror("Mmap");
	printf("%s\n",c);
	munmap(c, siz);
	return 0;
}
