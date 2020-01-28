//Simple program that prints out my name
#include <iostream>

using namespace std;

int main()
{
    // Declaration and Initialization of the name holding variable.
    // I made it a constant since it should not change.
    const string myName = "Tim";

    // Print myName out to the console along with some formatting.
    cout << "Hello, "<< myName  << "!" << endl;

    return 0;
}
