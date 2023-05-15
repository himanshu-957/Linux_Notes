#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
        int pid;
	int stat;
        char buf[100];
        pid = fork();
        if(pid==0)
        {
                printf("Child Terminating\n");
		exit(10);
        }
        else
        {
                int childpid = waitpid(pid, &stat, 0);
		printf("my child terminated with status %d\n", WEXITSTATUS(stat));
                printf("Parent terminating\n");
        }
        return 0;
}

