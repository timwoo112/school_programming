#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  // Define constant for tax rate
  const float TAX_RATE = 0.065;
  // Declare other variables
  float subtotal, tax, total;

  // Get user input for their subtotal
  cout << "\n" << "Please enter your subtotal: ";
  cin >> subtotal;
  cout << endl;

  // Compute the tax
  tax = subtotal * TAX_RATE;

  // Compute the total
  total = subtotal + tax;

  // Format and print out receipt. Also adding a border to make it
  // more readable in the terminal.
  cout << "------------------------------------" << endl;
  cout << "Here is your receipt:" << endl;
  cout << "Subtotal: $" << subtotal << endl;
  cout << "Tax: $" << fixed << setprecision(2) << tax << endl << endl;
  cout << "Total amount due: $" << fixed << setprecision(2) << total << endl;
  cout << "------------------------------------" << endl;
  
  return 0;
}
