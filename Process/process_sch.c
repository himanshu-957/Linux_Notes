#include<stdio.h>
#include<sched.h>

int main()
{
	int policy;
	printf("my pid is %d\n", getpid());
	policy = sched_getscheduler(0);
	switch(policy)
	{
		case SCHED_OTHER:
			printf("Policy is normal\n");
			break;
		case SCHED_RR:
			printf("Policy is round-robin\n");
		case SCHED_FIFO:
			printf("Policy is first-in, first-out.\n");
		case -1:
			perror("shed_getscheduler");
			break;
		default:
			fprintf(stderr,"Unknown policy!\n");
	}
	getc(stdin);
	struct sched_param sp = {.sched_priority = 1};
	int ret;
	ret = sched_setscheduler(0, SCHED_RR, &sp);
	if(ret == -1)
	{
		perror("Sched_setscheduler");
		return 1;
	}
	policy = sched_getscheduler(0);
	switch(policy)
	{
		case SCHED_OTHER:
			printf("Policy is normal\n");
			break;
		case SCHED_RR:
			printf("Policy is round-robin\n");
		case SCHED_FIFO:
			printf("Policy is first-in, first-out.\n");
		case -1:
			perror("shed_getscheduler");
			break;
		default:
			fprintf(stderr,"Unknown policy!\n");
	}
	getc(stdin);
	while(1);
	return 0;
}
