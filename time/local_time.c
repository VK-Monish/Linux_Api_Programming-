#include <time.h>
#include <stdio.h>

int main()
{
  time_t c_tm;
  c_tm = time(NULL);

  struct tm *my_tm;

  //struct tm *localtime(const time_t *timep);

  my_tm = localtime(&c_tm);
  printf("Date  : %d\n ",my_tm->tm_mday);
  printf("Month : %d\n ",my_tm->tm_mon+1);
  printf("Year  : %d\n ",my_tm->tm_year+1900);
}
