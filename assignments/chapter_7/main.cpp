#include <iostream>
#include <array>
using namespace std;

array<float,9> enterArray();
void printFormattedArray(array<float,9>);

int main()
{
  // Create array of type float with size of 9
  array<float,9> prices;

  // User the enterArray function to provide input to the array
  // and then print it out. I provided the test input to make it easier to grade
  cout << endl << "Part (a), input the following values into the array: 10.95, 16.32, 12.15, 8.22, 15.98, 26.22, 13.54, 6.45, 17.59" << endl;
  prices = enterArray();
  
  // Print out the array formatted to the homework specifications.
  cout << endl;
  cout << "Part (b), print out the array in the correct format: " << endl;
  printFormattedArray(prices);
  cout << endl;
  return 0;
}

// Print out the whole array object without any formatting
array<float,9> enterArray()
{
  // Initialize the array
  array<float,9> priceArray;
  
  // Enter numbers into the array
  for(int i = 0; i <= priceArray.size() - 1; i++)
    {
      cout << "Please enter float to put in the array: ";
      // Validate the input
      while(!(cin >> priceArray[i]))
	{
	  cout << "Invalid float, please try again: ";
	  cin.clear();
	  cin.ignore(10000, '\n');
	}
    }
  // Thank user for entering the numbers
  cout << endl << "Thank you, here are the numbers you entered..." << endl;
  
  // Print out the array
  for(int i = 0; i <= priceArray.size() - 1; i++)
    {
      if (i != priceArray.size() - 1)
	{
	  cout << priceArray[i] << ", ";
	}
      else
	{
	  cout << priceArray[i] << '\n';
	}
     }

  return priceArray;
}

// Print out the array with the specified formatting
void printFormattedArray(array<float,9> priceArray)
{
  // Print out the array according the format in the assignment.
  for(int i=0; i <= priceArray.size() - 1; i++)
    {
      cout << priceArray[i] << " ";
      // This will print out a new line every 3 items in the array.
      if (((i+1) % 3) == 0)
	{
	  cout << '\n';
	}
    }
}

