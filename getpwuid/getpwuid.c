/*
 * This program demonstrates how to use the getpwuid() function
 * to retrieve and display user account information from the system's
 * password database based on a given user ID (UID).
 *
 * Key points:
 * - getpwuid(uid_t uid) returns a pointer to a passwd struct containing
 *   details about the user with the specified UID.
 * - The passwd struct includes username, password (usually "x" or "*"),
 *   user ID, group ID, user info (gecos), home directory, and shell.
 *
 * In this example, the UID passed is 1, which corresponds to a system user.
 * The program prints out the user's information fields.
 *
 * Note: Access to password information may be limited depending on system security.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{
  //struct passwd *getpwuid(uid_t uid);

  struct passwd *pw = getpwuid(1);
  /*struct passwd 
  {
    char   *pw_name;       
    char   *pw_passwd;     
    uid_t   pw_uid;        
    gid_t   pw_gid;        
    char   *pw_gecos;      
    char   *pw_dir;        
    char   *pw_shell;      
  };*/

  printf("Name  : %s\n",pw->pw_name);
  printf("passwd: %s\n",pw->pw_passwd);
  printf("uid   : %d\n",pw->pw_uid);
  printf("gid   : %d\n",pw->pw_gid);
  printf("gecos : %s\n",pw->pw_gecos);
  printf("dir   : %s\n",pw->pw_dir);
  printf("shell : %s\n",pw->pw_shell);
}
