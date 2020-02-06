#include <iostream>

using namespace std;

int main()
{
  // Declare operation selection constants
  const int add = 1;
  const int subtract = 2;
  const int multiply = 3;
  const int divide = 4;
  // Declare input variables
  int operation_selection;
  float input1, input2;
  char loop_selection;
  // Declare other variables
  char operation_character;
  bool errors = false;
  float answer;

  // Get user selection for the function they want to user
  cout << "------------------------------------------------------" << endl;
  cout << "Please enter a selection: " << endl;
  cout << "Add(1), Subtract(2), Multiply(3), Divide(4): ";
  // If the user enters invalid input for operation_selction type, let them know
  // and then restart the program.
  if (!(cin >> operation_selection))
    {
      cout << "You made an invalid selection...exiting." << endl;
      exit(1);
    }

  // Get user input for the two numbers to perform the operation on.
  cout << "Please enter two numbers to perform the operation on: " << endl;
  cout << "Number 1: ";
  // If the input given is invalid for the type then let user know and restart.
  if (!(cin >> input1))
    {
      cout << "Your input is invalid...exiting." << endl;
      exit(1);
    }
  cout << "Number 2: ";
  // Again if the input is invalid, let user know and restart.
  if (!(cin >> input2))
    {
      cout << "Your input is invalid...exiting" << endl;
      exit(1);
    }
  // Use a switch statement to perform the correct operation based on user input
  switch (operation_selection)
    {
      // Addition
    case 1:
      answer = input1 + input2;
      operation_character = '+';
      break;
      // Subtraction
    case 2:
      answer = input1 - input2;
      operation_character = '-';
      break;
      // Multiplication
    case 3:
      answer = input1 * input2;
      operation_character = '*';
      break;
      // Division
    case 4:
      if (input2 != 0) // Safe input
	{
	  answer = input1 / input2;
	  operation_character = '/';
	}
      else // User trying to divide by zero
	{
	  cout << "You cannot divide by 0." << endl;
	  errors = true;
	}
      break;
    case 25:
      cout << "You made an invalid selection." << endl;
      errors = true;
      break;
      // Default case, this could run if the user enters too high of a number.
    default:
      cout << "It appears you have entered an invalid operation selection, please try again" << endl;
      cin.clear();
      cin.ignore(1);
      main();
    }
  // If the errors bool is false run this
  if (!errors)
    {
      cout << input1 << " " << operation_character << " " << input2 << " = " << answer  << endl;
      cout << "------------------------------------------------------" << endl;
    
      // Ask the user if they would like to perform another operation
      cout << "Would you like to perform another operation? (Enter y or n): ";
      cin >> loop_selection;
      if (loop_selection == 'y')
	{
	  main();
	}
      else
	{
	  cout << "Goodbye!" << endl;
	}
    }
  // If the errors bool was set to true, letting us know that something went wrong.
  else if(errors)
    {
      cout << "Would you like to try again? y or n: ";
      cin >> loop_selection;
      // If true, run program again
      if (loop_selection == 'y')
	{
	  main();
	}
      // Else exit the program.
      else
	{
	  cout << "Goodbye!" << endl;
	}
    }

  
  return 0;
}
