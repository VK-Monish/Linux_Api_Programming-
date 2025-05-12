#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main (int argc, char *argv[])
{
  int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
  int c;

  while ((c = getopt(argc, argv, "habc:")) != -1)
  {
    switch (c)
    {
      case 'a':
        aflag = 1;
        break;
      case 'b':
        bflag = 1;
        break;
      case 'c':
        cvalue = optarg;
        break;
    }
  }

  printf ("aflag = %d, bflag = %d, cvalue = %s\n",aflag, bflag, cvalue);

  for (index = optind; index < argc; index++)
  {
    printf ("Non-option argument %s\n", argv[index]);
  }
}

//output
/*
   moni@monish:~/Documents/api/system_calls/getopt$ ./a.out -a
   aflag = 1, bflag = 0, cvalue = (null)
*/
