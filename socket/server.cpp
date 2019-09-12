//
// Created by 王振 on 2019-07-31.
//


#include <sys/types.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<iostream>
#include <unistd.h>
#include <cstring>

using namespace std;

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(6180);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(sock, (sockaddr *) (&addr), sizeof(addr));
    listen(sock, 100);
    char buff[64];
    while (true) {
        struct sockaddr_in remoteAddr;
        socklen_t len;
        int acsock = accept(sock, (sockaddr *) (&remoteAddr), &len);
        if (acsock > 0) {
            strcpy(buff, "welcome to myworld!");
            write(acsock, buff, strlen(buff));
            close(acsock);
        }
    }
    return 0;
}

