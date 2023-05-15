#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int p[2];
	pipe(p);
	printf("Read end of pipe = %d \t Write end of the file = %d\n", p[0], p[1]);
	if(fork())
	{
		char s[20];
		printf(" In parent Enter data.....\n");
		scanf("%s", s);
		write(p[1],s,strlen(s)+1);
	}
	else
	{
		char buff[20];
		printf("In child....\n");
		read(p[0], buff, sizeof(buff));
		printf("Child pro printing..Data. of the parent process...%s\n",buff);
	}
	return 0;
}
