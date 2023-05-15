#include<signal.h>
#include<stdio.h>
void sighand(int signum)
{
	printf("I have to wake up my boss now\n");
	alarm(5);
}

main()
{
	signal(SIGALRM, sighand);
	alarm(5);
	printf("\n HELLO\n");
	while(1){
	}
}
