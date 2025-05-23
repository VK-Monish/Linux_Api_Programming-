#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler()
{
  printf("Segmentation fault occurred due to accessing an invalid memory location.\n");
  printf("Example of correct usage:\n");
  printf("int    a = 10\n");
  printf("int *ptr = &a\n");
  exit(-1);
}

int main()
{
  signal(SIGSEGV,handler);

  int *ptr = NULL;
  *ptr = 100;
}
