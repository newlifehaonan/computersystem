#include	<stdlib.h>
#include	<stdio.h>

int		data		= 10;

int		bss		= 0;

int		main		()
{
  int*	heapPtr	= (int*)malloc(sizeof(int));
  int	stack	= 1;

  if  (fork() == 0)
  {
    *heapPtr = stack = data = bss = getpid();
  }
  else
  {
    *heapPtr = stack = data = bss = getpid();
  }

  printf("Process %d has stack = %d, heap = %d, data = %d, bss = %d\n",
         getpid(),stack,*heapPtr,data,bss
        );

  return(EXIT_SUCCESS);
}
