/*
ELF Header Reader in C

This program reads and displays key fields from the ELF (Executable and Linkable Format) header of a given binary file.

---

Program Behavior:
- Opens a specified ELF file provided as a command-line argument.
- Reads the ELF header (Elf64_Ehdr) from the file.
- Prints the magic number and important ELF header fields like:
  - OS/ABI
  - ABI Version
  - Type
  - Machine architecture
  - Entry point address
  - Program headers offset
  - Section headers offset
  - Flags
  - Sizes and counts of headers
  - Section header string table index
- Closes the file descriptor after reading.

Requirements:
- POSIX-compliant OS with ELF binaries (e.g., Linux).
- C compiler (e.g., GCC).
- ELF header definitions from `<elf.h>`.

How to Compile:
    gcc elf_header_reader.c -o elf_header_reader

How to Run:
    ./elf_header_reader /path/to/elf/binary

Expected Output:
- Displays hexadecimal magic number bytes.
- Prints various ELF header metadata fields with their values.

Notes:
- The program assumes a 64-bit ELF binary.
- No validation is performed to check if the file is a valid ELF file.
- The program prints error if the file cannot be opened.
- The offsets and sizes are in bytes.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <math.h>

int main(int argc,char*argv[])
{
  int fd;
  size_t bytecnt;

  //int open(const char *pathname, int flags, .../* mode_t mode */ );

  fd = open(argv[1], O_RDONLY);
  if(fd == -1)
  {
    perror("OPEN");
  }
  Elf64_Ehdr header;

  bytecnt = read(fd, &header, sizeof(header));
  printf("Magic Number :");
  for(int i=0; i < 16; i++)
  {
    printf("%2.2x ",header.e_ident[i]);
  }
  printf("\n");
  printf("OS/ABI:                            %d\n", header.e_ident[EI_OSABI]);
  printf("ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
  printf("Type:                              %x\n", header.e_type);
  printf("Machine:                           %x\n", header.e_machine);
  printf("Version:                           %x\n", header.e_version);
  printf("Entry point address:               %lx\n", header.e_entry);
  printf("Start of program headers:          %lu (bytes into file)\n", header.e_phoff);
  printf("Start of section headers:          %lu (bytes into file)\n", header.e_shoff);
  printf("Flags:                             0x%x\n", header.e_flags);
  printf("Size of this header:               %d (bytes)\n", header.e_ehsize);
  printf("Size of program headers:           %d (bytes)\n", header.e_phentsize);
  printf("Number of program headers:         %d\n", header.e_phnum);
  printf("Size of section headers:           %d (bytes)\n", header.e_shentsize);
  printf("Number of section headers:         %d\n", header.e_shnum);
  printf("Section header string table index: %d\n", header.e_shstrndx);
  close(fd);
}
