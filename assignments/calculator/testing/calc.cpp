#include <iostream>
using namespace std;

int main()
{
  // Declare constants
  const int add = 1;
  const int subtract = 2;
  const int multiply = 3;
  const int divide = 4;
  // Input variables
  int function_selection;
  float input1, input2; 
  // Output variables
  float answer;
  // Other variables
  bool errors = false;
  char loop_input;
  string function_string;

  // Get user input for function selection
  cout << "-------------------------------------" << "\n\n";
  cout << "Enter a selection: " << endl;
  cout << "Add: 1" << endl;
  cout << "Subtract: 2" << endl;
  cout << "Multiply: 3" << endl;
  cout << "Divide: 4" << endl;
  cin >> function_selection; 

  // Get user input for the two numbers they want to perform a function on.
  cout << "Please enter two numbers that you want to perform the operation on:" << endl;
  cin >> input1 >> input2;
  
  // Use switch statement to perform the correct function.
  switch (function_selection)
    {
    case 1:
      answer = input1 + input2;
      function_string = "+";
      break;
    case 2:
      answer = input1 - input2;
      function_string = "-";
      break;
    case 3:
      answer = input1 * input2;
      function_string = "*";
      break;
    case 4:
      if (input2 != 0)
	{
	  answer = input1 / input2;
	  function_string = "/";
	}
      else
	{
	  cout << "Division by 0 not allowed." << endl;
	  errors = true;
	}
      break;
    default:
      cout << "It looks like you made unsupported selection." << endl;
      errors = true;
    }

  // If there were no errors, then print out the answer.
  if (!errors)
    {
      cout << input1 << " " << function_string << " " << input2 << " = " << answer << "\n\n";
    }

  cout << "Would you like to make another calculation: (y or n)";
  cin >> loop_input;
  if (loop_input == 'y')
    {
      main();
    }

  
  return 0;
}
