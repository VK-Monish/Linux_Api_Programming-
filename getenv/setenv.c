/*
Set and Get Environment Variable in C

This program demonstrates how to set an environment variable using setenv() and then retrieve it with getenv().

---

Program Behavior:
- Takes two command-line arguments: variable name and value.
- Uses setenv() to set the environment variable to the given value (with overwrite enabled).
- Retrieves the newly set value using getenv().
- Prints the variable name and its value to standard output.

Usage:
    ./program_name VARIABLE_NAME VARIABLE_VALUE

Example:
    ./a.out TEST_VAR HelloWorld

Output:
    TEST_VAR :: HelloWorld

Requirements:
- POSIX-compliant OS.
- C compiler (e.g., GCC).

How to Compile:
    gcc set_get_env.c -o set_get_env

How to Run:
    ./set_get_env VAR_NAME VAR_VALUE

Notes:
- The program overwrites existing environment variables with the same name.
- No error checking is performed for missing command-line arguments.
- getenv() reflects the current process environment.
- Changes do not persist outside the running process.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
  char *var = argv[1];
  char *val = argv[2];

  //int setenv(const char *name, const char *value, int overwrite); 
  setenv(var,val,1);

  //char *getenv(const char *name);
  char *valu = getenv(var);
  printf("%s :: %s",var,val);

}
