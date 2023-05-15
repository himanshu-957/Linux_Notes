#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

struct msgbuf{ //user defined structure to pack data + type field
	long mtype; // mtype is a type
	char data[512]; //data is to send to process
};

int main(int argc, char *argv[])
{
	struct msgbuf v;
	int id;
	id = msgget(55, IPC_CREAT | 0644); // create a message queue...if msg with key 55 is not present, on success return the message id
	printf("id = %d\n", id);
	v.mtype = atoi(argv[1]);
	strcpy(v.data, argv[2]);
	msgsnd(id, &v, strlen(v.data)+1, IPC_NOWAIT);
	return 0;
}
