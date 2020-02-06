#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  // Declare constant for tax rate
  const float TAX_RATE = 0.065;
  // Declare the other variables
  float subtotal, tax, total;

  // Get user input for their subtotal
  cout << "PLease enter your subtotal: " << endl;
  cin >> subtotal;
  cout << endl;

  // Compute the tax
  tax = subtotal * TAX_RATE;
  // Compute the total
  total = subtotal + tax;

  // Format and print out the receipt
  cout << "----------------------------" << endl;
  cout << "Here is the receipt." << endl;
  cout << "Subtotal: $" << fixed << setprecision(2) << subtotal << endl;
  cout << "Tax: $" << fixed << setprecision(2) << tax << endl;
  cout << "Total: $" << fixed << total << endl;

  return 0;
}
