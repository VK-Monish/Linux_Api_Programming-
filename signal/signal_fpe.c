#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handle()
{
  printf("Floating point error");
  exit(1);
}

int main() 
{
  signal(SIGFPE, handle);
  int a=5,b=0;
  int c= a/b;
}

