#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>

int shared;
sem_t mysem;

void *thread_increment1(void *arg)
{
        sem_wait(&mysem);
        for(int i=0;i<100;i++)
                shared++;
        sem_post(&mysem);
}


void *thread_increment2(void *arg)
{
        sem_wait(&mysem);
        for(int i=0;i<100;i++)
                shared++;
        sem_post(&mysem);
}

int main()
{
        pthread_t td1, td2;
        sem_init(&mysem,0,1);
        pthread_create(&td1, NULL, thread_increment1, NULL);
        pthread_create(&td2, NULL, thread_increment2, NULL);
        pthread_join(td1, NULL);
        pthread_join(td2, NULL);
        printf("Two process synchronised and incremented shared variable value by %d\n", shared);
        return 0;
}
  
