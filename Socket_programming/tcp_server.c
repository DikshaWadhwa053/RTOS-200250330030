#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>



int main(){
    char server_msg[256]="You have reached the server!";
    //create the server socket
    int s_fdserver;
    s_fdserver=socket(AF_INET,SOCK_STREAM,0);
    //define the server address
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9002);
    server_address.sin_addr.s_addr=INADDR_ANY;

    //bind the socket to our specified IP and port
    bind(s_fdserver,(struct sockaddr*) &server_address,sizeof(server_address));

    listen(s_fdserver,6);//atleast 1 here 6 for example

    int client_socket;
    client_socket= accept(s_fdserver,NULL,NULL);
//send the message
    send(client_socket,server_msg,256,0);
//cloase the socket
close(s_fdserver);

    return 0;

}