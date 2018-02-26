#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<signal.h>
#include	<unistd.h>

#define		MAX_LINE	64

int		shouldRun	= 1;

void		tickleHandler	(int		signum,
				 siginfo_t*	infoPtr,
				 void*		dataPtr
				)
{
  if  (infoPtr->si_pid == getppid())
    printf("Elmo: \"Hee-hee!  That tickles!\"\n");
  else
    printf("Elmo: \"Do I know you, Mister!?!\"\n");
}


void		sigTermHandler	(int		signum
				)
{
  shouldRun	= 0;
}

int		main		()
{
  pid_t	childId;

  childId	= fork();

  if  (childId == 0)
  {
    struct sigaction	act;

    memset(&act,'\0',sizeof(act));
    act.sa_sigaction	= tickleHandler;
    act.sa_flags	= SA_SIGINFO;
    sigaction(SIGINT,&act,NULL);

    memset(&act,'\0',sizeof(act));
    act.sa_handler	= sigTermHandler;
    sigaction(SIGTERM,&act,NULL);

    while  (shouldRun)
      sleep(1);

    printf("Elmo: \"Now going to bed\"\n");
    exit(EXIT_SUCCESS);
  }

  int		i;
  char		line[MAX_LINE];

  for  (i = 0;  i < 4;  i++)
  {
    printf("Press enter to tickle your Elmo:\n");
    fgets(line,MAX_LINE,stdin);
    kill(childId,SIGINT);
  }

  kill(childId,SIGTERM);

  return(EXIT_SUCCESS);
}
