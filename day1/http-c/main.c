#include <stdio.h>              // printf, perror
#include <stdlib.h>             // exit, EXIT_FAILURE
#include <unistd.h>             // close()
#include <sys/socket.h>         // socket(), bind(), listen(), accept()
#include <netinet/in.h>         // sockaddr_in
#include <arpa/inet.h>          // inet_pton()

// Macro to handle errors
#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main() {
    int sfd, cfd, result;                       // sfd = server socket, cfd = client socket
    struct sockaddr_in addr, client_addr;       // Address structures
    socklen_t client_addr_size;                 // Size of client address structure

    // STEP 1: Create a TCP socket (IPv4)
    sfd = socket(AF_INET, SOCK_STREAM, 0);      // AF_INET = IPv4, SOCK_STREAM = TCP
    if (sfd == -1) {
        handle_error("socket");
    }

    // STEP 2: Set address information
    addr.sin_family = AF_INET;                  // Address family = IPv4
    addr.sin_port = htons(8000);                // Port number = 8000 (host to network byte order)
    if (inet_pton(AF_INET, "0.0.0.0", &addr.sin_addr) <= 0) {
        handle_error("inet_pton");
    }

    // STEP 3: Bind the socket to IP and port
    result = bind(sfd, (struct sockaddr *)&addr, sizeof(addr));
    if (result == -1) {
        handle_error("bind");
    }

    // STEP 4: Listen for incoming connections
    result = listen(sfd, 10);                   // Backlog = 10
    if (result == -1) {
        handle_error("listen");
    }

    // STEP 5: Accept an incoming connection (blocking)
    client_addr_size = sizeof(client_addr);
    cfd = accept(sfd, (struct sockaddr *)&client_addr, &client_addr_size);
    if (cfd == -1) {
        handle_error("accept");
    }

    // Connection accepted
    printf("\nHello, world!\n");

    // STEP 6: Close sockets
    close(cfd);
    close(sfd);

    return 0;
}

