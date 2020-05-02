#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

struct myStruct
{
  int member1;
  int member2;
};

void testFun(int);

int main()
{

  myStruct ohyeah = {112, 1112};

  testFun(ohyeah.member1);
  
  return 0;
}

void testFun(int myVar)
{
  cout << myVar << endl;
}
