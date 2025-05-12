#include "header.h"

void help() 
{
  printf("Usage: a.out [OPTION]...\n");
  printf("List information about the FILEs (the current directory by default).\n");
  printf("-c,   --chmod=<mode>:<file>     Change file permissions (e.g., --chmod=755:file.txt)\n");
  printf("-w,   --wordcount=<file>        Count the number of words in the file(e.g, --wordcount=file.txt)\n");
  printf("-h,   --help                    Show this help message\n");
  exit(-1);
}

int main(int argc, char* argv[]) 
{
  options(argc,argv);
  return 0;
}
