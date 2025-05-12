#include "header.h"


void options(int argc, char* argv[]) 
{
  int c;
  int index = 0;

  struct option long_options[] = {
    {"chmod"    ,  required_argument,  0, 'c'},
    {"wordcount",  required_argument,  0, 'w'},
    {"help"     ,  no_argument      ,  0, 'h'},
    {0, 0, 0, 0}
  };
 
  //int getopt_long(int argc, char *argv[],const char *optstring,const struct option *longopts, int *longindex);

  while ((c = getopt_long(argc, argv, "hc::w:", long_options, &index)) != -1) 
  {
    switch (c)
    {
      case 'c':
	
	if(optind+1 >= argc)
	{
	  printf("Please enterd the argument\n");
	  printf("\n");
	  help();
	  exit(-1);
	}
	int fd;
        mode_t new_mode;
	
	//strtol("0", NULL, base);

        new_mode = strtol(argv[2],NULL,8);
        fd = chmod(argv[3],new_mode);
        break;
      
      case 'h':
	
	help();
        break;
      
      case 'w':
	
	int fd1,i;
        int j=0;
        char buf;
        ssize_t bytecnt;
	
	//int open(const char *pathname, int flags, .../* mode_t mode */ );
        
	fd1 = open(argv[2],O_RDONLY);
        
	// ssize_t read(int fd, void buf[.count], size_t count);
        
	while(bytecnt > 0)
	{
	  bytecnt = read(fd1,&buf,Buffsize);
          if (buf == ' ' || buf == '\n' || buf == '\t')
	  {
	    i=0;
	  }
	  else if(i==0)
	  {
	    j++;
            i=1;
	  }
	}
	printf("The total number of words:%d",j+1);
        break;
      case '?':
        help();
        break;
        }
    }
}
