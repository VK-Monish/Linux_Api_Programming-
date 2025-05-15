#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <math.h>

char* os_abi (Elf64_Ehdr *header);
char* type   (Elf64_Ehdr *header);
char* machine(Elf64_Ehdr *header);

#endif
