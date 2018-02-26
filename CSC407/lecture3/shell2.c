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

    int	status;

    wait(&status);

    if  (WIFEXITED(status) )
    {
      printf("Child did not crash ");

      if  (WEXITSTATUS(status) == EXIT_SUCCESS)
        printf("and it succeeded.\n");
      else
        printf("but it failed.\n");
    }
    else
      printf("Child crashed\n");

  }

  return(EXIT_SUCCESS);
}
