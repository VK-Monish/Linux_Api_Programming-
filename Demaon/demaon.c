/*
 * File: daemon_example.c
 * Description:
 *   This program demonstrates how to create a simple daemon process in Linux.
 *   It forks a child, detaches it from the terminal, redirects output, and writes messages
 *   to the system log using syslog().
 *
 * Features:
 *   - Forks a child process and terminates the parent to ensure it's not a process group leader.
 *   - Creates a new session with setsid() to detach from any terminal.
 *   - Changes the working directory to root ("/") to avoid locking the current directory.
 *   - Closes all open file descriptors.
 *   - Uses syslog to log messages under the "LOG_DAEMON" facility.
 *   - Logs a message every second for 5 seconds, simulating daemon activity.

 * Usage:
 *   Compile: gcc daemon_example.c -o daemon_example
 *   Run: ./daemon_example
 *   Check logs: sudo journalctl -t said or check /var/log/syslog (or /var/log/messages depending on distro)

 * Notes:
 *   - The syslog tag used is "said".
 *   - Ensure proper permissions when running, especially if logging to system directories.
 *   - For actual daemon implementation, redirecting stdin, stdout, stderr to `/dev/null` is recommended.
 *   - The program prints the daemon's PID before detaching standard output.

 * Important:
 *   - The message "parent process" is printed before the parent exits.
 *   - The log entries can be viewed with tools like `journalctl` or by inspecting system log files.
 */

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
