#include <stdio.h>      /*  printf                          */
#include <arpa/inet.h>  /*  create, bind, listen, accept    */
#include <errno.h>      /*  errno message                   */
#include <sys/socket.h> /*  socket API                      */
#include <unistd.h>     /* read, write                      */

#define PORT 60003
#define BUFFER_SIZE 1024

/*
 *  guide how to create http server code:
 *  https://bruinsslot.jp/post/simple-http-webserver-in-c/
 *
 */

int main()
{
    char buffer[BUFFER_SIZE];

    struct sockaddr_in host_addr;
    int host_addrlen = 0;
    int valread = 0;
    int valwrite = 0;

    /* Create a socket*/
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); /* AF_INET- type of address: IPv4 , SOCK_STREAM - type of socket: TCP */
    if (sockfd == -1)                             /* sockfd stored socket descriptor                    */
    {
        perror("webserver couldn't create socket)");
        return 1;
    }
    printf("socket created successfully\n");

    /* Create the address to bind the socket to*/
    host_addrlen = sizeof(host_addr);
    host_addr.sin_family = AF_INET;                /* what type of address      */
    host_addr.sin_port = htons(PORT);              /* what port to listen       */
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY); /* bind to any local address */
    
    /* Bind the address to a socket   */
    if (bind(sockfd, (struct sockaddr *)&host_addr, host_addrlen) != 0)    
    {
        perror("webserver couldn't bind");
        return 1;
    }
    printf("socket successfully bound to address\n");

    /* Listen for incoming connections*/
    if (listen(sockfd, SOMAXCONN) != 0)             /*  SOMAXCONN define by OS , max num of connections*/
    {
        perror("webserver couldn't listen");
        return 1;
    }
    printf("server listening for connections\n");

    for (;;)
    {
        /* Accept incoming connections*/
        int newsockfd = accept(sockfd, (struct sockaddr *)&host_addr,
                               (socklen_t *)&host_addrlen);
        if (newsockfd < 0)
        {
            perror("webserver couldn't accept)");
            continue;
        }
        printf("connection accepted\n");

        for (;;)
        {
            /* Read from the socket*/
            valread = read(newsockfd, buffer, BUFFER_SIZE);
            if (valread < 0)
            {
                perror("webserver can't read)");
                continue;
            }
            printf("Received: %s", buffer);

            /* Echo back to the user his data*/
            valwrite = write(newsockfd, buffer, valread);
            if (valwrite < 0)
            {
                perror("webserver can't write)");
                continue;
            }
        }

        close(newsockfd);
    }

    return 0;
}
