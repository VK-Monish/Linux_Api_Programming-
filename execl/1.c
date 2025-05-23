#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

int main(int argc,char*argv[]) 
{
  pid_t pid;
  int fd = open(argv[1], O_CREAT | O_RDWR);

  pid = fork();
  if (pid == 0) 
  {
    char buffer[100];
    int fd_read = open(argv[1], O_CREAT | O_RDWR);
    int n = read(fd_read,buffer, sizeof(buffer));
    printf("Child read: %s\n", buffer);
    close(fd);
  } 
  else 
  {
    char *sou = "Hi iam Monish Kumar";
    write(fd, sou, strlen(sou));
  }
}
