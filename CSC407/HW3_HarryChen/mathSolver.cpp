/*-------------------------------------------------------------------------*
 *------*
 *---mathSolver.cpp---*
 *------*
 *---    This file defines the high-level functions of the math ---*
 *---generator and solver program.---*
 *------*
 *--------------------------------------*
 *------*
 *---Version 1a2018 February 22Joseph Phillips---*
 *------*
 *-------------------------------------------------------------------------*/

//
//Compile with:
//$ g++ mathSolver.cpp -o mathSolver -lpthread -g
//


#include"mathSolverHeader.h"


void* evaluate(void* vPtr
	      )
{
  NodeBuffer* nodeBufferPtr = (NodeBuffer*)vPtr;
  for  (int i = 0;  i < (NUM_PROBLEMS)/2;  i++)
    {
      Node* j = nodeBufferPtr->pullOut();
      printf("%d %s = %f\n",i,j->toString().c_str(),j->eval());
      delete(j);
      fflush(stdout);
    }
  return(NULL);
  //  YOUR CODE HERE
}


//  PURPOSE:  To return a randomly generated Node.
Node* makeNode()
{
  return( (rand() % 3) ? (Node*)new ConstNode() : (Node*)new OperatorNode() );
}


int main(int argc,
	 char* argv[]
	)
{
  NodeBuffer nodeBuffer;
  pthread_t consumer0;
  pthread_t consumer1;
  int toReturn = EXIT_SUCCESS;

  srand( (argc < 2) ? getpid() : atoi(argv[1]) );

  //  YOUR CODE HERE
  pthread_create(&consumer0,NULL,evaluate,&nodeBuffer);
  pthread_create(&consumer1,NULL,evaluate,&nodeBuffer);

  for(int i = 0;  i < NUM_PROBLEMS; i++){
    printf("make %d\n",i);
    (&nodeBuffer)->putIn(makeNode()); //might have problem
  }
  
  pthread_join(consumer1,NULL);
  pthread_join(consumer0,NULL);
  
  return(toReturn);
}
