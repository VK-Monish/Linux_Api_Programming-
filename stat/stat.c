#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char* argv[])
{
  int fd;
  struct stat st;
  fd = stat(argv[1],&st);
  if(fd == -1)
  {
    perror("stat");
  }
  printf("File Name %s\n",argv[1]);
  printf("File size %ld\n",st.st_size);
  printf("file mode %d\n",st.st_mode);
  printf("File uid  %d\n",st.st_uid);
  printf("File gid  %d\n",st.st_gid);
}
