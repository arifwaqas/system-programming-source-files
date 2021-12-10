#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int arr[4]={0,1,2,3};

void* func(void* args){
  int index=*(int*)args;
  printf("%d ", index);
}

int main(){
  pthread_t pid[4];
  int i;

  for(i=0; i<4; i++){
    if(pthread_create(&pid[i],NULL,&func,arr+i)!=0) return 1;
  }
  for(i=0; i<4; i++){
    if(pthread_join(pid[i],NULL)!=0) return 2;
  }
  return 0;
}
