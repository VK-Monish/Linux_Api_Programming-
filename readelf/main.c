#include "header.h"

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
  printf("Magic Number:                      ");
  for(int i=0; i < 16; i++)
  {
    printf("%2.2x ",header.e_ident[i]);
  }
  printf("\n");
  printf("Data:                              %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2'Complement Little India" : "bigindian");
  printf("OS/ABI:                            %s\n", os_abi(&header));
  printf("Version:                           %x\n", header.e_version);
  printf("ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
  printf("Type:                              %s\n", type(&header));
  printf("Machine:                           %s\n", machine(&header));
  printf("Entry point address:               0x%lx\n", header.e_entry);
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
