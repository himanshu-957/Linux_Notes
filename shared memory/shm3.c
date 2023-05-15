#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main(int argc, char **argv)
{
	char *p;
	int id;
	
	id = shmget(atoi(argv[1]), 250, IPC_CREAT|0644);
	if(id<0)
	{
		perror("shmget");
		return 0;
	}
	printf("id = %d\n", id);
	p = shmat(id, 0, 0);
	strcpy(p,argv[2]);
	return 0;
}
