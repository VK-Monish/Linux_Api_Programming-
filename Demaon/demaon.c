#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <stdlib.h>
#include <time.h>

void sl_daemon()
{
  int i;
  for(i=0; i<5; i++)
  {
    syslog(LOG_NOTICE,"sid running");
    sleep(1);
  }
}

int main(int argc,char*argv[])
{
  pid_t pid;
  int i;
  pid=fork();

  if(pid < 0)
  {
    perror("error");
    exit(-1);
  }
  else if(pid > 0)
  {
    printf("parent process\n");
    exit(1);
  }
  if(setsid()<0)
  {
    perror("error");
    exit(-1);
  }
  chdir("/");
  printf("PID:%d\n",getpid());
  i=sysconf(_SC_OPEN_MAX);
  for(i;i>=0;i--)
  {
    close(i);
  }
  openlog("said",LOG_PID,LOG_DAEMON);
  syslog(LOG_NOTICE,"said started");
  sl_daemon();
  syslog(LOG_NOTICE,"said stoped");
  close(1);
}
