#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>

#define PORT 8000
#define MAXSZ 1000

int main()
{
	int sockfd;
	int newsockfd;

	struct sockaddr_in sAddr;
	struct sockaddr_in cAddr;
	int n;
	char msg[MAXSZ];
	int clientAddressLength;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&sAddr,0,sizeof(sAddr));
	
	sAddr.sin_family = AF_INET;
	sAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	sAddr.sin_port = htons(PORT);

	bind(sockfd, (struct sockaddr *)&sAddr, sizeof(sAddr));
	listen(sockfd,5);
	while(1)
	{
		printf("\nWaiting for Connection from CLient Side\n");
		clientAddressLength = sizeof(cAddr);
		newsockfd = accept(sockfd,(struct sockaddr*)&cAddr, &clientAddressLength);
		while(1)
		{
			n = recv(newsockfd,msg,MAXSZ,0);
			if(n==0)
			{
				close(newsockfd);
				break;
			}
			msg[n] = 0;
			send(newsockfd,msg,n,0);

			printf("Receive and set the value to :%s\n",msg);
		}
	}
	return 0;
}
