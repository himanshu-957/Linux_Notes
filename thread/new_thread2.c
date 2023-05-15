#include<pthread.h>
#include<stdio.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void myinit()
{
	printf("\nI am in INIT FUNCTION\n");
}

void *mythread(void *i)
{
	printf("\nI am in my thread: %d\n",(int *)i);
	pthread_once(&once, myinit);
	printf("\nExit from mythread: %d\n",(int *)i);
}

int main()
{
	pthread_t thread, thread1, thread2;
	pthread_create(&thread, NULL, mythread, (void *)1);	
	pthread_create(&thread1, NULL, mythread, (void *)2);
	pthread_create(&thread2, NULL, mythread, (void *)3);
	pthread_exit(NULL);
}
