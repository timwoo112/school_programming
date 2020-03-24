#include <iostream>

using namespace std;

int main()
{
  int numerator = 5;
  int denominator = 25;
  int temp = 0;
  temp = numerator;
  numerator = denominator;
  denominator = temp;
  cout << numerator << "/" << denominator << "=" << (numerator/denominator) << endl;
  
  return 0;
}
