#include<sys/socket.h>
#include<vector>
#include<libc.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define REMOTE_ADDR "127.0.0.1"

struct sockaddr_in address;
std::vector<char> buffer{'a', 'a', 'a', 'a', 'a', 'a','a'};

int main(){
    int sock = socket(AF_INET,SOCK_STREAM,0);

    address.sin_family = AF_INET;
    address.sin_port = htons(5432);

    inet_pton(AF_INET,REMOTE_ADDR,&address.sin_addr.s_addr);
    connect(sock, (struct sockaddr*)&address, sizeof address);
    write(sock,&buffer,buffer.size());
    close(sock);
    return 0;


}