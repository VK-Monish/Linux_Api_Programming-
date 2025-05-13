#include <time.h>
#include <stdio.h>

int main()
{
  time_t tm;
  struct tm *my_tm;
  char *t_str;
  tm = time(NULL);
  t_str = ctime(&tm);
  printf("Date : %s",t_str);
}
