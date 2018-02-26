#include	<stdlib.h>
#include	<stdio.h>

int		main		()
{
  int		i;
  int		numReturned;

  while  (1)
  {
    printf("Please enter an integer: ");
    numReturned = scanf("%d",&i);

    printf("numReturned = %d, i = %d\n",numReturned,i);
  }

  return(EXIT_SUCCESS);
}
