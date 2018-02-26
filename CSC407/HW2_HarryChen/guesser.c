#include "assign2Headers.h"

int shouldRun =1;
void TimeOverHandler(int sigNum
		    )
{
  printf("Oh no!  The time is up!\n");
  shouldRun= 0;
}

void WinHandler(int sigNum
		    )
{
  printf("Congratulations!  You found it!\n");
  shouldRun= 0;
}

void CorrectHandler(int sigNum
		    )
{
  printf("Yay!  That was right!\n");
}

void IncorrectHandler(int sigNum
		    )
{
  printf("Oops!  That was wrong.  Please restart from the beginning.\n");
}

int main (int argc, char* argv[])
{
  struct sigaction act;

  memset(&act,'\0',sizeof(act));
  act.sa_handler = WinHandler;
  sigaction(WIN_SIGNAL,&act,NULL);

  memset(&act,'\0',sizeof(act));
  act.sa_handler = CorrectHandler;
  sigaction(CORRECT_SIGNAL,&act,NULL);

  memset(&act,'\0',sizeof(act));
  act.sa_handler = IncorrectHandler;
  sigaction(INCORRECT_SIGNAL,&act,NULL);

  memset(&act,'\0',sizeof(act));
  act.sa_handler = TimeOverHandler;
  sigaction(TIME_OVER_SIGNAL,&act,NULL);
  
  char line[LINE_LEN];
  if( argc == 0)
    {
      printf("Not enough argument!\n");
      return(EXIT_FAILURE);
    }
  
  int answerid = strtol(argv[1],NULL,10);
  
  while(shouldRun)
    {
     printf("What would you like your next guess to be: 0 or 1?");
     fgets(line, LINE_LEN, stdin);
     int guessNum = strtol(line,NULL,10);

     if(guessNum == 0)
       {
       kill(answerid, ZERO_SIGNAL);
       sleep(1);
       }

     if(guessNum == 1)
       {
       kill(answerid, ONE_SIGNAL);
       sleep(1);
       }
    }
  printf("guesser finished\n");
  return(EXIT_SUCCESS);
}
