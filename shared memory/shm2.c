#include<sys/shm.h>
#include<stdio.h>
#define SIZE 20
int main()
{
	char *ptr;
	int shmid, pid, i;
	shmid = shmget((key_t)66, 20, IPC_CREAT | 0666);
	ptr = (char *)shmat(shmid,(char*)0,0);
	pid = fork();
	if(pid == 0)
	{
		i = read(0,ptr,SIZE);
		if(i==1)
		{
			printf("\nRead failed\n");
		}
		else
			printf("Child reads %s\n", ptr);
	}
	else
	{
		wait(0);
		write(1, ptr, SIZE);
		printf(" parent reads ... %s\n", ptr);
		shmctl(shmid, IPC_RMID, NULL);
	}
}
