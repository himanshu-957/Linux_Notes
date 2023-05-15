#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
void * start_one(void *arg)
{
	int i;
	for(i = 0; i < 100; i++)
		printf("Thd of control 1\n");
}

void * start_two(void *arg)
{
	int i;
	for(i =0; i < 100; i++)
		printf("** Thd of Control 2\n");
}

void* thread1(void *arg)
{
	sleep(1);
	printf("newly created thread is executing\n");
	return NULL;
}

int main(void)
{
	pthread_t pt1, pt2;
	getchar();
	pthread_create(&pt1, NULL, start_one, NULL);
	pthread_create(&pt2, NULL, start_two, NULL);
	getchar();
	return 0;
}
