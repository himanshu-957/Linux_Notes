#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

main()
{
        int msqid;
        msqid = msgget(55, IPC_CREAT|0644);
        printf("Message Queue ID is printed = %d\n",msqid);
        msgctl(msqid,IPC_RMID,NULL);
	printf("Message Queue is removed using msgctl\n");
}

