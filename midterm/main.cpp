#include <iostream>
#include <array>
using namespace std;

// Declaring function prototypes
double getPayRate();
int getHours();

int main()
{
    // Constants
    const double FEDERAL = .10;
    const double STATE = .0575;
    const double CITY = .0275;
    const double FICA = .062;
    // Declaring my arrays
    array<int, 7> empID = {5658845,4520125,7895122,8777541,8451277,1302850,7580489};
    array<int, 7> hours {0, 0, 0, 0, 0, 0, 0};
    array<double, 7> payRate {0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00};
    array<double, 7> grossPay, fedTax, stateTax, cityTax, schoolTax, ficaTax, netPay;

    // Iterate over each employee to calculate their wages.
    for (int i = 0; i <= empID.size()-1; i++)
    {
        cout << "*EMPLOYEE: " << empID[i] << "*" << endl;
        // Getting employees pay rate.
        payRate[i] = getPayRate();
        // Getting employees hours.
        hours[i] = getHours();
        // Calculate gross pay
        grossPay[i] = hours[i] * payRate[i];
        // Calculate fedTax
        fedTax[i] = grossPay[i] * FEDERAL;
        // Calculate state tax
        stateTax[i] = grossPay[i] * STATE;
        // Calculate city tax
        cityTax[i] = grossPay[i] * CITY;
        // Calculate fica tax
        ficaTax[i] = grossPay[i] * FICA;
        // Calculate net pay
        netPay[i] = (grossPay[i]) - (fedTax[i] + stateTax[i] + cityTax[i] + ficaTax[i]);
        cout << endl;
    }
    // Iterate over each employee and format/print out their information
    for (int i = 0; i <= empID.size()-1; i++)
    {
        // Employee ID section
        cout << "Employee ID: " << empID[i] << endl;
        // Gross wages section
        cout << "Gross wages: $" << grossPay[i] << endl;
        // Payroll deductions section
        cout <<  "*Payroll deductions*" << endl;
        cout << "Federal tax: $" << fedTax[i] << endl;
        cout << "State tax: $" << stateTax[i] << endl;
        cout << "City Tax: $" << cityTax[i] << endl;
        cout << "FICA tax: $" << ficaTax[i] << endl;
        // Net pay section
        cout << "Net Pay: $" << netPay[i] << endl;
        cout << endl;
    }

    return 0;
}

double getPayRate()
{
    double payRateInput;
    cout << "Enter hourly pay rate: " << endl;
    while(!(cin >> payRateInput) || payRateInput < 15.00)
    {
        cout << "Invalid input, please make sure you entered a value greater than 15.00." << endl;
        cout << "Enter hourly pay rate: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return payRateInput;
}

int getHours()
{
    int hoursInput;
    cout << "Enter hours worked: ";
    while(!(cin >> hoursInput) || hoursInput < 0)
    {
        cout << "Invalid input, please make sure you did not enter a negative number." << endl;
        cout << "Enter hours worked: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return hoursInput;
}
