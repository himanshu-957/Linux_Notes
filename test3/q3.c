#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void sig_handler(int sig1)
{
        printf("Signal handler got called for %d signal\n", sig1);
        (void)signal(sig1, SIG_DFL);
}

int main()
{
        (void)signal(SIGABRT, sig_handler);
        printf("PID of this process is %d\n", getpid());
        while(1){
                printf("Process running\n");
                sleep(1);
        }
	return 0;
}

