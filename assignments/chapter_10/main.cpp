/*
Author: Tim Woolley
 */

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

// Function prototypes
int countVowels(string*);
int countConsonants(string*);
bool repeatProgram();
bool menuSelectionAndOutput(string*);

int main()
{
  // Define variables: testing variable and the pointer to use in the functions
  string userString;
  string* userStringPtr = nullptr;

  // This will run atleast once, and then run until repeatProgram returns false
  do
    {
      // Formatting
      cout << endl << "-----------------------------------------------------" << endl << endl;
      // Get the users input for their string and remove spaces to allow for sentences
      cout << "Enter string: ";
      getline(cin, userString);
      userString.erase(remove_if(userString.begin(), userString.end(), ::isspace), userString.end());
      userStringPtr = &userString;

      // If menuSelectionAndOutput returns true it will allow the user to
      // enter a different string.
      while(menuSelectionAndOutput(userStringPtr))
	{
	  cin.clear();
	  cin.ignore(10000, '\n');
	  // Get new string and remove spaces to allow for sentences
	  cout << "Enter a new string: ";
	  getline(cin, userString);
	  userString.erase(remove_if(userString.begin(), userString.end(), ::isspace), userString.end());
	}
    }
  while(repeatProgram());
  
  return 0;
}

// Counts the vowels in the string and returns that number
int countVowels(string* userString)
{
  // Declare variables
  string vowels = "aeiou";
  int numberOfVowels = 0;

  // Loop through each letter of userString and search for each case of vowels
  for (int i = 0; i < (*userString).length(); i++)
    {
      for (int h = 0; h < vowels.length(); h++)
	{
	  // Checks the lowercased character against vowel list.
	  if (tolower((*userString)[i]) == vowels[h])
	    {
	      // If there is a match, increase the vowel count.
	      numberOfVowels++;
	    }
	}
    }

  return numberOfVowels;
}

// Counts the consonants in the string and returns that number
int countConsonants(string* userString)
{
  // Define variables
  int numberOfConsonants = 0;                                                     
  string vowels = "aeiou"; // Using vowels, to check against because it is a shorter list than all the consonants
  bool matchVowel = false; //  

  // Loop through each letter of userString and search for each case of vowels     
  for (int i = 0; i < (*userString).length(); i++)
    {
      for (int h = 0; h < vowels.length(); h++)
        {
          if (tolower((*userString)[i]) == vowels[h])
            {
	      // If there is a match then it is not a consonant.
              matchVowel = true;
            }
        }
      // If there is no match then it is a consonant, so increase the consonant count. 
      if (matchVowel == false)
	{
	  numberOfConsonants++;
	}
      else
	{
	  // Sets the bool back to false so it can be tripped again in the next loop(default is false)
	  matchVowel = false;
	}
    }
  
  return numberOfConsonants;
}

bool repeatProgram()
{
  // Define variables
  bool decision = false; // This is returned true/false for if the user wants to use the program again.
  char userChoice; // This holds the user's selection so we can test it with an if statement to properly assign the decision variable.

  // Create line for formatting
  cout << endl << "-----------------------------------------------------" << endl << endl;
  
  // Ask user if they want to try again
  cout << "Try again?\nEnter y or n: ";
  while (!( cin >> userChoice) || !(userChoice == 'y' || userChoice == 'n'))
    {
      // Clearing the buffer so the user can try to enter the selection again
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "You entered an invalid selection, please try again: ";
    }

  if (userChoice == 'y')
    {
      decision = true;
    }
  else
    {
      decision = false;
      cout << endl << "Goodbye" << endl;
    }
  // Clear buffer for new input
  cin.clear();
  cin.ignore();
  
  return decision;
}

bool menuSelectionAndOutput(string* userString)
{
  // Define variables
  char userSelection;
  bool createNew = false;

  // Formatting line
  cout << endl << "-----------------------------------------------------" << endl << endl;

  // Display the menu for the user to select from
  cout << "Menu:" << endl;
  cout << "What would you like to do?" << endl;
  cout << "A. Count the number of vowels in the string" << endl;
  cout << "B. Count the number of consonants in the string" << endl;
  cout << "C. Count both the vowels and consonants" << endl;
  cout << "D. Enter another string" << endl;
  cout << "E. Exit the program" << endl;
  cout << "Please enter your selection(A,B,C,D,or E): ";

  // Keep looping until the user provides valid input
  while(!(cin >> userSelection))
    {
      userSelection = toupper(userSelection);
      cout << userSelection << endl;
      // If the selection is in between 
      if (userSelection == 'A' || userSelection == 'B' || userSelection == 'C' || userSelection == 'D' || userSelection == 'E')
	{
	  // If the user provides acceptable input, then break out, no need to get input again.
	  break;
	}
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "You entered invalid input, try again: ";
    }
  // Create a blank line for formatting
  cout << endl << "-----------------------------------------------------" << endl << endl;
  cout << "Results:" << endl;

  // Puts the userSelection to upper case, in case the user enters a lower case
  userSelection = toupper(userSelection);
  // This switch takes the userSelection and gives them the info that they asked for, printing it to the terminal.
  switch(userSelection)
    {
    case 'A':
      cout << "The number of vowels is: " << countVowels(userString) << endl;
      break;
    case 'B':
      cout << "The number of consonants is: " << countConsonants(userString) << endl;
      break;
    case 'C':
      cout << "The numer of vowels is: " << countVowels(userString) << endl;
      cout << "The number of consanants is: " << countConsonants(userString) << endl;
      break;
    case 'D':
      cout << endl << "-----------------------------------------------------" << endl;
      createNew = true; // If the user wants to enter a new string then this gets set to true.
      break;
    case 'E':
      cout << "Exiting the program..." << endl;
      exit(1);
    default:
      cout << "You made an invalid selection." << endl;
      break;
    }

  // If this returns true, then the main function will ask the user for new input before looping again
  return createNew;
}
