#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  // Declare constants
  const float TAX_RATE = 0.065;
  // Declare other variables
  float subtotal, tax, total;

  // Get user input for their subtotal
  cout << "Please enter your subtotal: ";
  cin >> subtotal;
  cout << endl;

  // Compute the tax
  tax = subtotal * TAX_RATE;
  // Compute the total
  total = subtotal + tax;

  // Format and print out the receipt
  cout << "-------------------------------";
  cout << "Here is your receipt:" << endl;
  cout << "Subtotal: $" << fixed << setprecision(2) << subtotal << endl;
  cout << "Tax: $" << fixed << setprecision(2) << tax << "\n\n";
  cout << "Total: $" << fixed << setprecision(2) << total << endl;
  cout << "-------------------------------";  

  return 0;
}
