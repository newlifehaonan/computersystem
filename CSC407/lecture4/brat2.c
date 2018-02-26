#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<signal.h>

void		sigIntHandler	(int	signum
				)
{
  const char*	cPtr;

  switch (rand() % 4)
  {
  case 0 : cPtr = "Ouch!";		break;
  case 1 : cPtr = "Leave me alone!";	break;
  case 2 : cPtr = "I hate you!";	break;
  case 3 : cPtr = "Get a life!";	break;
  }
  printf("%s\n",cPtr);
}


int		main		()
{
  struct sigaction	act;

  memset(&act,'\0',sizeof(act));
  act.sa_handler = sigIntHandler;
  sigaction(SIGINT,&act,NULL);

  while  (1)
  {
    printf("Ngyeah-ngyeah!  You can't stop me!\n");
    sleep(2);
  }

  return(EXIT_SUCCESS);
}
