//
// Created by wz on 2019/8/27.
//

#include <sys/types.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(6180);
    addr.sin_addr.s_addr = INADDR_ANY;
    connect(sock, (sockaddr *) (&addr), sizeof(addr));
    char buff[64];
    int offset = 0;
    int len;
    while ((len = read(sock, buff, sizeof(buff))) > 0) {
        if (len == 0) {
            break;
        }
        offset += len;
        buff[offset] = 0;
    }
    cout << buff << endl;
    return 0;
}