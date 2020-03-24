#include <iostream>
#include <array>
using namespace std;

// Function prototypes
int getHours();
double getPayRate();

int main()
{
  // Declare Constants
  const double FEDERAL = .10;
  const double STATE = .0575;
  const double CITY = .0275;
  const double FICA = 0.62;
  // Declare arrays
  array<double, 7> userID = {1,2,3,4,5,6,7};
  array<double, 7> userHours;
  array<double, 7> userPayRate;
  array<double, 7> userGrossPay;
  array<double, 7> federalTax;
  array<double, 7> stateTax;
  array<double, 7> cityTax;
  array<double, 7> ficaTax;
  array<double, 7> userNetPay;
  
  // Iterate through the users and get info/calculate pay
  for (int i=0; i < userID.size() - 1; i++)
    {
      // Greet user
      cout << "Hello user " << userID[i] << endl;
      // Get user hours
      userHours[i] = getHours();
      // Get user pay rate
      userPayRate[i] = getPayRate();
      // Calculate gross pay
      userGrossPay[i] = userHours[i] * userPayRate[i];
      // Calculate federal tax
      federalTax[i] = userGrossPay[i] * FEDERAL;
      // Calculate stateTax
      stateTax[i] = userGrossPay[i] * STATE;
      // Calculate city tax
      cityTax[i] = userGrossPay[i] * CITY;
      // Calculate FICA tax
      ficaTax[i] = userGrossPay[i] * FICA;
      // Calculate net pay
      userNetPay[i] = (userGrossPay[i]) - (federalTax[i] + stateTax[i] + cityTax[i] + ficaTax[i]);
      // Put in a blank line for formatting.
      cout << endl;
    }

  // Iterate through the users again and print out/format their information.
  for (int i=0; i < userID.size() - 1; i++)
    {
      // Print user ID
      cout << "User ID: " << userID[i] << endl;
      // Print out user gross pay
      cout << "User gross pay: " << userGrossPay[i] << endl;
      // Print out all taxes the user paid
      cout << "Federal tax: " << federalTax[i] << endl;
      cout << "State tax: " << stateTax[i] << endl;
      cout << "City tax: " << cityTax[i] << endl;
      cout << "FICA tax: " << ficaTax[i] << endl;
      // Print out the user net pay
      cout << "Net pay: " << userNetPay[i] << endl;
      cout << endl;
    }
  
  return 0;
}

int getHours()
{
  int hours;
  cout << "Enter hours: ";
  while(!(cin >> hours) || hours < 0)
    {
      cout << "Invalid entry, try again." << endl;
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Enter hours: ";
    }
  return hours;
}

double getPayRate()
{
  double payRate;
  cout << "Enter pay rate: ";
  while(!(cin >> payRate) || payRate < 15.00)
    {
      cout << "Invalid entry, try again." << endl;
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Enter pay rate: ";
    }

  return payRate;
}
