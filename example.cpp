#include<iostream>
#include<thread>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

void func1(){
	std::cout<<"Func1 called"<<endl;
}
void func2(){
	std::cout<<"Func2 called"<<endl;
}

int main(){
	thread p1(func1);
	thread p2(func2);
	p1.join();
	p2.join();
	return 0;
}
