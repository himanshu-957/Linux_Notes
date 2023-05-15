#include<stdio.h>
#include<pthread.h>
#define THD_NUM 2

void * task(void * arg)
{
	sleep(1);
	printf("FINISHED TASK\n");
}

int main()
{
	pthread_t th[THD_NUM];
	int i;
	for(i = 0; i < THD_NUM; i++)
	{
		if(pthread_create(&th[i],NULL,task,NULL)!=0)
		{
			perror("Failed to create\n");
		}
		pthread_detach(th[i]);
	}
	for(i = 0; i < THD_NUM; i++)
	{
		if(pthread_join(th[i], NULL)!=0)
		{
			perror("Failed to join\n");
		}
	}
	//return 0;
	pthread_exit(0); //when pthd_exit() main process, process will wait for thds execution.
	// this is different behaviour of pthread_exit();
}
