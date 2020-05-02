#include <iostream>

using namespace std;

// Define the weather structure
struct Weather
{
  string month;
  int totalRain;
  int highTemp;
  int lowTemp;
  int averageTemp;
};
// Defines a temperature structure so I can return both temp and month
struct Temp
{
  string monthName; // Holds the month name
  int temp; // Holds the rain amount
};

// Function Prototypes
void enterData(Weather [], int);
int calcYearRainAvg(Weather [], int);
int calcYearRainTotal(Weather [], int);
Temp calcHighestTemp(Weather [], int);
Temp calcLowestTemp(Weather [], int);
int calcYearAverageTemp(Weather [], int);
		      
int main()
{
  // Declare variables
  const int MAX = 12; // CHANGE THIS TO A SMALLER NUMBER FOR EASIER TESTING
  int yearAvgRain; // Holds average rainfall for entire year
  int yearTotalRain; // Holds total rainfall for entire year
  Temp highestTemp; // Holds highest temp of year and what month
  Temp lowestTemp; // Holds lowest temp of year and what month
  int yearAverageTemp; // Holds the year average temp
  Weather yearArray[MAX];

  // Get the user's input to fill in the array
  enterData(yearArray, MAX);

  // Calculate the year average rain
  yearAvgRain = calcYearRainAvg(yearArray, MAX);

  // Calculate the highest rain month
  highestTemp = calcHighestTemp(yearArray, MAX);

  // Calculate the lowest rain month
  lowestTemp = calcLowestTemp(yearArray, MAX);

  // Calculate the year average of the monthly averages for temperature
  yearAverageTemp = calcYearAverageTemp(yearArray, MAX);

  // Calculate year rain total
  yearTotalRain = calcYearRainTotal(yearArray, MAX);

  // Format and print out values to screen
  cout << "Results:" << endl;
  cout << "Average monthly rainfall: " << yearAvgRain << " inches"  << endl;
  cout << "Total year rainfall: " << yearTotalRain << " inches" << endl;
  cout << "Highest temperature: " << highestTemp.monthName << "-> " << highestTemp.temp << "\u2109" << endl;
  cout << "Lowest temperature: " << lowestTemp.monthName << "-> " << lowestTemp.temp << "\u2109" << endl;
  cout << "Year average of all monthly average temperatures: " << yearAverageTemp << "\u2109" << endl;
  
  return 0;
}

// Get and validate the weather data from user
void enterData(Weather myArray[], int numMonths)
{
  string months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};

  for(int i = 0; i < numMonths; i++)
    {
      // Print out month
      cout << months[i] << " Data:" << endl;
      // Set month
      myArray[i].month = months[i];
      // Get total rainfall
      cout << "Enter total rain fall for " << months[i] << "(inches): ";
      while(!(cin >> myArray[i].totalRain) || !(myArray[i].totalRain >= 0))
        {
          cout << "Invalid input, try again: ";
          cin.clear();
          cin.ignore(10000, '\n');
        }
      // Get highest temp
      cout << "Enter highest temp for " << months[i] << "(F): ";
      while(!(cin >> myArray[i].highTemp) || !(myArray[i].highTemp >= -100 && myArray[i].highTemp <= 140))
	{
	  cout << "Invalid input, try again: ";
	  cin.clear();
	  cin.ignore(10000, '\n');
	}
      // Get lowest temp
      cout << "Enter lowest temperature for " << months[i] << "(F): ";
      while(!(cin >> myArray[i].lowTemp) || !(myArray[i].lowTemp >= -100 && myArray[i].lowTemp <= 140))
	{
	  cout << "Invalid input, try again: ";
	  cin.clear(); 
	  cin.ignore(10000, '\n');
	}
      // Calculate and set average temp
      myArray[i].averageTemp = (myArray[i].highTemp + myArray[i].lowTemp) / 2;

      // Blank line for formatting
      cout << endl;
    }
}

// Returns the average rain fall for year
int calcYearRainAvg(Weather myArray[], int numMonths)
{
  int total = 0; // Holds the total rainfall
  int average; // Holds the average rainfall
  // Add up all the months rainfall
  for (int i = 0; i < numMonths; i++)
    {
      total += myArray[i].totalRain;
    }
  // Calculate average
  average = total / numMonths;

  return average;
}

// Returns the total rain fall for the year
int calcYearRainTotal(Weather myArray[], int numMonths)
{
  int total = 0; // Holds accumulated total of rain fall for year
  for (int i = 0; i < numMonths; i++)
    {
      total += myArray[i].totalRain;
    }

  return total;
}

// Returns the highest temp amount and which month in a struct
Temp calcHighestTemp(Weather myArray[], int numMonths)
{
  // Temp structure that holds the highest temp month and value
  Temp month = {"none", -100};
  // Iterate through each month in array to find the highest
  for(int i = 0; i < numMonths; i++)
    {
      if(myArray[i].highTemp > month.temp)
	{
	  month.temp = myArray[i].highTemp;
	  month.monthName = myArray[i].month;
	}
    }
    
  return month;
}

// Returns a struct of the highest temp month and value
Temp calcLowestTemp(Weather myArray[], int numMonths)
{
  // Temp structure that holds the highest temp month and value
  Temp month = {"none", 140};
  // Iterate through each month in the array to find the lowest.
  for(int i = 0; i < numMonths; i++)
    {
      if(myArray[i].lowTemp < month.temp)
	{
	  month.temp = myArray[i].lowTemp;
	  month.monthName = myArray[i].month;
	}
    }

  return month;
}

// Returns the year average of the months averages for temperature.
int calcYearAverageTemp(Weather myArray[], int numMonths)
{
  int total = 0; // Holds the total rainfall
  int average; // Holds the average
  
  // Add up all of the month averages
  for(int i = 0; i < numMonths; i++)
    {
      total += myArray[i].averageTemp;
    }
  // Divide the total by the number of months
  average = total / numMonths;
  
  return average;
}
