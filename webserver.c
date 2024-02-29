#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>

#define PORT 8080
#define BACKLOG 50

int main() {
    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_socket == -1) {
        perror("webserver (socket)");
        return 1;
    }
    printf("socket created successfully\n");

    struct sockaddr_in host_addr;
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = PORT;
    host_addr.sin_addr.s_addr = INADDR_ANY;
    int host_addrlen = sizeof(host_addr);

    int binding = bind(tcp_socket, (const struct sockaddr *)&host_addr, host_addrlen);
    if (binding == -1) {
        perror("webserver (bind)");
        return 1;
    }
    printf("Bind was successful\n");

    int listener = listen(tcp_socket, BACKLOG);
    if (listener == -1) {
        perror("webserver (listen)");
    }
    printf("Socket set as passive\n");

    return 0;
}
