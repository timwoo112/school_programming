#include <iostream>

using namespace std;

int main()
{
  // Declare constants
  const int FRESHMAN = 1;
  const int SOPHOMORE = 2;
  const int JUNIOR = 3;
  const int SENIOR = 4;
  const int GRADUATE = 5;
 
  // Declare other variables
  float GPA;
  int class_selection;
  int futue_class; 

  // Get the users current class rank
  cout << "What year are you? Please make a selection:" << endl;
  cout << "Freshman: 1" << endl << "Sophomore: 2" << endl << "Junior: 3" << endl << "Senior: 4" << endl;
  cin >> class_selection;

  cout << "Please enter your GPA: " << endl;
  cin >> GPA;
  cout << endl;

  if (class_selection == 1)
    {
      cout << "You will be a Sophomore next year." << endl;
      future_class = 2
    }
  if (class_selection == 2)
    {
      cout << "You will be a Junior next year." << endl;
      future_class = 3;
    }
  if (class_selection == 3)
    {
      cout << "You will be a Senior next year." << endl;
      future_class = 4;
    }
  if (class_selection == 4)
    {
      future_class = 5;
      if (GPA > 3.6)
	{
	  cout <<  "You are graduating magma cum laude!" << endl;
	}
      else if(GPA > 3.4)
	{
	  cout << "You are graduating with honors!" << endl;
	}
      else
	{
	  cout << "You are graduating this year!" << endl;
	}
    }

  
  return 0;
}
