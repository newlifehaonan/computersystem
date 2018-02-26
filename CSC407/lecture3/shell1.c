#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>

#define		MAX_LINE	256

#define		QUIT_CMD	"exit"

int		main		()
{
  char		line[MAX_LINE];

  while  (1)
  {
    printf("What program do you want to run? ");
    fgets(line,MAX_LINE,stdin);

    char* cPtr = strchr(line,'\n');
    if (cPtr != NULL)
      *cPtr = '\0';

    if  (strcmp(line,QUIT_CMD) == 0)
      break;

    pid_t	childId	= fork();

    if  (childId == 0)
    {
      execl(line,line,NULL);
      printf("Cannot find %s\n",line);
      exit(EXIT_FAILURE);
    }

  }

  return(EXIT_SUCCESS);
}
