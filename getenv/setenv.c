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
