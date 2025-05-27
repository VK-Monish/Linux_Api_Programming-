/*
 * File: change_dir_and_create_folder.c
 * Description:
 *   This program changes the current working directory to "/home/moni/ai"
 *   and then attempts to create a new directory named "my_folder" within it.
 *
 * Usage:
 *   Compile: gcc change_dir_and_create_folder.c -o change_dir
 *   Run: ./change_dir
 *
 * Behavior:
 *   - Uses chdir() to change the current working directory to "/home/moni/ai".
 *   - If successful, creates a new directory "my_folder" with permissions 0755:
 *       - Owner: read, write, execute
 *       - Group: read, execute
 *       - Others: read, execute
 *   - If either operation fails, an appropriate error message is displayed using perror().
 *
 * Notes:
 *   - Make sure the directory "/home/moni/ai" exists and your program has the necessary permissions.
 *   - The success message for chdir incorrectly states "/tmp" but actually changes to "/home/moni/ai".
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() 
{
  if (chdir("/home/moni/ai") == 0) 
  {
    printf("Changed directory to /tmp\n");
    if (mkdir("my_folder", 0755) == 0) 
    {
      printf("Directory 'my_folder' created successfully.\n");
    } 
    else 
    {
      perror("mkdir failed");
    }
  } 
  else 
  {
    perror("chdir failed");
  } 
}

