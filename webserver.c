#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>

int main() {
    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_socket == -1) {
        perror("webserver (socket)");
        return 1;
    }
    printf("socket created successfully");

    return 0;
}
