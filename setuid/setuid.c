#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{
  int set;
  printf("getuid %d\n",getuid());
  set = setuid(0);
  if(set == -1)
  {
    perror("setuid");
  }
  printf("getuid %d\n",getuid());
  struct passwd *pw = getpwuid(getuid());
  printf("%s\n",pw->pw_name);
}
