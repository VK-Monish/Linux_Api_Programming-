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
