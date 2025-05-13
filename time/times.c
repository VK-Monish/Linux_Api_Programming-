#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/times.h>

int main()
{
  int i ;
  struct tms st;
  struct tms en;

  times(&st);
  for(int i =0; i<1000000000000; i++);
  times(&en);
  printf("user:%ld\n",st.tms_utime);
  printf("user:%ld\n",st.tms_stime);
  printf("user:%ld\n",en.tms_utime);
  printf("user:%ld\n",en.tms_stime);
}

