#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char*argv[])
{
  struct tm *m_tm;

  //long strtol(const char *restrict nptr,char **restrict endptr, int base);
  long fd = strtol(argv[1],NULL,10);
  m_tm = localtime(&fd);
  printf("Date  : %d\n ",m_tm->tm_mday);
  printf("Month : %d\n ",m_tm->tm_mon+1);
  printf("Year  : %d\n ",m_tm->tm_year+1900);
}
