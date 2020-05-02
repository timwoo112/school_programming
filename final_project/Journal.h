#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <cstring>
#include <vector>

using namespace std;

// Constants to create goal sizes
const int GOAL_SIZE = 100; // Bump these up if you have bigger goals
const int DATE_SIZE = 25;  // Date size
const int TITLE_SIZE = 50; // title size

// Struct to hold goal goal objects
struct Goal 
{
  char title[TITLE_SIZE];
  char date[DATE_SIZE];
  char text[GOAL_SIZE];
};

// Function Protoype
void Clear();

class Journal {
public:
  void writeGoal();
  void readGoals();
  void searchGoals();
};

// Search goals using a search term, searches through: dates, titles, text
void Journal::searchGoals()
{
  fstream file;
  string again;
  Goal goalHolder;
  char searchTerm[50];
  int counter = 1;
  string searchBar =
"\x1B[34m                                                \n"
"  ####   ######    ##    #####    ####   #    # \n"
" #       #        #  #   #    #  #    #  #    # \n"
"  ####   #####   #    #  #    #  #       ###### \n"
"      #  #       ######  #####   #       #    # \n"
" #    #  #       #    #  #   #   #    #  #    # \n"
"  ####   ######  #    #  #    #   ####   #    # \n"
"\033[0m                                                \n";

  do {
    Clear();
    cout << searchBar << endl;
    cout << "\x1B[35mEnter search term or date:\033[0m ";
    cin.ignore();
    cin.getline(searchTerm, 50);
    file.open("goals.dat", ios::in | ios::binary);
    if(file)
      {
	file.read(reinterpret_cast<char *>(&goalHolder), sizeof(goalHolder));
	// While not at end of file                                                     
	while(!file.eof()){
	  if(strstr(goalHolder.text, searchTerm) || strstr(goalHolder.date, searchTerm) || strstr(goalHolder.title, searchTerm))
	    {
	      cout << "\x1B[33mTitle: " << goalHolder.title << "\033[0m" << endl;
	      cout << "\x1B[31mDate: \033[0m" << goalHolder.date << endl;
	      cout << "\x1B[31mDetail: \033[0m"  << goalHolder.text << endl;
	      cout << endl;
	      counter++;
	    }
	  file.read(reinterpret_cast<char *>(&goalHolder), sizeof(goalHolder));
	}
      }
    cout << "\x1B[34mSearch again?\033[0m" << endl;
    cout << "\x1B[35mEnter yes or no: \033[0m";
    getline(cin, again);
    cin.clear();
    file.close();
    counter = 1;
  }while(again == "yes");
}

// Write a goal to the goals.dat file
void Journal::writeGoal()
{
  // Variables
  string again;
  Goal goalHolder;
  string timeString;
  string writeText =
"\x1B[34m \n"    
" #######                                                                    \n"
" #        #    #  #####  ######  #####        ####    ####     ##    #      \n"
" #        ##   #    #    #       #    #      #    #  #    #   #  #   #      \n"
" #####    # #  #    #    #####   #    #      #       #    #  #    #  #      \n"
" #        #  # #    #    #       #####       #  ###  #    #  ######  #      \n"
" #        #   ##    #    #       #   #       #    #  #    #  #    #  #      \n"
" #######  #    #    #    ######  #    #       ####    ####   #    #  ###### \n"
    "\033[0m"
    ;

  // Get the current date
  time_t t = time(0);
  tm* now = localtime(&t);
  timeString = to_string((now->tm_mon + 1)) + "/"  + to_string((now->tm_mday)) + "/"  + to_string((now->tm_year + 1900));
  strcpy(goalHolder.date, timeString.c_str());
  cout << goalHolder.date << endl;
  
  // Open the file
  fstream file;
  file.open("goals.dat", ios_base::app | ios::out | ios::binary);
  do{
    // Clear the screen
    Clear();
    cout << writeText << endl;
    // Get title input
    cout << "\x1B[35mEnter a goal title: \033[0m";
    cin.ignore();
    cin.getline(goalHolder.title, TITLE_SIZE);
    // Get text input
    cout << "\x1B[35mEnter goal details: \033[0m";
    cin.clear();
    cin.getline(goalHolder.text, GOAL_SIZE);
    // Persist the goal to the file
    file.write(reinterpret_cast<char *>(&goalHolder), sizeof(goalHolder));
    // Ask user if they want to write another goal
    cout << "\x1B[34mEnter another goal?\033[0m" << endl;
    cout << "\x1B[35myes or no: \033[0m";
    getline(cin, again);
    cin.clear();
  }while(again == "yes");
  // Close the file
  file.close();
}

// Prints all of your goals to the screen
void Journal::readGoals()
{
  fstream file;
  Goal goalHolder;
  int counter = 1;
  string writeText =
"\x1B[34m    "
"#                                                                \n"
"   # #    #       #            ####    ####     ##    #        ####  \n"
"  #   #   #       #           #    #  #    #   #  #   #       #      \n"
" #     #  #       #           #       #    #  #    #  #        ####  \n"
" #######  #       #           #  ###  #    #  ######  #            # \n"
" #     #  #       #           #    #  #    #  #    #  #       #    # \n"
" #     #  ######  ######       ####    ####   #    #  ######   ####  \n"
" \033[0m                                                               ";

  // Open the file
  file.open("goals.dat", ios::in | ios::binary);
  if(file)
    {
      // Clear the screen, to make it less cluttered
      Clear();
      cout << writeText << endl;
      // Read the first line and save it to goalHolder
      file.read(reinterpret_cast<char *>(&goalHolder), sizeof(goalHolder));
      // While not at end of file
      while(!file.eof()){ // While not at end of file
	// Print out the goalHolder struct to screen
        cout << "\x1B[33mTitle: " << goalHolder.title << "\033[0m" << endl;
	cout << "\x1B[31mDate: \033[0m" << goalHolder.date << endl;
	cout << "\x1B[31mDetails: \033[0m"  << goalHolder.text << endl;
	cout << endl;
	// Read next line and set it equal to goalHolder
	file.read(reinterpret_cast<char *>(&goalHolder), sizeof(goalHolder));
	counter++;
      }
    }
  cout << "<Press enter for menu>" << endl;
  cin.ignore(); // This stops the program from returning to menu
  cin.ignore(); // This waits for user to hit enter to return menu. 
  file.close(); // Close the file
}

// This function clears the terminal, works on windows, linux, and apple
void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}
