#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
pthread_once_t pthread = PTHREAD_ONCE_INIT;
void *myinit()
{
	printf("Only one time\n");
}
void *thread1(void)
{
	printf("Inside thread 1 PID : %d\n",pthread_self());
	sleep(2);
	pthread_once(&pthread, myinit);
	pthread_exit((void *)1);
}
void *thread2(void)
{
	printf("Inside thread 2 PID : %d\n",pthread_self());
	sleep(2);
	pthread_exit((void *)2);
}
int main()
{
	pthread_t td1, td2, td3;
	void *tret;
	pthread_create(&td1,NULL,thread1,NULL);
	pthread_create(&td2,NULL,thread2,NULL);
	pthread_create(&td3,NULL,thread1,NULL);
	pthread_join(td2,&tret);
	printf("Thread2 exited: %d\n",(int)tret);
	pthread_join(td1,&tret);
	printf("Thread 1 exited: %d\n",(int)tret);
	exit(0);
}
