#include<fcntl.h>

int main()
{
	int fd;
	fd = open("dumpdemo.txt",O_RDWR | O_CREAT | O_TRUNC, 0660);
	if(fd < 0)
	{
		printf("Could not open file\n");
		exit(2);
	}
	dup2(fd,1);
	printf("sample string 1\n");
	printf("sample string two\n");
	puts("sample string three\n");
}
