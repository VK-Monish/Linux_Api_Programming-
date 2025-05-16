/*
 * mmap_anon_example.c
 *
 * This program demonstrates the use of anonymous memory mapping (`MAP_ANONYMOUS`)
 * in C using the `mmap()` system call.
 * 
 * Steps performed:
 * 1. Defines a string `"School of linux"`.
 * 2. Allocates a 1024-byte region of memory using `mmap()` with `MAP_ANONYMOUS` and `MAP_SHARED`.
 *    - No file is involved (`fd = -1`).
 * 3. Copies the string into the mapped memory.
 * 4. Prints the address and contents of the mapped memory.
 * 5. Uses `getchar()` to pause execution at key steps so that the process can be inspected (e.g., via `pmap`).
 * 6. Unmaps the memory using `munmap()` based on the string length.
 *
 * Usage:
 *   gcc mmap_anon_example.c -o mmap_anon_example
 *   ./mmap_anon_example
 *
 * Notes:
 * - Since the mapping is anonymous, it is not backed by any file and the data is lost once the program exits.
 * - `MAP_SHARED` is used here, but for anonymous mappings with no sharing between processes, `MAP_PRIVATE` is often used.
 * - `getchar()` calls help in debugging or observing memory during runtime.
 *
 * Author: Monish Kumar
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
  char*str = "School of linux";
  printf("PID %d\n",getpid());
  getchar();
  
  //void *mmap(void addr[.length], size_t length, int prot, int flags,int fd, off_t offset);

  char*data = mmap(NULL,1024,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);

  strcpy(data,str);
  printf("%p %s\n",&data,data);
  getchar();
  munmap(data,strlen(data));
  getchar();
}
