/*
 * File: file_permission_check.c
 * Description:
 *   This program checks the read, write, and execute permissions of a file using the `access()` system call.
 *   It provides user-friendly output based on whether the file `moni.c` is accessible with specific permissions.
 *
 * How It Works:
 *   - `access(pathname, mode)` is used to determine the calling process's access to the file.
 *     It checks for the existence of the file and whether the file can be read (`R_OK`), written (`W_OK`), or executed (`X_OK`).
 *   - The program defines a file name `moni.c` and checks:
 *       - If it has read permission.
 *       - If it has write permission.
 *       - If it has execute permission.
 *   - Corresponding messages are printed based on the result of each check.

 * Output Example:
 *   The file has read permission
 *   The file has write permission
 *   The file does not have the execute permission

 * Notes:
 *   - The `access()` system call checks the real UID and GID of the calling process.
 *   - This is useful in scripts and system-level code where pre-checking file permissions is required before access.
 *   - The program assumes the file `moni.c` is present in the current working directory.

 * Usage:
 *   Compile: gcc file_permission_check.c -o file_perm
 *   Run: ./file_perm

 * Suggestions:
 *   - Consider accepting the filename from command-line arguments for flexibility.
 *   - Use `fopen()`, `fwrite()`, or `exec()` functions for actual usage after verifying permissions.
 *   - Fix typo in output messages: "dose" → "does", and "as" → "has".

 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  char str[] = "moni.c";
  if(access(str,R_OK) == 0)
  {
    printf("The file as read permission\n");
  }
  else
  {
    printf("The file dose not have the Read permission\n");
  }
  
  if(access(str,W_OK) == 0)
  {
    printf("The file as write permission\n");
  }
  else
  {
    printf("The file dose not have the Write permission\n");
  }

  if(access(str,X_OK) == 0)
  {
    printf("The file as execute permission\n");
  }
  else
  {
    printf("The file dose not have the execute permission\n");
  }
}
