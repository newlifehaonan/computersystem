#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<time.h>

#define		BUFFER_LEN	256

int		main		(int	argc,
				 char*	argv[]
				)
{
  const char*	dirName	= (argc >= 2) ? argv[1] : ".";
  DIR*		dirPtr	= opendir(dirName);

  if  (dirPtr == NULL)
  {
    fprintf(stderr,"Cannot open %s\n",dirName);
    exit(EXIT_FAILURE);
  }

  struct stat		statBuffer;
  struct dirent*	entryPtr;
  char			entryPath[BUFFER_LEN];

  while  ( (entryPtr = readdir(dirPtr)) != NULL )
  {
    snprintf(entryPath,BUFFER_LEN,"%s/%s",dirName,entryPtr->d_name);
    stat(entryPath,&statBuffer);

    if  ( S_ISREG(statBuffer.st_mode) )
      printf("%20s\t%u\t%s",entryPtr->d_name,statBuffer.st_size,ctime(&statBuffer.st_mtime));
    else
    if  ( S_ISDIR(statBuffer.st_mode) )
      printf("%20s\t%s\t%s",entryPtr->d_name,"(DIR)",ctime(&statBuffer.st_mtime));
    else
      printf("%20s\t%s\t%s",entryPtr->d_name,"(OTHER)",ctime(&statBuffer.st_mtime));
  }

  closedir(dirPtr);
  return(EXIT_SUCCESS);
}








