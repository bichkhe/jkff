
#include "stl.h"


void JKArray::AddBook(const string& name)
{
  mBooks.push_back(name);
  for (auto book : mBooks)
    {
      cout << book <<endl;
    }
}


/*
int main()
{

  cout << "Begin---!";
  return 0;
}
*/
