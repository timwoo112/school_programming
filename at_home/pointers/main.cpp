#include <iostream>
using namespace std;

int main()
{
  int myVar = 25;
  int* myPointer = nullptr;
  myPointer = &myVar;
  
  cout << "The value of myVar is: " << myVar << endl;
  cout << "The memory location of myVar is: " << myPointer << endl;
  cout << "The value of myPointer using de-referencing: " << *myPointer << endl;

  // Changing value of myVar using the pointer
  *myPointer += 1;
  cout << "New value of myVar: " << myVar << endl;
  
  return 0;
}
