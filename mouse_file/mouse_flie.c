/*
Mouse Event Reader in C

This program reads and interprets mouse events from a Linux input device file (e.g., /dev/input/event5).

---

Program Behavior:
- Opens the specified input device file for reading mouse events.
- Continuously reads input_event structures from the device.
- Detects mouse button clicks (right, left, middle) based on event codes.
- Detects mouse movement directions on the X and Y axes.
- Prints corresponding messages to the terminal for each detected event.

Requirements:
- Linux system with input event device files (under /dev/input/).
- Proper permissions to read from the device file (usually requires root or appropriate group).
- `<linux/input.h>` header for input_event struct and event codes.

How to Compile:
    gcc mouse_event_reader.c -o mouse_event_reader

How to Run:
    sudo ./mouse_event_reader

Notes:
- Update the device file path ("/dev/input/event5") to match your mouse input device.
- Program runs indefinitely; terminate manually (e.g., Ctrl+C).
- Event codes 272, 273, 274 correspond to mouse buttons (right, left, middle).
- Movement detection is based on event codes and value changes for X and Y axes.
- Reading from input device requires appropriate permissions.
- The program currently prints simple messages; it can be extended for more complex input handling.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <linux/input.h>

#define Buffer_size 64

int main()
{
  char buf[Buffer_size];
  int fd;
  size_t read_mouse;
  struct input_event ev;
  // int open(const char *pathname, int flags, .../* mode_t mode */ );
  
  fd = open("/dev/input/event5",O_RDONLY);
  if(fd == -1)
  {
    perror("open");
    exit(-1);
  }

  // ssize_t read(int fd, void buf[.count], size_t count);

  while(1)
  {
    read_mouse = read(fd,&ev,sizeof(struct input_event));
    if(read_mouse == -1)
    {
      perror("Read");
      exit(-1);
    }
    if(ev.code == 272)
    {
      printf("Right click\n");
    }
    else if(ev.code == 273)
    {
      printf("Left click\n");
    }
    else if(ev.code == 274)
    {
      printf("Midlle button clicked\n");
    }
    else if(ev.code == 0 && ev.value == -1)
    {
      printf("moving X' direction\n");
    }
    else if(ev.code == 0 && ev.value == 1)
    {
      printf("moveing X direction\n");
    }
    else if(ev.code == 1 && ev.value == -1)
    {
      printf("moveing Y' direction\n");
    }
    else if (ev.code == 1 && ev.value == 1)
    {
      printf("moving Y direction\n");
    }
  } 
    close(fd);
}
