#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{
  string myString;
  cout << "Enter string";
  getline(cin, myString);
  myString.erase(remove_if(myString.begin(), myString.end(), ::isspace), myString.end());
  cout << myString;
  
  string wow = "Hello World wo wo wo";
  wow.erase(remove_if(wow.begin(), wow.end(), ::isspace), wow.end());
	
  cout << wow;

  return 0;
}
