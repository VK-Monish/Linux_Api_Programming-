/*
 * File: sbrk_heap_demo.c
 * Description:
 *   This program demonstrates the use of the `sbrk()` system call to inspect and extend
 *   the heap segment of the process in a Linux environment.
 *
 * How It Works:
 *   - Prints the current process ID using `getpid()`.
 *   - Calls `sbrk(0)` to get the current end address of the heap (the program break).
 *   - Waits for user input (`getchar()`) before extending the heap.
 *   - Calls `sbrk(1 << 30)` to increase the heap size by 1 GiB (1 shifted left by 30 bytes).
 *   - Prints the new heap end address returned by `sbrk()`.
 *   - Waits for user input again before program termination.
 *
 * Output:
 *   - Displays the initial heap end pointer.
 *   - Displays the heap end pointer after heap extension.
 *
 * Notes:
 *   - `sbrk(0)` returns the current location of the program break (heap end).
 *   - `sbrk(n)` moves the program break by `n` bytes; in this case, extending the heap.
 *   - Extending the heap by 1 GiB may fail if the system does not have enough memory.
 *   - This is a low-level memory management technique rarely used directly in modern applications.
 *
 * Usage:
 *   Compile: gcc sbrk_heap_demo.c -o sbrk_demo
 *   Run: ./sbrk_demo
 *   Follow prompts and observe heap end pointer changes.
 *
 * Caution:
 *   - Be careful with large allocations using `sbrk()` as it can cause the program or system instability.
 *   - Modern programs generally use `malloc()` for dynamic memory management.
 */

#include <stdio.h>
#include <unistd.h>
int main()
{
  void *l;
  printf("getpid %d\n",getpid());
  l= sbrk(0);   
  printf("The intial heap end point %p\n",l);
  getchar();
  l= sbrk(1<<30);
  printf("The final heap end point  %p\n",l);
  getchar();
}
