/*
 * File:    main.c
 * Author:  Monish Kumar
 *
 * Description:
 * This program provides command-line utilities similar to basic Linux commands.
 * It supports changing file permissions and counting words in a file.
 *
 * Usage:
 *   ./a.out [OPTION]...
 *
 * Options:
 *   -c, --chmod=<mode>:<file>
 *       Change file permissions using chmod (e.g., --chmod=755:file.txt)
 *
 *   -w, --wordcount=<file>
 *       Count the number of words in the specified file
 *
 *   -h, --help
 *       Display this help message
 *
 * Compilation:
 *   gcc -o a.out main.c
 *
 * Notes:
 * - File permissions for --chmod must be provided in octal format (e.g., 755).
 * - This tool demonstrates command-line parsing using getopt_long and basic system calls like open, read, and chmod.
 *
 */

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
