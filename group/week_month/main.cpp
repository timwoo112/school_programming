#include <iostream>

using namespace std;

int main()
{
  // Declare variables
  float total;
  float user_input;
  string user_selection;

  // Ask user if they want to input weekly or monthly sales
  cout << "Do you want to input daily or monthly sales: weekly or monthly ";
  cin >> user_selection;
  
  // Iterate on the users selection allowing them to enter data
  if (user_selection == "weekly")
    {
      for (int i = 1; i <= 7; i++)
	{
	  switch (i)
	    {
	    case 1:
	      cout << "Enter input for Monday: ";
	      cin >> user_input;
	      cout << endl;
	      total += user_input;
	      break;
	    case 2:
	      cout << "Enter input for Tuesday: ";
	      cin >> user_input;
	      cout << endl;
	      total += user_input;
	      break;
	    case 3:
	      cout << "Enter input for Wednesday: ";
	      cin >> user_input;
	      cout << endl;
	      total += user_input;
	      break;
	    case 4:
	      cout << "Enter input for Thursday: ";
	      cin >> user_input;
	      cout << endl;
	      total += user_input;
	      break;
	    case 5:
	      cout << "Enter input for Friday: ";
	      cin >> user_input;
	      cout << endl;
	      total += user_input;
	      break;
	    case 6:
	      cout << "Enter input for Saturday: ";
	      cin  >> user_input;
	      cout << endl;
	      total += user_input;
	      break;
	    case 7:
	      cout << "Enter input for Sunday: ";
	      cin >> user_input;
	      cout << endl;
	      total += user_input;
	      break;
	    default:
	      cout << "Something went wrong" << endl;
	      break;
	    }
	}
      // Print out total for the week
      cout << "The total for the week was: $" << total << endl;
    }
  else if(user_selection == "monthly")
    {
      cout << "monthly" << endl;
    }
  else
    {
      cout << "It look like you provided invalid input, restarting program..." << endl;
      main();
    }

  return 0;
}
