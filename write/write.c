#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char*argv[])
{
  int fd,openflag;
  mode_t fileperm;
  char *buf = "School of linux";
  openflag  = O_CREAT | O_WRONLY ; 
  fileperm  = S_IRUSR | S_IWUSR | S_IRGPR | S_IWGPR | S_IROTH ;
//size_t write(int fd, const void buf[.count], size_t count);
  fd = open(argv[],openflag,fileperm);
}
