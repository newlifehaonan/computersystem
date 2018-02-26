#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

char* niceCopy (const char* fromP, int n)
{
  int	fromLen	= strlen(fromP);
  int   numCharsToCopy = (fromLen < n) ? fromLen : n;
  char* toP	= (char*)malloc(numCharsToCopy + 1);
  char*	toReturn= toP;
  int	i;

  for (i = 0 ; i < numCharsToCopy; fromP++, toP++, i++)
    *toP = *fromP;

  *toP	= '\0';
  return(toReturn);
}


int		main		()
{

  int	i;

  for  (i = 0;  i < 30;  i++)
  {
    char*	cPtr	= niceCopy("Hello class",i);

    printf("%s\n",cPtr);
    free(cPtr);
  }

  return(EXIT_SUCCESS);
}
