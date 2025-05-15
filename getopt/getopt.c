/*
Command Line Option Parser using getopt

This program demonstrates how to use the `getopt` function in C to parse command-line options.

---

Functionality:
- Accepts and processes the following command-line options:
  - `-a`: sets the `aflag` to 1
  - `-b`: sets the `bflag` to 1
  - `-c <value>`: assigns the string following `-c` to the `cvalue` variable
- Any additional non-option arguments are printed after parsing options.

---

Compilation:
    gcc getopt_example.c -o getopt_example

Usage:
    ./getopt_example -a -b -c Hello argument1 argument2

Example Output:
    aflag = 1, bflag = 1, cvalue = Hello  
    Non-option argument argument1  
    Non-option argument argument2

Explanation:
- `getopt(argc, argv, "habc:")` processes options:
  - `h`, `a`, and `b` are flags (no arguments expected).
  - `c:` expects an argument (stored in `optarg`).
- `optind` is the index of the first non-option argument after `getopt` completes.

---

Note:
- This is a basic usage of `getopt`. For more advanced argument parsing (e.g., long options), consider using `getopt_long` (GNU extension).
*/

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
