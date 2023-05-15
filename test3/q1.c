#include<unistd.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
        struct shmid_ds buf;
        size_t s = 20;
        int shmid;
	int *a;
        shmid = shmget(555,s, 0666|IPC_CREAT);
        printf("Shared memory created with ID: %d\n", shmid);
        a = shmat(shmid, 0, 0);
        printf("Address at which shared memory segment starts: 0x%x\n",a);
        return 0;
}

