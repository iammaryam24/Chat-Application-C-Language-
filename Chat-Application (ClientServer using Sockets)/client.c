#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main(){
int sock = socket(AF_INET, SOCK_STREAM,0);
struct sockaddr_in addr; addr.sin_family=AF_INET; addr.sin_port = htons(9002);
inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
if(connect(sock, (struct sockaddr*)&addr, sizeof addr)!=0){ perror("connect"); return 1; }
char buf[512]; while(1){ printf("You: "); if(!fgets(buf,sizeof buf,stdin)) break; write(sock, buf, strlen(buf)); int n = read(sock, buf, sizeof buf-1); if(n<=0) break; buf[n]=0; printf("Server: %s\n", buf); }
close(sock); return 0;
}