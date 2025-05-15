/*
Simple getenv() Usage in C

This program demonstrates how to use the getenv() function to retrieve the value of an environment variable.

---

Program Behavior:
- Defines an environment variable name ("SHELL").
- Uses getenv() to get the value of that environment variable.
- Prints the variable name and its value to standard output.

Requirements:
- Any operating system with standard C library support.
- C compiler like GCC.

How to Compile:
    gcc getenv.c -o getenv

How to Run:
    ./getenv

Expected Output:
    SHELL :: /bin/bash

(Note: The output value depends on the current environment variable settings.)

Notes:
- getenv() returns NULL if the environment variable does not exist.
- This example assumes "SHELL" is defined in your environment.
- Always check for NULL return in real applications for robustness.

*/

#include <stdio.h>
#include <stdlib.h>

/*
   moni@monish:~/Documents/api/system_calls/getenv$ gcc getenv.c
   moni@monish:~/Documents/api/system_calls/getenv$ ./a.out
   
   OUTPUT/#/#/
   
   The value of SHELL is: /bin/bash

*/

int main() 
{
    char *var = "SHELL";

    //   char *getenv(const char *name);
    
    char *value = getenv(var);
    printf("%s :: %s", var, value);
}
