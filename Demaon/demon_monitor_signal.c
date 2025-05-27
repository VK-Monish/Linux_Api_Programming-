/*
 * File: signal_logging_daemon.c
 * Description:
 *   This C program demonstrates a simple daemon that logs messages to a file periodically.
 *   It also attempts to register the logging function (`sl_daemon`) as a signal handler for SIGTERM.
 *
 * Key Features:
 *   - Forks a child process and terminates the parent to create a background process (daemon-like behavior).
 *   - Closes all inherited file descriptors using sysconf(_SC_OPEN_MAX).
 *   - The `sl_daemon()` function opens and appends messages to `/home/moni/love.c` every 2 seconds.
 *   - Automatically truncates the file after 30 log entries to avoid file bloat.
 *
 * Signal Handling:
 *   - Registers `sl_daemon` as the handler for SIGTERM using `signal(SIGTERM, sl_daemon);`.
 *   - However, this usage is **incorrect**, as `sl_daemon()` is a long-running function and not suitable for a signal handler.
 *     Signal handlers should be quick, non-blocking, and safe. Using `open`, `sleep`, or loops in a signal handler is undefined behavior.
 *
 * Logging Behavior:
 *   - Initially truncates the log file.
 *   - Writes messages: "Hello...I am monish and my roll number is: <PID>".
 *   - Every 2 seconds, until 30 entries are made, then truncates and restarts.

 * Usage:
 *   Compile: gcc signal_logging_daemon.c -o signal_logger
 *   Run: ./signal_logger
 *   Check log: tail -f /home/moni/love.c
 *
 * Warnings and Fixes:
 *   - The signal registration for `sl_daemon` should be removed unless properly redesigned.
 *     Signal handlers must only call async-signal-safe functions.
 *   - Consider using a proper signal handler to set a flag that controls whether `sl_daemon()` should run.
 *   - The file descriptor (`fd`) should be checked for `-1` *before* using `dprintf(fd, ...)`.

 * Recommended Improvements:
 *   - Add `setsid()` after the fork for full daemonization.
 *   - Redirect stdin, stdout, stderr to `/dev/null`.
 *   - Use proper signal handling with flags (e.g., `volatile sig_atomic_t`) for safe communication.
 *   - Close the file descriptor (`close(fd)`) after writing in each loop to avoid resource leakage.

 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
void sl_daemon()
{
  char *log_file= "/home/moni/love.c";
  int fd;
  int count = 0;
  open(log_file,O_TRUNC);
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
  signal(SIGTERM,sl_daemon);	
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
