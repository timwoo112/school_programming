#include <iostream>

using namespace std;

int linearSearch(const int[], int, int, int=1);

int main()
{
  const int SIZE = 6;
  int tests[SIZE] = {87,75, 98, 100, 82, 100};
  int results;

  results = linearSearch(tests, SIZE, 100);

  if (results == -1)
    {
      cout << "\nThe search item was not found.\n";
    }
  else
    {
      cout << "\nThe search  item was found at element #" << (results + 1) << " and position# #" << results << " in the array.\n";
    }

  results = linearSearch(tests, SIZE, 100, 2);

  if (results == -1)
    {
      cout << "\nThe search item was not found.\n";
    }
  else
    {
      cout << "\nThe search  item was found at element #" << (results + 1) << " and position# #" << results << " in the array.\n"; 
    }

  return 0;
}

int linearSearch(const int arr[], int size, int value, int occ)
{
  int index = 0;
  int position = -1;
  int occur = 0;
  bool found = false;

  //While loop
    while(index < size && !found)
    {
      if (arr[index] == value)
	{
	  occur += 1;
	  if(occur == occ)
	    {
	      found = true;
	      position = index;
	    }
	}
      index++;
    }
    return position;
}
