#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main(int argc, char **argv)
{
	char *r;
	int id;
	id = shmget(atoi(argv[1]), 250, IPC_CREAT|0644);
	if(id<0)
	{
		perror("shmget");
		return 0;
	}
	printf("id=%d\n", id);
	r = shmat(id, 0, 0);
	printf("%s\n", r);
	return 0;
}
