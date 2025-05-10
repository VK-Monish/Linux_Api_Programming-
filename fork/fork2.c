#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
  pid_t p = fork();
  printf("%d\n",p);
}
