#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>

#define PORT 8000
#define MAXSZ 100

int main()
{
	int sockfd;
	int newsockfd;

	struct sockaddr_in serverAddress;//server receive on this address
	struct sockaddr_in clientAddress;//server sends to client on this address

	int n;
	char msg[MAXSZ];
	int clientAddressLength;

	//create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serverAddress,0,sizeof(serverAddress));
	//initialize the socket
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(PORT);

	//bid the socket with the server address and port
	bind(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	//listen for connection from client
	listen(sockfd,5);

	//accept a connection
	while(1)
	{
		printf("\n******server waiting for new client connection*****\n");
		clientAddressLength = sizeof(clientAddress);
		newsockfd = accept(sockfd,(struct sockaddr*)&clientAddress, &clientAddressLength);//accept system call accepting the client connection request enters into inner while loop
		//returns a client socket and enters into while loop and serves the client
		//receiving the client messages and processing the data
		//once the client closes the connection with the server, server will receive 0 bytes that is indication of client closing
		//now it is calling break and comming out of inner while loop
		//After that server program again blocking at accept system call

		//receive from client
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

			printf("Receive and set:%s\n",msg);
		}
	}
	return 0;
}
