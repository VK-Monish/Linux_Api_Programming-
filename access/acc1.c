#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  char str[] = "moni.c";
  if(access(str,R_OK) == 0)
  {
    printf("The file as read permission\n");
  }
  else
  {
    printf("The file dose not have the Read permission\n");
  }
  
  if(access(str,W_OK) == 0)
  {
    printf("The file as write permission\n");
  }
  else
  {
    printf("The file dose not have the Write permission\n");
  }

  if(access(str,X_OK) == 0)
  {
    printf("The file as execute permission\n");
  }
  else
  {
    printf("The file dose not have the execute permission\n");
  }
}
