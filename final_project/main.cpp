#include <iostream>
#include <vector>
#include "Journal.h"

using namespace std;

// Function prototypes
int menu();
  
int main()
{
  // Initialize the user's journal
  Journal user;
  bool exitProgram = false;
  int selection;
  do
    {
      selection = menu();
      switch(selection)
	{
	case 1:
	  user.writeGoal();
	  break;
	case 2:
	  user.searchGoals();
	  break;
	case 3:
	  user.readGoals();
	  break;
	case 4:
	  exitProgram = true;
	  break;
	default:
	  cout << "An error occurred :0" << endl;
	  break;
	}
    }
  while(!exitProgram);
  
  return 0;
}

/*
--------------------------------------
Functions section
--------------------------------------
*/

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
