#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	<signal.h>

#define		MAX_LINE	256

#define		QUIT_CMD	"exit"

void		sigChildHandler	(int	signum
				)
{
  pid_t pid;
  int s;

  while( (pid=waitpid(-1,&s,WNOHANG)) > 0)
    if (WIFEXITED(s) != 0)
      printf("%d returned %d\n", pid,WEXITSTATUS(s));
    else
      printf("%d crashed!\n",pid);
}


int		main		()
{
  char			line[MAX_LINE];
  struct sigaction	act;

  memset(&act,'\0',sizeof(struct sigaction));
  act.sa_handler	= sigChildHandler;
  act.sa_flags		= SA_NOCLDSTOP | SA_RESTART;
  sigaction(SIGCHLD,&act,NULL);

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
