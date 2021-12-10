#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
//-pthread as argument to gcc command

int mails=0;
//Creation of mutex
pthread_mutex_t mutex;

void* rollDice(){
  int rollDiceValue=rand();
  int *res=malloc(sizeof(int));
  *res=rollDiceValue;
  return (void*) res;
}

int main(int argc, char** argv)
{
  srand(time(NULL));
  //STRUCT
  int *res;
  pthread_t t1;
  //pthread_create(pointer to thread variable, customization attributes, func pointer,arguments for func)
  if(pthread_create(&t1, NULL, &rollDice, NULL)!=0) return 1;
  //struct and pointer to return value from thread
  if(pthread_join(t1, (void**) &res)) return 2;
  printf("Returned number is %d.\n", *res);
  printf("Returned address is %p.\n", res);
  return 0;
}
