#include "header.h"

char* os_abi(Elf64_Ehdr *header)
{
  switch(header->e_ident[EI_OSABI])
  {
    case ELFOSABI_SYSV:         return "UNIX System V ABI";
    case ELFOSABI_HPUX:         return "HP-UX ABI";
    case ELFOSABI_NETBSD:       return "NetBSD ABI";
    case ELFOSABI_LINUX:        return "Linux ABI";
    case ELFOSABI_SOLARIS:      return "Solaris ABI";
    case ELFOSABI_IRIX:         return "IRIX ABI";
    case ELFOSABI_FREEBSD:      return "FreeBSD ABI";
    case ELFOSABI_TRU64:        return "TRU64 UNIX ABI";
    case ELFOSABI_ARM:          return "ARM architecture ABI";
    case ELFOSABI_STANDALONE:   return "Stand-alone (embedded) ABI";
  }
}

char* type(Elf64_Ehdr *header)
{
  switch(header->e_type)
  {
    case ET_REL:         return "A relocatable file";
    case ET_EXEC:        return "An executable file.";
    case ET_DYN:         return "A shared object";
    case ET_CORE:        return "A core file";
  }
}

char* machine(Elf64_Ehdr *header)
{
  switch(header->e_machine)
  {
    case EM_M32:         return "AT&T WE 32100";
    case EM_X86_64:      return "AMD x86-64";
    case EM_SPARC:       return "Sun Microsystems SPARC";
    case EM_386:         return "Intel 80386";
    case EM_68K:         return "Motorola 68000";
  }
}
