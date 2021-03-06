#include <iostream>

using namespace std;

void invalidInput(int);

int main()
{
  // Declaring variables
  int input_1 = 0;
  int input_2 = 0;
  int total = 0;
  char loop_selection;

  do
    {
      // Setting total to 0, so user can use again.
      total = 0;
      // Set loop_selection to an arbitrary char other than y or n so that it loops
      loop_selection = 'w';
      // Ask user for the number they want to count to
      cout << "Counting to: ";
      while(!(cin >> input_1))
	{
	  invalidInput(1);
	}

      // Ask user for the number they want to increment by
      cout << "Increment by: ";
      while(!(cin >> input_2))
	{
	  invalidInput(2);
	}
    
      // Start the for loop to begin the output
      for (int i=1; i <= input_1; i += input_2)
	{
	  cout << i << " ";
	  total += i;
	}

      // Print out the total
      cout << endl << "The total is: " << total << endl;

      // Will keep looping until the user enters a valid 'y' or 'n'
      while(loop_selection == 'w')
	{
	  // Ask user if they would like to play again.
	  cout << "Would you like to try again? (y or n): ";

	  // Will keep looping until the user enters a valid char
	  while(!(cin >> loop_selection))
	    {
	      invalidInput(3);
	      loop_selection = 'w';
	    }
	  if(loop_selection == 'y')
	    {
	      cout << "Restarting program" << "\n\n";
	    }
	  else if(loop_selection == 'n')
	    {
	      cout << "Goodbye" << endl;
	    }
	  else
	    {
	      invalidInput(3);
	      loop_selection = 'w';
	    }
	}
    }while(loop_selection == 'y');
  
  return 0;
}

// This function lets user know they entered input and clears the cin stream.
// Also made it as a way to clean up my main function from repetitive code.
void invalidInput(int selector)
{
  switch(selector)
    {
    case 1:
      cout << "Invalid input, please try again" << endl;
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Counting to: ";
      break;
    case 2:
      cout << "Invalid input, please try again" << endl;
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Increment by: ";
      break;
    case 3:
      cout << "Invalid input, please try again" << endl;
      cin.clear();
      cin.ignore(10000, '\n');
      break;
    }
}
