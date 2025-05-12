#ifndef HEADER_H
#define HEADER_H

// Standard headers you need across all C files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>
#include <sys/stat.h>
#include <stddef.h>   // For NULL
#include <sys/types.h> // For ssize_t

// Function declarations
void help();
void options(int argc, char *argv[]);

#define Buffsize 1   // Your buffer size constant (optional but helpful)

#endif

