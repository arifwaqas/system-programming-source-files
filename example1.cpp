#include <iostream>
#include <thread>

void func1(){
  std::cout<<"Func1 called from "<<std::this_thread::get_id()<<std::endl;
}

void func2(){
  std::cout<<"Func2 called from "<<std::this_thread::get_id()<<std::endl;
}

int main(int argc, char **argv){
  std::cout<<"This program also prints command line arguments ";
  printf("%s\n", argv[1]);
  //First always contains the file names
  std::thread p1(func1);
  std::thread p2(func2);
  p1.join();
  p2.join();
  return 0;
}
