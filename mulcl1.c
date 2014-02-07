//server program for multiple client using fork

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char ch,a[50];
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    	server_address.sin_family = AF_INET;
    	server_address.sin_addr.s_addr =  htonl(INADDR_ANY);
    	server_address.sin_port = 9734;
    	server_len = sizeof(server_address);
    	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
    	listen(server_sockfd, 5);
    	signal(SIGCHLD, SIG_IGN);
   
 	while(1)    
	{
       		printf("server waiting\n");

        	client_len = sizeof(client_address);
        	client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address, &client_len);

        	if(fork() == 0) 
		{

             		while(1)
        		{
        			read(client_sockfd,a, 50);

        			printf("reply:%s",a);
        			printf("Me: ");
        			fgets(a,50,stdin);
        			write(client_sockfd,a , 50);
        

        		}

		}
        	else 
		{
            		close(client_sockfd);
        	}
 	}   
}


