//-----------------READ CODE-------------------------
#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>

struct msgbuf{
	long m_type;
	char data[1024];
};

int main(int argc, char **argv){
	int msqid;
	struct msgbuf read;
	msqid = msgget(190, IPC_CREAT|0644);
	msgrcv(msqid, &read, sizeof(read), atoi(argv[1]), IPC_NOWAIT);
	printf("Data readed is:  %s\n", read.data);
	return 0;
}
