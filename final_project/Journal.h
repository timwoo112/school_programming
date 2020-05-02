#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <cstring>
#include <vector>

using namespace std;

const int GOAL_SIZE = 100;
const int DATE_SIZE = 25;
const int TITLE_SIZE = 50;
struct Goal
{
  char title[TITLE_SIZE];
  char date[DATE_SIZE];
  char text[GOAL_SIZE];
};
void Clear();

class Journal {
public:
  void writeGoal();
  void readGoals();
  void searchGoals();
};

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

void Journal::writeGoal()
{
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

  time_t t = time(0);
  tm* now = localtime(&t);
  timeString = to_string((now->tm_mon + 1)) + "/"  + to_string((now->tm_mday)) + "/"  + to_string((now->tm_year + 1900));
  strcpy(goalHolder.date, timeString.c_str());
  cout << goalHolder.date << endl;
  
  // Write to file
  fstream file;
  file.open("goals.dat", ios_base::app | ios::out | ios::binary);
  do{
    Clear();
    cout << writeText << endl;
    cout << "\x1B[35mEnter a goal title: \033[0m";
    cin.ignore();
    cin.getline(goalHolder.title, TITLE_SIZE);
    cout << "\x1B[35mEnter goal details: \033[0m";
    cin.ignore();
    cin.getline(goalHolder.text, GOAL_SIZE);
    file.write(reinterpret_cast<char *>(&goalHolder), sizeof(goalHolder));
    cout << "\x1B[34mEnter another goal?\033[0m" << endl;
    cout << "\x1B[35myes or no: \033[0m";
    getline(cin, again);
    cin.clear();
  }while(again == "yes");
  file.close();
}

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
  
  file.open("goals.dat", ios::in | ios::binary);
  if(file)
    {
      Clear();
      cout << writeText << endl;
      file.read(reinterpret_cast<char *>(&goalHolder), sizeof(goalHolder));
      // While not at end of file
      while(!file.eof()){
        cout << "\x1B[33mTitle: " << goalHolder.title << ".\033[0m" << endl;
	cout << "\x1B[31mDate: \033[0m" << goalHolder.date << endl;
	cout << "\x1B[31mDetails: \033[0m"  << goalHolder.text << endl;
	cout << endl;
	file.read(reinterpret_cast<char *>(&goalHolder), sizeof(goalHolder));
	counter++;
      }
    }
  cout << "<Press enter for menu>" << endl;
  cin.ignore();
  cin.ignore();
  file.close();
}

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
