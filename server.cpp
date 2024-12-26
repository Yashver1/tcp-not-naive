#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string>
#include<libc.h>
#include<netdb.h>
#include<vector>
#include<iostream>
struct sockaddr_in localAddress;
std::vector<char> buffer;

int main(){
    int bytesRead{0};
    buffer.resize(4096);
    int sock = socket(AF_INET,SOCK_STREAM,0);

    localAddress.sin_family = AF_INET;
    localAddress.sin_family = AF_INET;
    localAddress.sin_port = htons(5432);

    inet_pton(AF_INET,"0.0.0.0",&localAddress.sin_addr.s_addr);
    bind(sock,(struct sockaddr*)&localAddress,sizeof localAddress);
    listen(sock,128);

    socklen_t addrlen = sizeof localAddress;
    int client = accept(sock,(struct sockaddr*)&localAddress,&addrlen);
    write(client, "220 Welcome\r\n",13);

    for(;;) {
        int res = read(client, buffer.data(), buffer.size());
        if(res < 0){
            perror("read");
            exit(1);
        }

        if(!res){
            break;
        }
        bytesRead+=res;
    }

    std::cout << bytesRead << std::endl;
    return 0;

    
}