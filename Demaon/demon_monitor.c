/*
 * File: file_logging_daemon.c
 * Description:
 *   This program demonstrates how to create a custom daemon process in Linux that writes periodic
 *   messages to a specified log file. The daemon runs in the background and logs a message every
 *   2 seconds, including its process ID.
 *
 * Features:
 *   - Forks the current process and terminates the parent, allowing the child to run as a daemon.
 *   - Closes all open file descriptors to detach from the terminal.
 *   - Writes messages to the file "/home/moni/love.c" using dprintf().
 *   - After writing 30 log entries, it truncates the file to start fresh and avoids infinite growth.
 *
 * Log File Behavior:
 *   - The file "/home/moni/love.c" is created/appended to if it doesn’t exist.
 *   - Every 2 seconds, it logs: "Hello...I am monish and my roll number is: <pid>"
 *   - When `count == 30`, the file is truncated using `O_TRUNC`.
 *   - After `count > 30`, the count resets to 0 and the cycle continues.

 * Usage:
 *   Compile: gcc file_logging_daemon.c -o file_logger
 *   Run: ./file_logger
 *   Check output: tail -f /home/moni/love.c

 * Notes:
 *   - This is a minimal daemon and does not set a new session ID (`setsid()`), which is recommended in full daemons.
 *   - File descriptor returned by `open()` should be checked *before* calling `dprintf()` to avoid writing to an invalid fd.
 *   - File is opened and closed every cycle for simplicity, but keeping it open might be more efficient.
 *   - No logging to syslog; this daemon writes directly to a file.

 * Improvements (optional):
 *   - Add `setsid()` after fork to fully detach from terminal.
 *   - Redirect stdin, stdout, stderr to `/dev/null`.
 *   - Add signal handling for clean shutdown.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void sl_daemon()
{
  char *log_file= "/home/moni/love.c";
  int fd;
  int count = 0;
  while(1)
  {
    if(count < 30)
    {
      fd = open(log_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
      dprintf(fd,"Hello...I am monish and my roll number is: %d\n",getpid());
      if(fd == -1)
      {
	perror("open");
      }
    }

    else if(count == 30)
    {
      open(log_file,O_TRUNC);
    }
    count++;

    if(count > 30)
    {
      count = 0;
    }
    sleep(2);
  }
}

int main() 
{
  int i;
  pid_t pid;
  pid = fork();
  if(pid < 0 )
  {
    perror("fork");
  }
  if(pid>0)
  {
    printf("Parent process%d\n",getpid());
    exit(EXIT_SUCCESS);
  }
  i = sysconf(_SC_OPEN_MAX);
  for(i;i>=0; i--)
  {
    close(i);
  }
  sl_daemon();
}
