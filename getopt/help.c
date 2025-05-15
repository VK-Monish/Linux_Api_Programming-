/*
 * Program: getopt_long Help Option Demo
 * Author: Monish Kumar
 * Description:
 *   This C program demonstrates the use of getopt_long() to handle 
 *   long options in command-line arguments. Specifically, it implements 
 *   a '--help' or '-h' option that displays a detailed usage/help message
 *   similar to that found in GNU core utilities.
 *
 * Usage:
 *   ./a.out --help
 *   ./a.out -h
 *
 * Features:
 *   - Supports the --help or -h flag to print a comprehensive guide
 *     on simulated Linux command-line options and behavior.
 *   - Includes descriptions for commonly used flags like --cat, --echo,
 *     --mkdir, etc.
 *   - Mimics the structure of 'ls --help' output from coreutils.
 *
 * Compilation:
 *   gcc -o a.out your_file.c
 *
 * Example Output:
 *   $ ./a.out --help
 *   (Displays all option descriptions and usage format)
 *
 * Exit Codes:
 *   - Returns 0 when successful.
 *   - Returns -1 after printing help information (can be adjusted).
 *
 * Notes:
 *   - Currently, only the help option is implemented.
 *   - Designed for educational purposes to understand getopt_long().
 */

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int c;
  int index=0;
  struct option long_options[]=
  {
    {"help",no_argument,0,'h'},
    {0,0,0,0}
  };
 //  int getopt_long(int argc, char *argv[],const char *optstring,const struct option *longopts, int *longindex);
  c = getopt_long(argc,argv,"h",long_options,&index);
  if(c == 'h')
  {
    printf("Usage: a.out [OPTION]... [FILE]...\n");
    printf("List information about the FILEs (the current directory by default)Sort entries alphabetically if none of -cftuvSUX nor --sort is specified\n");
    printf("-a    --append                Appending typically refers to adding data to the end of a data structure or file\n");
    printf("-b    --bakspace              The backspace character is represented as /b\n");
    printf("-c    --cat                   The cat command in Linux/Unix stands for,It is most commonly used to read, display, combine, and create text files\n");
    printf("-d    --delete                Delete operation typically removes files, text, or data from a structure\n");
    printf("-e    --echo                  Echo prints its arguments to standard output (e.g., echo Hello)\n");
    printf("-f    --file                  Refers to a regular file on disk; often used with file operations\n");
    printf("-g    --grep                  Grep searches for patterns in files using regular expressions\n");
    printf("-h    --help                  Displays help message or usage information for commands\n");
    printf("-i    --input                 Indicates input is being provided or requested\n");
    printf("-j    --join                  Join is used to combine lines from two files based on a common field\n");
    printf("-k    --kill                  Kill sends signals to processes, commonly used to stop them\n");
    printf("-l    --list                  Often used to list files, options, or contents (e.g., ls -l)\n");
    printf("-m    --mkdir                 Used to create new directories\n");
    printf("-n    --number                Often used to show line numbers (e.g., cat -n)\n");
    printf("-o    --output                Indicates the output destination or file\n");
    printf("-p    --print                 Typically used to print output (e.g., in scripting languages)\n");
    printf("-q    --quiet                 Runs commands with minimal output (silent mode)\n");
    printf("-r    --read                  Refers to reading input or files\n");
    printf("-s    --sort                  Sorts lines or values (e.g., sort filename.txt)\n");
    printf("-t    --touch                 Touch creates a file or updates its timestamp\n");
    printf("-u    --user                  Refers to the user running the command or accessing a file\n");
    printf("-v    --version               Displays version information of a program\n");
    printf("-w    --write                 Used to write data to files or output\n");
    printf("-x    --execute               Refers to executing files or commands (e.g., chmod +x script.sh)\n");
    printf("-y    --yes                   Continuously outputs 'y', useful for piping into commands requiring confirmation\n");
    printf("-z    --gzip                  Used to compress files using gzip (z for zip)\n");
    
    printf("\nThe SIZE argument is an integer and optional unit (example: 10K is 10*1024).\n");
    printf("Units are K,M,G,T,P,E,Z,Y,R,Q (powers of 1024) or KB,MB,... (powers of 1000).\n");
    printf("Binary prefixes can be used, too: KiB=K, MiB=M, and so on.\n");

    printf("\nThe TIME_STYLE argument can be full-iso, long-iso, iso, locale, or +FORMAT.\n");
    printf("FORMAT is interpreted like in date(1).  If FORMAT is FORMAT1<newline>FORMAT2,\n");
    printf("then FORMAT1 applies to non-recent files and FORMAT2 to recent files.\n");
    printf("TIME_STYLE prefixed with 'posix-' takes effect only outside the POSIX locale.\n");
    printf("Also the TIME_STYLE environment variable sets the default style to use.\n");

    printf("\nThe WHEN argument defaults to 'always' and can also be 'auto' or 'never'.\n");

    printf("\nUsing color to distinguish file types is disabled both by default and\n");
    printf("with --color=never.  With --color=auto, ls emits color codes only when\n");
    printf("standard output is connected to a terminal.  The LS_COLORS environment\n");
    printf("variable can change the settings.  Use the dircolors(1) command to set it.\n");

    printf("\nExit status:\n");
    printf(" 0  if OK,\n");
    printf(" 1  if minor problems (e.g., cannot access subdirectory),\n");
    printf(" 2  if serious trouble (e.g., cannot access command-line argument).\n");

    printf("\nGNU coreutils online help: <https://www.gnu.org/software/coreutils/>\n");
    printf("Full documentation <https://www.gnu.org/software/coreutils/ls>\n");
    printf("or available locally via: info '(coreutils) ls invocation'\n");
    exit(-1);
  }
  else
  {
    printf("Ther is no match arrgument");
  }
}




