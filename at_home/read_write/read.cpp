#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream test;
  string reader;
  
  test.open("test.txt");

  test >> reader;
  cout << reader << endl;

  test.close();
  
  return 0;
}
