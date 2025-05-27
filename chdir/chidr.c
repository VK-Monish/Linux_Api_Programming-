#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() 
{
  if (chdir("/home/moni/ai") == 0) 
  {
    printf("Changed directory to /tmp\n");
    if (mkdir("my_folder", 0755) == 0) 
    {
      printf("Directory 'my_folder' created successfully.\n");
    } 
    else 
    {
      perror("mkdir failed");
    }
  } 
  else 
  {
    perror("chdir failed");
  } 
}

