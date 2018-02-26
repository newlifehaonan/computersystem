#include	<stdlib.h>
#include	<stdio.h>
#include	<pthread.h>


int		data		= 10;
int		bss		= 0;

struct TwoIntPtr{ int* int0Ptr; int* int1Ptr; };

void*		function	(void*	vPtr)
{
  struct TwoIntPtr*	twoIntPtrPtr	= (struct TwoIntPtr*)vPtr;

  data++;
  bss++;
  (*(*twoIntPtrPtr).int0Ptr)++;
  (*twoIntPtrPtr->int1Ptr)++;
  return(NULL);
}

void		addEverything	(int	local,
				 int*	heapPtr
				)
{
  printf("data (%d) + bss (%d) + local (%d) + heap (%d) = %d\n",
	 data,bss,local,*heapPtr, data+bss+local+*heapPtr
	);
}

int		main		()
{
  int		local		= 7;
  int*		heapPtr		= (int*)malloc(sizeof(int));
  pthread_t	threadId;
  struct TwoIntPtr	myStruct;

  *heapPtr			= 5;
  myStruct.int0Ptr		= &local;
  myStruct.int1Ptr		= heapPtr;
  addEverything(local,heapPtr);
  pthread_create(&threadId,NULL,function,(void*)&myStruct);
  pthread_join  (threadId,NULL);
  addEverything(local,heapPtr);
  free(heapPtr);
  return(EXIT_SUCCESS);
}
