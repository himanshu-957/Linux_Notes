#include<stdio.h>
#include<signal.h>

void check_blocked_sigs()
{
	int i,res;
	sigset_t s;
	sigprocmask(SIG_BLOCK, NULL, &s);
	for(i = 1; i <= 20;i++)
	{
		res = sigismember(&s,i);
		if(res)
			printf("signal %d is blocked\n",i);
		else
			printf("signal %d is not blocked \n",i);
	}
}
main()
{
	sigset_t s_set;
	sigfillset(&s_set);
	sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set, NULL);
	check_blocked_sigs();
	//sigprocmask(SIG_UNBLOCK, &s_set, NULL);
	//check_blocked_sigs();
}
