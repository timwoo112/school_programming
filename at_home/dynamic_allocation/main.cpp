#include <iostream>
#include <memory>
using namespace std;

int main()
{
  // Dynamic array allocation
  const int SIZE = 5;
  unique_ptr<int []> myPtr(new int[SIZE]);

  // Single variable dynamic allocation
  int* POINTY = nullptr;
  int random_int = 544;
  POINTY = &random_int;

  cout << "POINTY: " << *POINTY << endl;
  cout << POINTY << endl;
  
  for (int count = 0; count < SIZE; count++)
    {
      myPtr[count] = count;
      cout << myPtr[count] << endl;
    }

  for (int count = 0; count < SIZE; count ++)
    {
      cout << &(myPtr[count]) << endl;
    }
  
  return 0;
}
