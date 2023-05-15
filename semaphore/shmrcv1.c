#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<string.h>

#define MY_KEY 1992
#define SHM_SIZE 0x1000
#define MSG_LEN 256

int main()
{
	int semId, shmId;
	char *pShm;
	struct sembuf smop;
	semId = semget(MY_KEY, 1, 0660);
	if(semId < 0)
	{
		printf("Could not create semaphore\n");
		return 1;
	}
	else
		printf("Opened a semaphore. Id is %d\n", semId);
	shmId = shmget(MY_KEY, SHM_SIZE, 0660);
	if(shmId<0)
	{
		printf("Could not create shared memory\n");
		return 2;
	}
	pShm = shmat(shmId, NULL, 0);
	if(!pShm)
	{
		printf("Could not attach shared memory segment\n");
		return 3;
	}
	printf("Client: Enter some request message to send to server\n");
	fgets(pShm, MSG_LEN, stdin);
	smop.sem_num = 0;
	smop.sem_op = 1;
	smop.sem_flg = 0;
	semop(semId, &smop, 1);

}
