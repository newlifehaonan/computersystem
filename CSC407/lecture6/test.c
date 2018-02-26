#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main ()
{
  char line[10];
  printf("please enter a word:\n");
  if (fgets(line, sizeof(line), stdin) != NULL) {

    int len = strlen(line);
    if (len > 0 && line[len-1] == '\n') {
      line[--len] = '\0';
    }


    printf("string size is : %d\n", len);
    for(int i=0; i< len; i++){
      if(line[i] == '\n'){
        printf("n \n");
      }
      else
        printf("%c \n", line[i]);
    }
  }
}


const char* getPathText(int argc,
                       char*argv[],
                       char* textSpace,
                       int textSpaceLen
                       )
{
  // char line[LINE_LEN];
  if(argc < 1){
    char line[10];
    printf("please enter a word:\n");
    if (fgets(line, sizeof(line), stdin) != NULL) {

      int testSpaceLen = strlen(line);
      if (testSpaceLen > 0 && line[testSpaceLen-1] == '\n') {
        line[--testSpaceLen] = '\0';
      }

      for(int i = 0; i < testSpaceLen; i++){
        *textSpace = line[i];
      }
    }
    return textSpace;
  }
  else
    return argv[1];
}
