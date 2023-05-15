#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *Proc(void)
{
        printf("\nGoing into infinite loop\n");
        printf("Waiting for pthread_Cancel\n");
        while(1);
}

int main()
{
        pthread_t thread;
        int r, t =0 ;
        r = pthread_create(&thread, NULL, Proc, NULL);
        printf("\n Thread ID : %u",thread);
        sleep(5);
        t = pthread_cancel(thread);
        if(t==0)
                printf("\nThread Succesfully cancelled\n");
}

