#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int sharedVar = 0;
int i;
pthread_mutex_t my_mutex;

void *thread_inc1(void *arg)
{
	pthread_mutex_lock(&my_mutex);
	for(i=0;i<100000;i++)
		sharedVar++;
	pthread_mutex_unlock(&my_mutex);
}


void *thread_inc2(void *arg)
{
	pthread_mutex_lock(&my_mutex);
	for(i=0;i<100000;i++)
		sharedVar++;
	pthread_mutex_unlock(&my_mutex);
}

int main()
{
	pthread_t thread1, thread2;
	pthread_mutex_init(&my_mutex,NULL);

	pthread_create(&thread1, NULL, thread_inc1, NULL);
	pthread_create(&thread2, NULL, thread_inc2, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("sharedVar = %d\n", sharedVar);
	return 0;
}
