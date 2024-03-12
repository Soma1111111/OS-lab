/*
Program Number : 51-server
Name : soma datta
Register Number : IMT2022077
Description : Inter-Machine Communication using Socket: Write a program to communicate between
              two machines using sockets.
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
    struct sockaddr_in serv, cli;
    int sd;
    sd = socket(AF_INET, SOCK_STREAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(5000);
    
    bind(sd, (struct sockaddr *)&serv, sizeof(serv));
    listen(sd, 5);

    int nsd;

    int len = sizeof(cli);
    nsd = accept(sd, (struct sockaddr *)&cli, &len);

    char buf[100];
    int ret;
    ret = read(nsd, buf, sizeof(buf));
    write(1, buf, ret);
    write(nsd, "Message From server\n", sizeof("Message From server\n"));

    close(sd);

    return(0);
}