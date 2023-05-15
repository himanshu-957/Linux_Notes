#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
        pid_t id;
        int op, stat;

        while(1)
        {
                printf("1 to exec 'ps' and 0 to exit\n");
                scanf("%d",&op);
                if(!op)
                        exit(0);
                if(fork()==0)
                {
                        execl("./ps","ls",0);
                        exit(5);
                }
                id = wait(&stat);
                printf("%d\n",WEXITSTATUS(stat));
                printf("Child pid %d terminated\n",id);
        }
	return 0;
}

