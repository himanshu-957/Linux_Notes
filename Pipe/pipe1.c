#include<stdio.h>

int main()
{
	int fds[2],ii,n;
	char readbuff[100];
	char writebuff[100];

	if(pipe(fds)<0)
	{
		perror("pipe creation failed\n");
		exit(1);
	}
	if(fork()==0)
	{
		close(fds[1]);
		while(1)
		{
			n = read(fds[0],readbuff,100);
			printf("Read from fds[0] and output to screen:\n");
			for(ii=0;ii<n;ii++)
				readbuff[ii] = toupper(readbuff[ii]);
			puts(readbuff);
		}
	}
	close(fds[0]);
	while(1)
	{
		fgets(writebuff,100,stdin);
		write(fds[1],writebuff,strlen(writebuff)+1);
		printf("Wrote to fds[1]:\n");
	}
}
