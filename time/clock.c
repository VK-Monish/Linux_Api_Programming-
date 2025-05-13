#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int i;
  clock_t st,en;
  st = clock();
  for(int i=0;i<1000000; i++);
  en = clock();
  double sec = (double)(en-st);
  printf("%lf clock used \n",sec);
}
