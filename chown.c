#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char*argv[]) 
{
  int fd;
  uid_t new_uid = 0;
  gid_t new_gid = 0;
  fd = chown(argv[1],new_uid,new_gid);
  if(fd == -1)
  {
    perror("chown");
  }
}
