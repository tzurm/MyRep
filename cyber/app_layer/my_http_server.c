#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8000
#define BUFFER_SIZE 1024

/*
 *  guide how to create http server code:
    https://bruinsslot.jp/post/simple-http-webserver-in-c/ 

*/

int main() 
{
    char buffer[BUFFER_SIZE];
    char resp[] = "HTTP/1.0 200 OK\r\n"
                    "Server: webserver-c\r\n"
                    "Content-type: text/html\r\n\r\n"
                    "<html><body><a href='https://cdn.pixabay.com/photo/2019/04/14/13/36/scam-4126798_1280.jpg'>Don't click here!</a></body></html>\r\n";

    struct sockaddr_in host_addr;
    int host_addrlen = 0;
    int valread = 0;
    int valwrite = 0;

    /* Create a socket*/
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) 
    {
        perror("webserver (socket)");
        return 1;
    }
    printf("socket created successfully\n");

    /* Create the address to bind the socket to*/
    host_addrlen = sizeof(host_addr);
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(PORT);
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    /* Bind the socket to the address*/
    if (bind(sockfd, (struct sockaddr *)&host_addr, host_addrlen) != 0) 
    {
        perror("webserver (bind)");
        return 1;
    }
    printf("socket successfully bound to address\n");

    /* Listen for incoming connections*/
    if (listen(sockfd, SOMAXCONN) != 0) {
        perror("webserver (listen)");
        return 1;
    }
    printf("server listening for connections\n");

    for (;;) 
    {
        /* Accept incoming connections*/
        int newsockfd = accept(sockfd, (struct sockaddr *)&host_addr,
                               (socklen_t *)&host_addrlen);
        if (newsockfd < 0) {
            perror("webserver (accept)");
            continue;
        }
        printf("connection accepted\n");

        /* Read from the socket*/
        valread = read(newsockfd, buffer, BUFFER_SIZE);
        if (valread < 0) {
            perror("webserver (read)");
            continue;
        }

        /* Write to the socket*/
        valwrite = write(newsockfd, resp, strlen(resp));
        if (valwrite < 0) {
            perror("webserver (write)");
            continue;
        }

        close(newsockfd);
    }

    return 0;
}
