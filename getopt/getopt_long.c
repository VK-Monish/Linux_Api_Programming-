#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <stdio.h>
void help()
{
  printf("Usage: a.out [OPTION]... [FILE]...\n");
  printf("List information about the FILEs (the current directory by default)Sort entries alphabetically if none of -cftuvSUX nor --sort is specified\n");
  printf("-a    --append                Appending typically refers to adding data to the end of a data structure or file\n");
  printf("-b    --bakspace              The backspace character is represented as /b\n");
  printf("-c    --cat                   The cat command in Linux/Unix stands for,It is most commonly used to read, display, combine, and create text files\n");
  exit(-1);
}
int main(int argc, char* argv[])
{
  int c;
  char *cvalue = NULL;
  int aflag = 0;
  int bflag = 0;
  int index = 0;
  struct option long_options[] = 
  {
    {"help",no_argument,     0,'h'},
    {"append",no_argument,       0,'a'},
    {"bakspace",no_argument,       0,'b'},
    {"cat",required_argument, 0,'c'},
    {0,0,0,0}
  };

  //int getopt_long(int argc, char *argv[],const char *optstring,const struct option *longopts, int *longindex);
  while((c=getopt_long(argc,argv,"habc:",long_options,&index)) != -1)
  {
    switch(c)
    {
      case'a':
	aflag=1;
	break;
      case'h':
	help();
	break;
      case'b':
	bflag=1;
	break;
      case'c':
	cvalue = optarg;
	break;
    }
  }
  printf("a flag = %d\n", aflag);
  printf("b flag = %d\n", bflag);
  printf("c value = %s\n", cvalue);
}

//output
/*
moni@monish:~/Documents/api/system_calls/getopt$ ./a.out --help
Usage: a.out [OPTION]... [FILE]...
List information about the FILEs (the current directory by default)Sort entries alphabetically if none of -cftuvSUX nor --sort is specified
-a    --append                Appending typically refers to adding data to the end of a data structure or file
-b    --bakspace              The backspace character is represented as /b
-c    --cat                   The cat command in Linux/Unix stands for,It is most commonly used to read, display, combine, and create text files
moni@monish:~/Documents/api/system_calls/getopt$ ./a.out --a
a flag = 1
b flag = 0
c value = (null)
moni@monish:~/Documents/api/system_calls/getopt$ ./a.out -abc moni
a flag = 1
b flag = 1
c value = moni
*/
