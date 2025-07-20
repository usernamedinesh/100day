#include <stdio.h>              // printf, perror
#include <stdlib.h>             // exit, EXIT_FAILURE
#include <unistd.h>             // close()
#include <string.h>             // strlen()
#include <sys/socket.h>         // socket(), bind(), listen(), accept()
#include <netinet/in.h>         // sockaddr_in
#include <arpa/inet.h>          // inet_pton()

// Macro to handle errors
#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main() {
    int sfd, cfd, result;
    struct sockaddr_in addr, client_addr;
    socklen_t client_addr_size;

    // Create socket
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1)
        handle_error("socket");

    // Set address info
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8000);
    if (inet_pton(AF_INET, "0.0.0.0", &addr.sin_addr) <= 0)
        handle_error("inet_pton");

    // Bind socket
    if (bind(sfd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
        handle_error("bind");

    // Listen
    if (listen(sfd, 10) == -1)
        handle_error("listen");

    printf("Waiting for client connection...\n");

    // Accept
    client_addr_size = sizeof(client_addr);
    cfd = accept(sfd, (struct sockaddr *)&client_addr, &client_addr_size);
    if (cfd == -1)
        handle_error("accept");

    printf("Client connected. Sending message...\n");

    // Send message to client
    const char *msg = "Hello Client\n";
    write(cfd, msg, strlen(msg));

    // Close sockets
    close(cfd);
    close(sfd);

    return 0;
}

