#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main(){
int sockfd = socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in addr; addr.sin_family=AF_INET; addr.sin_port=htons(9002); addr.sin_addr.s_addr = INADDR_ANY;
bind(sockfd, (struct sockaddr*)&addr, sizeof addr); listen(sockfd,5);
printf("Server listening on 9002\n");
int client = accept(sockfd, NULL, NULL);
char buf[512]; while(1){
int n = read(client, buf, sizeof buf-1); if(n<=0) break; buf[n]=0; printf("Client: %s\n", buf);
printf("Reply: "); if(!fgets(buf,sizeof buf,stdin)) break; write(client, buf, strlen(buf));
}
close(client); close(sockfd); return 0;
}