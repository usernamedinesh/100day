#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int fd, result;
    struct sockaddr_in addr; // for importing already define in headersfile
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        return -1;
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8000);
    inet_pton(AF_INET, "0.0.0.0", &addr.sin_addr);
    result = bind(fd, (struct sockaddr *) &addr, sizeof(addr));  
    if (result == -1) {
        perror("bind");
        return -1;
    }
    printf("\nhello world");
    return 0;
}
