#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 256

int main (int argc, const char* argv[])
{

  if (argc < 3)
  {
    fprintf(stderr, "Usage: charCount <char> <file>\n");
    return(EXIT_FAILURE);
  }

  const char charToCount	= *argv[1];
  const char* fileCPtr		= argv[2];


  int	fd	= open(fileCPtr,O_RDONLY,0);

  if  (fd < 0)
  {
    fprintf(stderr,"Cannot open %s\n",fileCPtr);
    exit(EXIT_FAILURE);
  }

  int	counter	= 0;
  char	buffer[BUFFER_SIZE];
  int	numBytes;

  while  ( (numBytes = read(fd,buffer,BUFFER_SIZE)) > 0 )
  {
    int	i;

    for  (i = 0;  i < numBytes;  i++)
      if  (buffer[i] == charToCount)
        counter++;

  }

  close(fd);
  printf("%d\n",counter);
  return(EXIT_SUCCESS);
}
