#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>

int main()
{
	char *c;
	c = mmap(0, 512, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
	perror("mmap");
	strcpy(c, "linuxkernel");
	printf("%s\n", c);
	munmap(c,50);
	return 0;
}
