/*
 * This program demonstrates how to change the effective user ID (UID) of a process
 * using the `setuid()` system call and retrieve user account information using `getpwuid()`.
 *
 * Key steps:
 * - It first prints the current real UID using `getuid()`.
 * - Then attempts to change the UID to 0 (root) using `setuid(0)`.
 * - If the operation fails, it prints an error using `perror()`.
 * - After attempting the UID change, it again prints the current UID.
 * - Finally, it uses `getpwuid()` to retrieve and print the username associated with the current UID.
 *
 * Note:
 * - To successfully set UID to 0, the program must be run with elevated privileges (e.g., as root or setuid root binary).
 * - Running without proper permissions will result in a "setuid: Operation not permitted" error.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{
  int set;
  printf("getuid %d\n",getuid());
  set = setuid(0);
  if(set == -1)
  {
    perror("setuid");
  }
  printf("getuid %d\n",getuid());
  struct passwd *pw = getpwuid(getuid());
  printf("%s\n",pw->pw_name);
}
