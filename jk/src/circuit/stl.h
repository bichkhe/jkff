#ifndef _JK_ARRAY_H_
#define _JK_ARRAY_H_


/*
 * @author : bichkhe
 * @date : 26-07
 */

#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;


class JKArray 
{

 public:
  JKArray(){cout<< "Constructor---!"<<endl;}
  virtual ~JKArray(){ cout << "~Destructor !" <<endl;}
 
  
 private:
  
  array<string,100> mPeople;
  vector<string> mBooks;
  map<string, string> mOthers;
  
 public:
  int i;
 public:
  
  void AddBook(const string& name);
  int& getPeople(int& m)
  {
    int& l = m;
    std::cout << "L--------------:" << &l;
    int k = 20;
    std::cout << "K--------------:" << &k;
    std::cout << "Address:" << &m;
    std::cout << "Address of people:" << &mPeople;
    l+=100;
    return l;
   }

   friend ostream& operator(ostream& os,const  JKArray& jk)  
  {
	os << "JKarry : " << jk.i<< endl;
	return os;
  }
};


#endif // end of JK_ARRAY_H_
