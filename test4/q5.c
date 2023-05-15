#include<stdio.h>
#include<signal.h>

void check_blocked()
{
        int result;
        sigset_t sig;
        sigprocmask(SIG_BLOCK, NULL, &sig);
        for(int i = 1; i <= 20;i++)
        {
                result = sigismember(&sig,i);
                if(result)
                        printf("signal %d is blocked\n",i);
                else
                        printf("signal %d is not blocked \n",i);
        }
}
main()
{
        sigset_t signal_set;
        sigfillset(&signal_set);
        sigprocmask(SIG_BLOCK|SIG_SETMASK,&signal_set, NULL);
        check_blocked();
}

