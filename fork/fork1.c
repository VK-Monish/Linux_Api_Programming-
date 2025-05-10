#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int i = 0; 
int main()
{
  fork();
  fork();
  fork();
  printf("%d",i);
}