//output
/*
moni@monish:~/Documents/api/system_calls/getopt$ ./a.out --help


Usage: a.out [OPTION]... [FILE]...
List information about the FILEs (the current directory by default)Sort entries alphabetically if none of -cftuvSUX nor --sort is specified
-a    --append                Appending typically refers to adding data to the end of a data structure or file
-b    --bakspace              The backspace character is represented as /b
-c    --cat                   The cat command in Linux/Unix stands for,It is most commonly used to read, display, combine, and create text files
-d    --delete                Delete operation typically removes files, text, or data from a structure
-e    --echo                  Echo prints its arguments to standard output (e.g., echo Hello)
-f    --file                  Refers to a regular file on disk; often used with file operations
-g    --grep                  Grep searches for patterns in files using regular expressions
-h    --help                  Displays help message or usage information for commands
-i    --input                 Indicates input is being provided or requested
-j    --join                  Join is used to combine lines from two files based on a common field
-k    --kill                  Kill sends signals to processes, commonly used to stop them
-l    --list                  Often used to list files, options, or contents (e.g., ls -l)
-m    --mkdir                 Used to create new directories
-n    --number                Often used to show line numbers (e.g., cat -n)
-o    --output                Indicates the output destination or file
-p    --print                 Typically used to print output (e.g., in scripting languages)
-q    --quiet                 Runs commands with minimal output (silent mode)
-r    --read                  Refers to reading input or files
-s    --sort                  Sorts lines or values (e.g., sort filename.txt)
-t    --touch                 Touch creates a file or updates its timestamp
-u    --user                  Refers to the user running the command or accessing a file
-v    --version               Displays version information of a program
-w    --write                 Used to write data to files or output
-x    --execute               Refers to executing files or commands (e.g., chmod +x script.sh)
-y    --yes                   Continuously outputs 'y', useful for piping into commands requiring confirmation
-z    --gzip                  Used to compress files using gzip (z for zip)

The SIZE argument is an integer and optional unit (example: 10K is 10*1024).
Units are K,M,G,T,P,E,Z,Y,R,Q (powers of 1024) or KB,MB,... (powers of 1000).
Binary prefixes can be used, too: KiB=K, MiB=M, and so on.

The TIME_STYLE argument can be full-iso, long-iso, iso, locale, or +FORMAT.
FORMAT is interpreted like in date(1).  If FORMAT is FORMAT1<newline>FORMAT2,
then FORMAT1 applies to non-recent files and FORMAT2 to recent files.
TIME_STYLE prefixed with 'posix-' takes effect only outside the POSIX locale.
Also the TIME_STYLE environment variable sets the default style to use.

The WHEN argument defaults to 'always' and can also be 'auto' or 'never'.

Using color to distinguish file types is disabled both by default and
with --color=never.  With --color=auto, ls emits color codes only when
standard output is connected to a terminal.  The LS_COLORS environment
variable can change the settings.  Use the dircolors(1) command to set it.

Exit status:
 0  if OK,
 1  if minor problems (e.g., cannot access subdirectory),
 2  if serious trouble (e.g., cannot access command-line argument).

GNU coreutils online help: <https://www.gnu.org/software/coreutils/>
Full documentation <https://www.gnu.org/software/coreutils/ls>
or available locally via: info '(coreutils) ls invocation'*/

