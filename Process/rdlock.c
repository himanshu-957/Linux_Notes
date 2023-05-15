#include<pthread.h>
#include<stdio.h>

pthread_rwlock_t rwlock;

void *rdlockThread(void *i)
{
	int rc;
	int count = 0;
	printf("Entered %d thread, getting read lock\n",(int *)i);
	Retry:
	rc = pthread_rwlock_tryrdlock(&rwlock);
	printf("%d Thread unlock the read lock\n",(int *)i);
	rc = pthread_rwlock_unlock(&rwlock);
	if(rc==0)
		printf("\n successfuly Unlocked \n");
	else
		printf("\n Unsuccesfully Unlocked\n");
	printf("Secondary thread complete\n");
	return NULL;
}
int main()
{
	int rc = 0;
	pthread_t thread;
	if(pthread_rwlock_init(&rwlock,NULL)!=0)
		perror("init");
	printf("Main, get the write lock\n");
	rc = pthread_rwlock_wrlock(&rwlock);

	printf("Main, create the try read lock thread\n");
	rc = pthread_create(&thread,NULL,rdlockThread, (void *)1);

	printf("Main, wait a bit holding the write lock\n");
	sleep(5);

	printf("Main, Now unlock the write lock\n");
	rc = pthread_rwlock_unlock(&rwlock);

	printf("Main, wait for the thread to end\n");
	rc = pthread_join(thread, NULL);

	rc = pthread_rwlock_destroy(&rwlock);
	printf("Main completed\n");
	return 0;
}

