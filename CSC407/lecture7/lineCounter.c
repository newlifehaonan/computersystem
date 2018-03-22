#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#define		BUFFER_LEN	256

int		main		(int	argc,
				 char*	argv[]
				)
{
  if  (argc < 3)
  {
    fprintf(stderr,"Usage:\tlineCounter lookForString filePath\n");
    exit(EXIT_FAILURE);
  }

  const char*	lookFor	= argv[1];
  const char*	filePath= argv[2];
  FILE*		filePtr	= fopen(filePath,"r");

  if  (filePtr == NULL)
  {
    fprintf(stderr,"Cannot open %s\n",filePath);
    exit(EXIT_FAILURE);
  }

  char		buffer[BUFFER_LEN];
  int		lookForLen	= strlen(lookFor);
  int		counter		= 0;

  while  (fgets(buffer,BUFFER_LEN,filePtr) != NULL)
  {
    if  (strncmp(lookFor,buffer,lookForLen) == 0)
      counter++;
  }

  fclose(filePtr);
  printf("%d\n",counter);
  return(EXIT_SUCCESS);
}









