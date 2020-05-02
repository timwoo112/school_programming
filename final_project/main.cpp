#include <iostream>
#include "Journal.h"

using namespace std;

// Function prototypes
int menu();
  
int main()
{
  Journal user; // Initialize a journal instance
  bool exitProgram = false; // Set to false by default so program loops
  int selection; // Holds the user's selection from menu()
  do
    {
      selection = menu();
      switch(selection)
	{
	case 1:
	  user.writeGoal(); // Write a new goal
	  break;
	case 2:
	  user.searchGoals(); // Search goals
	  break;
	case 3:
	  user.readGoals(); // Read all goals
	  break;
	case 4:
	  exitProgram = true; // exit the program
	  break;
	default:
	  cout << "An error occurred :0" << endl;
	  break;
	}
    }
  while(!exitProgram);
  
  return 0;
}


// Ask the user for input from a menu, return their selection in an integer
int menu()
{
  string menuText =
"\x1B[34m"
" #     #                         \n"
" ##   ##  ######  #    #  #    # \n"
" # # # #  #       ##   #  #    # \n"
" #  #  #  #####   # #  #  #    # \n"
" #     #  #       #  # #  #    # \n"
" #     #  #       #   ##  #    # \n"
" #     #  ######  #    #   ####  \n"
"\033[0m                          \n";
  int selection;
  Clear();
  cout << menuText << endl;
  cout << "\x1B[34m1 - Write goal\033[0m" << endl;
  cout << "\x1B[34m2 - Search goals\033[0m" << endl;
  cout << "\x1B[34m3 - All goals\033[0m" << endl;
  cout << "\x1B[34m4 - Exit\033[0m" << endl;
  cout << "\x1B[35mEnter selection(1-4): \033[0m";
  while(!(cin >> selection) || (selection < 1 || selection > 4))
    {
      cout << "Invalid selection, try again: ";
      cin.clear();
      cin.ignore(10000, '\n');
    }
  return selection;
}
