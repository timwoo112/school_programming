#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ofstream myfile;
  myfile.open("test.txt");

  myfile << "line 1\n";
  myfile << "line 2\n";

  myfile.close();
  
  return 0;
}
