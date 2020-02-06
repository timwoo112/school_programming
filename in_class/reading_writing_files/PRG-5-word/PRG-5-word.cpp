#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // Variables
  int numLines;
  string input;
  
  // initialize ofstream
  ofstream outputFile;
  outputFile.open("MyDocument.txt");

  // Get number of lines user wants in the file
  cout << "Please enter the number of lines you want in the document: ";
  cin >> numLines;

  cin.ignore();
  
  for (int i = 1; i <= numLines; i++)
    {
      cout << "Please enter a line: ";
      getline(cin, input);
      outputFile << input << "\n";
    }

  outputFile.close();
  return 0;
}
