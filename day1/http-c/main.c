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
    result = bind(fd, ..., ...);
    printf("hello world");
    return 0;
}
