//client


#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
        char qw[50],wq[50];
    int sockfd;
    int len,result;
    struct sockaddr_in address;

/*  Remove any old socket and create an unnamed socket for the server.  */

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket.  */

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port =9734;
    len = sizeof(address);
	result=connect(sockfd,(struct sockaddr *)&address,len);
/*  Create a connection queue and wait for clients.  */

if(result==-1)
{
	perror("oops:client3");
	exit(1);
}
/*  Accept a connection.  */

	while(1)
	{
/*  We can now read/write to client on client_sockfd.  */
        printf("Me: ");
	fgets(qw,50,stdin);
       
        write(sockfd,qw ,sizeof(qw));
	read(sockfd,wq,sizeof(wq));
	printf("Reply: %s\n",wq);
	}
        close(sockfd);
	exit(0);
    }

