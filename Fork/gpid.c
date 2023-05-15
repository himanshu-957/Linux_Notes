#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("My process pid = %d\n", getpid());
	printf("My parent pid = %d\n", getppid());
	printf("Linux Kernel\n");
	while(1);
	return 0;
}
