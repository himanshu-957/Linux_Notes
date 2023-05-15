#include<signal.h>
#include<stdio.h>

void sighand(int sig_num)
{
	printf("abort signal rec'd \n");
	printf("We can use this to perform clean up op's\n");
}

main()
{
	signal(SIGABRT, sighand);
	printf("Some thing has gone wrong\n");
	abort();

	printf(" can you see this\n");
	printf(" can you see this\n");
	printf(" can you see this\n");
}
