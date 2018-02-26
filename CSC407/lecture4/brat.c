#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<signal.h>

int		main		()
{
  struct sigaction	act;

  memset(&act,'\0',sizeof(act));
  act.sa_handler = SIG_IGN;// Ignore SIGINT
  sigaction(SIGINT,&act,NULL);

  while  (1)
  {
    printf("Ngyeah-ngyeah!  You can't stop me!\n");
    sleep(2);
  }

  return(EXIT_SUCCESS);
}
