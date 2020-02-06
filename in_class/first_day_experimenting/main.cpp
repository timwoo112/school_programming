#include <iostream>

using namespace std;

// Declaring functions to be used in the main() function
int printInt();
int printChar();
int printString();

int main()
{
    // Calling my functions that will print different types to the screen
    printInt();
    printChar();
    printString();

    // Returning 0 if there are no issues
    return 0;
}

// Prints an Int to the terminal
int printInt()
{
    // Declaring and initializing the int
    int myInt = 5;

    // Printing the int to the terminal
    cout << "This is an Int " << myInt << endl;

    // Returning 0, meaning there are no issues
    return 0;
}

int printChar()
{
    // Declaring and initializing the Char
    char myChar = 't';

    // Printing the Char to the screen
    cout << "This is a Char " << myChar << endl;

    // Return 0 to signify there were no issues
    return 0;
}

int printString()
{
    // Declaring and initializing the String
    string myString = "Hello!";

    // Printing the string to the terminal
    cout << "This is a String " << myString << endl;

    // Return 0 to signify there were no issues
    return 0;
}
