//--------------------WRITE CODE-----------------------------
#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

struct msgbuf{
	long m_type;
	char data[1024];
};

int main(int argc, char *argv[])
{
	struct msgbuf send;
	int msqid;
	msqid = msgget(190, IPC_CREAT | 0644); 
	printf("Message queue ID = %d\n", msqid);
	send.m_type = atoi(argv[1]);
	strcpy(send.data, argv[2]);
	msgsnd(msqid, &send, strlen(send.data)+1, IPC_NOWAIT);
	return 0;
}
