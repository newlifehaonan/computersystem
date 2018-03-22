#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#define		BUFFER_LEN	256
#define		COMMENT_CHAR	'#'

int		main		(int	argc,
				 char*	argv[]
				)
{
  if  (argc < 2)
  {
    fprintf(stderr,"Usage:\tintPairCounter filePath\n");
    exit(EXIT_FAILURE);
  }

  const char*	filePath	= argv[1];
  FILE*		filePtr		= fopen(filePath,"r");

  if  (filePtr == NULL)
  {
    fprintf(stderr,"Cannot open %s\n",filePath);
    exit(EXIT_FAILURE);
  }

  char		buffer[BUFFER_LEN];
  int		counter	= 0;
  int		lineNum	= 0;

  while  (fgets(buffer,BUFFER_LEN,filePtr) != NULL)
  {
    char*	charPtr;
    int		i,j;

    lineNum++;

    for  (charPtr = buffer;  isspace(*charPtr);  charPtr++);

    if  ( (*charPtr == COMMENT_CHAR) || (*charPtr == '\0') )
      continue;

    if  (sscanf(charPtr,"%d %d",&i,&j) == 2)
      counter++;
    else
      fprintf(stderr,"Insufficient integers on line %d\n",lineNum);
  }

  fclose(filePtr);
  printf("%d\n",counter);
  return(EXIT_SUCCESS);
}


