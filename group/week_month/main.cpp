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
      for(int i=0; i<=12; i++)
	{
	  switch(i)
	    {
	    case 1:
	      cout << "Enter sales for January: ";
	      cin >> user_input;
	      total += user_input;
	      break;
	    case 2:
	      cout << "Enter sales for February: ";
	      cin >> user_input;
	      total += user_input;
	      break;
	    case 3:
	      cout << "Enter sales for March: ";
	      cin >> user_input;
	      total += user_input;
	      break;
	    case 4:
	      cout << "Enter sales for April: ";
	      cin >> user_input;
	      total += user_input;
	      break;
	    case 5:
	      cout << "Enter sales for May: ";
	      cin >> user_input;
	      total += user_input;
	      break;
	    case 6:
	      cout << "Enter sales for June: ";
	      cin >> user_input;
	      total += user_input;
	      break;
	    case 7:
	      cout << "Enter sales for July: ";
	      cin >> user_input;
	      total += user_input;
	      break;
	    case 8:
	      cout << "Enter sales for August: ";
	      cin >> user_input;
	      total += user_input;
	      break;
	    case 9:
	      cout << "Enter sales for September: ";
	      cin >> user_input;
	      total += user_input;
	      break;
	    case 10:
	      cout << "Enter sales for October: ";
	      cin >> user_input;
	      total += user_input;
	      break;
	    case 11:
	      cout << "Enter sales for November: ";
	      cin >> user_input;
	      total += user_input;
	      break;
	    case 12:
	      cout << "Enter sales for December: ";
	      cin >> user_input;
	      total += user_input;
	      break;
	    }
	}
      // Print out sales for the year
      cout << "Total sales this year: $" << total << endl;
    }
  else
    {
      cout << "It look like you provided invalid input, restarting program..." << endl;
      main();
    }

  return 0;
}
