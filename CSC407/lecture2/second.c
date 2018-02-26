#include	"123.h"

#define		ARRAY_LEN	16

void		enterBeginEnd	()
{
  char	line[ARRAY_LEN];

  printf("Please enter a character: ");
  fgets(line,ARRAY_LEN,stdin);
  begin	= line[0];

  do
  {
    printf("Please enter an character: ");
    fgets(line,ARRAY_LEN,stdin);
    end	= line[0];
  }
  while  (end < begin);

}
