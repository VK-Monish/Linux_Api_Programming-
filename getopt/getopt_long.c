/*
Program: getopt_long_demo.c

Description:
This program demonstrates the use of `getopt_long` to parse both short and long command-line options.

---

Functionality:
- Supports the following options:
  - `-h`, `--help`     → Displays usage instructions and exits.
  - `-a`, `--append`   → Sets a flag indicating append mode.
  - `-b`, `--bakspace` → Sets a flag indicating backspace mode.
  - `-c <val>`, `--cat=<val>` → Takes a required argument (typically a filename or string).

---

Compilation:
    gcc getopt_long_demo.c -o getopt_long

Usage:
    ./getopt_long [OPTIONS]

Examples:
    ./getopt_long --help  
        → Displays help message.

    ./getopt_long -a -b -c test.txt  
        → Sets append and backspace flags, and sets cvalue to "test.txt".

    ./getopt_long --append --bakspace --cat=example.txt  
        → Same as above, using long options.

Output Example:
    a flag = 1  
    b flag = 1  
    c value = example.txt

---

Notes:
- `getopt_long` parses long options using a `struct option[]`.
- The last element of the option array must be all zeros to indicate the end.
- The `optarg` global variable stores the value passed to options like `-c` or `--cat`.
- The help function provides clear usage guidance.

---

Header References:
- `<getopt.h>`: Required for `getopt_long` and `struct option`.
- `<unistd.h>`: Provides access to the POSIX API, including `getopt`.
- `<stdlib.h>` & `<stdio.h>`: For general utilities and I/O operations.
*/

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
