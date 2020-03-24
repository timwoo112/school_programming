#include <iostream>
#include <array>
using namespace std;

array<float, 9> inputArray();
void printFormattedArray(array<float,9>);

int main()
{
  array<float,9> prices;
  // Fill in the array
  prices = inputArray();

  // Print out the array in formatted style
  printFormattedArray(prices);
  return 0;
}

array<float,9> inputArray()
{
  array<float,9> priceArray;
  // Get input for the array.
  for (int i=0; i <= priceArray.size() - 1; i++)
    {
      cout << "Enter value: ";
      while(!(cin >> priceArray[i]))
	{
	  cout << "Invalid input, try again: ";
	  cin.clear();
	  cin.ignore(10000, '\n');
	}
    }
  // Print out the values that the user entered into the array.
  for (int i=0; i <= priceArray.size() - 1; i++)
    {
      if (i != priceArray.size() - 1)
	{
	  cout << priceArray[i];
	}
    }

  return priceArray;
}

void printFormattedArary(array<float,9> priceArray)
{
  cout << priceArray << endl;
  
}
