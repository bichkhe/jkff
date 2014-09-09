#include <vector>
#include <string>
#include "../../src/circuit/stl.h"
#include <thread>
#include <stdio.h>
#include <mutex>
//#include <lock_guard>
using namespace std;

class JKThread
{
public:
  JKThread(){std::cout<< "JK Thread constructor!"<<std::endl;}
  JKThread(const JKThread& jk)
  {
    std::cout <<"JK Thread Copy Constructor! ..." <<std::endl;
  }
  void operator()()
  {
    std::cout << "From t1";
  }
  void test(int i)
  {
    // std::lock_guard<std::mutex> guard(mu);
    for (int i =0; i<100; i++)
	{
	  std::cout << "From t1: " << i<<std::endl;
	}
  }
  template <typename F>
  void process_data(F f)
  {
    std::lock_guard<std::mutex> guard(mu);
    f(mArray);
  }
  

private:
  std::mutex mu;
  JKArray mArray;

};


int gI =10;
static int gL= 20;



int main(const int argc, char* argv[], char* env[])
{

  std::cout << &gI;
  std::cout << &gL;

  JKArray jk;
  jk.AddBook("Run Away");
  int m =10;
  int k =20;
  
  std::cout << &m <<std::endl;
  std::cout << &k<<std::endl;
  int z =jk.getPeople(m);
  std::cout << &z<<std::endl;
  std::cout <<"Z----------------:"<< z <<std::endl;
  JKThread jkthread ;
  std::cout << &jk <<" "<< &(jk.i)<<std::endl ;
  char* name = "Hello world";
  std:cout <<"Name:" << name <<std::endl;
  std::cout<< 'Address:' << &name<<std::endl;
  
  void (JKArray::* pFunc)(const string&) = &JKArray::AddBook;
  void* pPtr = (void*&) pFunc; // this works

  // std::thread t1 ((JKThread()));
  std::cout << "--" << &pPtr <<std::endl;
  
  // TEST 
  char c = 'A';
  char b = 'B';
 
  int i1 = (unsigned char)c;
  int i2 = (unsigned char)b;
  double f1 = 10.2344;
  int i4  = static_cast<int>(f1);
  cout << "i4: " << i4<<endl;

  int i5 = 65;
  char c1 = static_cast<char>(i5);
  std::cout << "c1 : " << c1 << endl;

  void* p1 = &i1;
  cout <<"Address of p1 : " << &p1 <<endl;
  int* p2 = static_cast<int*>(p1);
  cout <<"Address of p2 : " << &p2 <<endl;
  std::cout << "p2: " << *p2 << endl;

  int i3 = static_cast<int>(c);
  std::cout << "i1:" << i1 << " i2: " << i2 <<endl ;
  std::cout << "i2-i1 :  " << i2-i1 <<endl;

  std::cout << "i3 :   " << i3 <<endl;
  // try 
  //   {
  //     for (int i =0; i<100; i++)
  // 	{
  // 	  std::cout << "From main: " << i<<std::endl;
  // 	}
  
  //   }
  // catch (...)
  //   {
  //     t1.join();
  //     throw;
  //   }
  // t1.join();
  return 0;
}
