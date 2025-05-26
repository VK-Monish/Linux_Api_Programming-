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
