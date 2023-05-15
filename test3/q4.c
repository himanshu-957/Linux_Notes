#include<stdio.h>
#include<signal.h>

void check_blocking_signals()
{
        int result;
        sigset_t sig;
        sigprocmask(SIG_BLOCK, NULL, &sig);
        for(int i = 1; i <= 10;i++)
        {
                result = sigismember(&sig,i);
                if(result)
                        printf("BLOCKED signal is %d\n",i);
                else
                        printf("UNBLOCKED signal is %d\n",i);
        }
}
main()
{
        sigset_t signal_set;
        sigemptyset(&signal_set);
        sigaddset(&signal_set,1);
	sigaddset(&signal_set,5);
        sigaddset(&signal_set,9);
        sigprocmask(SIG_BLOCK|SIG_SETMASK,&signal_set, NULL);
	printf("\n\n******AFTER BLOCKING****** \n\n");
        check_blocking_signals();
        sigprocmask(SIG_UNBLOCK, &signal_set, NULL);
	printf("\n\n*****AFTER UNBLOCKING******\n\n");
        check_blocking_signals();
}

