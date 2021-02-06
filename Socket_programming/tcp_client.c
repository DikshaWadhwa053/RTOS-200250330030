#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>// address and port number of the remote socket we want to connenct to
#include<unistd.h>
#include<arpa/inet.h>
int main(){


    //create a socket
    int s_fdclient;
    s_fdclient=socket(AF_INET,SOCK_STREAM,0);

    //specify the address of the socket
   struct sockaddr_in server_address;
   server_address.sin_family=AF_INET;//address
   server_address.sin_port=htons(9002);
   //htons:the conversion fxn that's going to put our interger port passes in right network byte order
   //portnumber passes-9001 n 9002;
   server_address.sin_addr.s_addr=INADDR_ANY;
   /*sin_addr is also a structure which contains another member s_addr
    real server address  .... INADDR_ANY... shortcut to any address that 
    is available on our local machine*/
    //calling the connect fxn
    int conn_status= connect(s_fdclient, (struct sockaddr *) &server_address,sizeof(server_address));
    //check for error with the connection
    if(conn_status==-1)
    {
        printf("there was an error establishing the connection with the remote socket\n");
    }
    //receiver data form the server
    char server_response[256];//buffer to hold the data from server
    recv(s_fdclient,&server_response,256,0);

//received data from server successfully now printing what we got
    puts("The data is received");
    printf("The server sent the data: %s\n",server_response);
    
    close(s_fdclient);
    return 0;
}