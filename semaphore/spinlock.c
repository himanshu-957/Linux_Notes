#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>

static pthread_spinlock_t slock;

void *spinlockthread(void *i)
{
        int rc;
        int count = 0;
        printf("entered thread %d, getting spinlock\n",(int *)i);
        rc=pthread_spin_lock(&slock);
        printf("%d thread unlock the spin lock..after 5 sec\n",(int *)i);
        rc=pthread_spin_unlock(&slock);
        printf("%d thread complete\n",(int *)i);
        return NULL;
}
int main()
{
        int rc=0;
        pthread_t thread,thread1;
        if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0)
                perror("init");

        printf("main get spin lock\n");
        rc=pthread_spin_lock(&slock);
        printf("mIN create spin lock\n");
        rc=pthread_create(&thread,NULL,spinlockthread,(int *)1);
        printf("main wait a bit holding spin lock\n");
        sleep(5);
        printf("main now unlock the spin lock\n");
        rc=pthread_spin_unlock(&slock);
        if(rc==0)
                printf("\n main thread successfully unlocked\n");
        else
                printf("\nmain thread unsuccessfully unlocked");
        printf("main wait for the thread to end\n");
        rc=pthread_join(thread,NULL);
        rc=pthread_spin_destroy(&slock);
        printf("main completed\n");
        return 0;
}
