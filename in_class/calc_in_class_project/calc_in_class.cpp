#include <iostream>

using namespace std;

int main()
{
  // Declare constants
  const int ADD = 1;
  const int SUBTRACT = 2;
  const int MULTIPLY = 3;
  const int DIVIDE = 4;
  // Declare other variables
  int operation_selection_input;
  float number1;
  float number2;
  float answer;
  
  cout << "Please make a selection for the operation you want to use." << endl;
  cout << "Add: 1" << endl << "Subtract: 2" << endl << "Multiply: 3" << endl << "Divide: 4" <<  endl;
  cin >> operation_selection_input;
  cout << "Please enter the first number: " << endl;
  cin >> number1;
  cout << "Please ener the second number: " << endl;
  cin >> number2;

  if (operation_selection_input == ADD)
    {
      answer = number1 + number2;
      cout << "The answer is " << answer << endl;
    }
  if (operation_selection_input == SUBTRACT)
    {
      answer = number1 - number2;
      cout << "The answer is " << answer << endl;
    }
  if (operation_selection_input == MULTIPLY)
    {
      answer = number1 * number2;
      cout << "The answer is " << answer << endl;
    }
  if (operation_selection_input == DIVIDE)
    {
      if (number2 != 0)
	{
	  answer = number1 / number2;
	  cout << "The answer is " << answer << endl;
	}
      if (number2 == 0)
	{
	  cout << "You cannot divide by zero, exiting program..." << endl;
	}
    }
  if (operation_selection_input < 1 || operation_selection_input > 4)
    {
      cout << "You chose an invalid selection, exiting program." << endl;
    }

  return 0;
}
