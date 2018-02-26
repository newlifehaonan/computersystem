#include"assign2Headers.h"

pid_t answererPid;
pid_t guesserPid;
int shouldRun =1;

void sigChildHandler(int signum)
{
  pid_t pid;
  int s;

  while( (pid=waitpid(-1,&s,WNOHANG)) > 0)
    if (WIFEXITED(s) != 0)
      printf("%d returned %d\n", pid,WEXITSTATUS(s));
    else
      printf("%d crashed!\n",pid);
  shouldRun = 0;
}

void sigAlarmHandler(int sigNum
		    )
{
  kill(answererPid, TIME_OVER_SIGNAL);
  kill(guesserPid, TIME_OVER_SIGNAL);
  shouldRun= 0;
}

int main()
{
  char line[LINE_LEN];
  struct sigaction act;

  memset(&act,'\0',sizeof(act));
  act.sa_handler= sigAlarmHandler;
  sigaction(SIGALRM,&act,NULL);
  
  memset(&act,'\0',sizeof(struct sigaction));
  act.sa_handler= sigChildHandler;
  act.sa_flags= SA_NOCLDSTOP | SA_RESTART;
  sigaction(SIGCHLD,&act,NULL);

  answererPid = fork();

  if  (answererPid == 0)
    {
      execl(ANSWERER_PROGNAME,ANSWERER_PROGNAME,NULL);
      printf("Cannot find %s\n",ANSWERER_PROGNAME);
      exit(EXIT_FAILURE);
    }

  guesserPid = fork();

  if  (guesserPid == 0)
    {
      snprintf(line,LINE_LEN,"%d",answererPid);
      execl(GUESSER_PROGNAME,GUESSER_PROGNAME,line,NULL);
      printf("Cannot find %s\n",GUESSER_PROGNAME);
      exit(EXIT_FAILURE);
    }

  alarm(NUM_SECONDS);

  while  (shouldRun)
    sleep(1);

  sleep(1);
  sleep(1);

  printf("launcher finished\n");
  return(EXIT_SUCCESS);
}


