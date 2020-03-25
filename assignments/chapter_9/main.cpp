#include <iostream>
#include <memory>
using namespace std;

// Declare prototypes
double calcMedian(int*, int);
int calcMode(int*, int);
double calcAverage(int*, int);

int main()
{
  // Declare variables
  int max, mode; 
  double median, average;
  
  // Ask user to enter how many people 
  cout << "Please enter how many students were surveyed: ";
  while(!(cin>>max) || max <= 0)
    {
      cout << "Please enter valid input greater than 0" << endl;
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Please enter how many students were surveyed: ";
    }
  // Declare the dynamic array
  int ptr[max]; 
  // Assign values to each location in the array
  for(int i = 0; i < max; i++)
    {
      cout << "Please enter the number of movies student " << (i+1) << " saw: ";
      while(!(cin >> ptr[i]) || ptr[i] < 0)
	{
	  cout << "Invalid input, please enter integer greater than 0: ";
	  cin.clear();
	  cin.ignore(10000, '\n');
	}
    }

  // Use the calcMedian function to find the median
  median = calcMedian(ptr, max);
  cout << "The median is: " << median << endl;
  
  // Calculate mode, if the calcMode function returns -1, then there is no mode
  mode = calcMode(ptr, max);
  if (mode == -1)
    {
      cout << "There is no mode." << endl;
    }
  else
    {
      cout << "The mode is: " << mode << endl;
    }
  
  // Calc the average
  average = calcAverage(ptr, max);
  cout << "The average is: " << average << endl;
  
  return 0;
}

double calcAverage(int *array, int num)
{
  double average; // Holds the average
  double total;   // Holds the total of the array values to calc average
  
  // Loops through the array and adds each value to the total
  for(int i = 0; i < num; i++)
    {
      total += array[i];
    }
  average = total / num;

  return average;
}

double calcMedian(int *arr, int num)
{
    double med;

    if (num % 2 == 0) // is number of elements even?
    {
        int mid1 = num / 2, mid2 = (num / 2) - 1;
        med = ((*(arr + mid1) + *(arr + mid2)) / 2.0);
    }
    else
    {
        med = *(arr + (num / 2));
    }
       
    return med;
}

int calcMode(int *array, int size)
{
    int *frequencies;
    int mode = -1;        // The mode, initialized to -1
    int highest = 0;      // The value with highest frequency
    int element = 0;    // To hold an element subscript
    int count = 0;        // Loop counter

    frequencies = new int[size];
  
    for (count = 0; count < size; count++)
        frequencies[count] = 0;

    for (int count1 = 0; count1 < size; count1++)
    {
        for (int count2 = 0; count2 < size; count2++)
        {
            if (*(array + count2) == *(array + count1))
                (*(frequencies + count1))++;
        }
    }

    highest = *frequencies;
    element = 0;
  
    for (count = 1; count < size; count++)
    {
        if (*(frequencies + count) > highest)
        {
            highest = *(frequencies + count);
            element = count;
        }
    }

    if (highest > 1)
    {
        mode = *(array + element);
    }
   
    return mode;
}
