#include <stdio.h>
#include <unistd.h>
int main()
{
  void *l;
  printf("getpid %d\n",getpid());
  l= sbrk(0);   
  printf("The intial heap end point %p\n",l);
  getchar();
  l= sbrk(1<<30);
  printf("The final heap end point  %p\n",l);
  getchar();
}
