//
// Created by saimyomyat on 1/16/23.
//

//
// Created by saimyomyat on 1/16/23.
//

#include "stdlib.h"
#include "stdio.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(){

    int network_socket = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in server_address ;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(6666);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket,(struct sockaddr*) &server_address,sizeof (server_address));

    if(connection_status == -1){
        printf("connection failed\n");
        return -1;
    }

    char response[100];
    recv(network_socket,&response,sizeof (response),0);

    printf("Data from server: %s\n",response);

    return 0;
}