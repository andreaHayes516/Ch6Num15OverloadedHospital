/************************************************
** Author: Andrea Hayes
** Date: April 10, 2020
** Purpose: Figure hospital charges
** Input: Inpaitient and Outpatient function
** Processing: Functions for charges
** Output: Total Charges
*************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

void getInpatient(int&, double&, double&, double&); // Function headers
void getOutpatient(double&, double&);
void calcTotal(int, double, double, double);
void calcTotal(double, double);
bool inputValidation(int, double, double,double);
bool inputValidation(double, double);
int main() {
    
    int days;                                                    // Variables
    double dailyRate, medCharges, hospServices;
    char hosp;
    

    cout << "Was the patient hopitalized? (Y=Yes, N=No): ";
    cin >> hosp;

    if (hosp == 'Y' || hosp=='y')                   // For inpatient
    { 
        getInpatient(days,dailyRate,medCharges,hospServices); // Call function for inpatient
        calcTotal(days, dailyRate, medCharges, hospServices); // Call function for inpatient charges
    }
    else if (hosp == 'N'|| hosp=='n')               // For outpatient
    {
        getOutpatient(medCharges,hospServices); // Call function for outpatient
        calcTotal(medCharges, hospServices);   // Call function for outpatient charges
    }
    else                               // For incorrect input
    {
        cout << "Please enter Y or N";
    }
    
    return 0;
}
void getInpatient(int& days, double& dailyRate, double& medCharges, double& hospServices)  // Function for inpatient
{
    bool status;
    do
    {
        cout << "Number of days patient was hospitalized: ";
        cin >> days;
        cout << "Daily Rate: ";
        cin >> dailyRate;
        cout << "Hospital medication charges: ";
        cin >> medCharges;
        cout << "Hospital service charges(lab tests, etc.): ";
        cin >> hospServices;
        status = inputValidation(days, dailyRate, medCharges, hospServices); // Call function for input validation
    } while (status == false);
}
void getOutpatient(double& hospServices, double& medCharges)  // Function for outpatient
{
    bool status;
    do
    {
        cout << "Hospital medication charges: ";
        cin >> medCharges;
        cout << "Hospital service charges(lab tests, etc.): ";
        cin >> hospServices;
        status = inputValidation(medCharges, hospServices); // Call function for input validation
    } while (status == false);
}
void calcTotal(int days, double dailyRate, double medCharges, double hospServices) // Function for inpatient charges
{
    double totalCharges;
    totalCharges = (days * dailyRate) + medCharges + hospServices;
    cout << "Total Charges: $ " << totalCharges;
}
void calcTotal(double hospServices, double medCharges)  // Function for outpatient charges
{
    double totalCharges;
    totalCharges = medCharges + hospServices;
    cout << "Total Charges: $ " << totalCharges;
}
bool inputValidation(int days, double dailyRate, double medCharges, double hospServices) // Function for only positive numbers - inpatient
{
    bool status;
    if (days > 0 && dailyRate > 0 && medCharges > 0 && hospServices > 0) {
        status = true;
    }
    else {
        status = false;
        cout << "Numbers must be positive." << endl;
    }
    return status;
}
bool inputValidation(double medCharges, double hospServices) // Function for only positive numbers - outpatient
{
    bool status;
    if ( medCharges > 0 && hospServices > 0) {
        status = true;
    }
    else {
        status = false;
        cout << "Numbers must be positive." << endl;
    }
    return status;
}