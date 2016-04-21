#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>

void* RSA_GenKey_C(size_t bits);

int main(int argc, char** argv) {
  int listenfd = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
  
  struct sockaddr_in addr;
  memset(&addr,0,sizeof(addr));
  
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(5000);
  
  bind(listenfd, (struct sockaddr*)&addr, sizeof(addr));
  
  listen(listenfd, 1);
  socklen_t slen = sizeof(addr);
  int clientFD = accept(listenfd,(struct sockaddr*)&addr,&slen);
  printf("Client connected!");
  while(1) {
    char sendBuff[1025];
    
    int nbytes = read(clientFD,sendBuff,1025);
    write(STDOUT_FILENO,sendBuff,nbytes);
    
  }
  
  return 0;
}