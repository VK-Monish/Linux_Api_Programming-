#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
  int i;
  time_t st,en;
  st = time(NULL);
  sleep(2);
  en = time(NULL);
  printf("%ld Start time\n",st);
  printf("%ld End   time\n",en);
  printf("%ld Seconds\n",en-st);
}
