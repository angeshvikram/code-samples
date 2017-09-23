
/*----------------------------------------------------------------------------------+
|  1) Write a program to check whether the given year is leap year or not  |
|                     |
|  Date : 10:Nov:2006               |
|  Angesh Vikram                |
+----------------------------------------------------------------------------------*/
#include <iostream>
#define SUCCESS 0
#define ERROR 1
#define TRUE 1
#define FALSE 0


using namespace std;

int iCheckForLeapYear(int);
int main()
{
    int iYear;
    while (TRUE) {
        cout << "\nEnter any year to check weather it’s a leap year or not\n";
        cin >> iYear;
        if (iCheckForLeapYear(iYear) == SUCCESS)
            cout << "\n The Year " << iYear << " is a Leap Year\n";
        else
            cout << "\n The Year " << iYear << " is not a Leap Year\n";
        cout << "\nEnter 0 if you want to check again \n";
        cin >> iYear;
        if (iYear == ERROR)
            break;
    }
    return SUCCESS;
}
int iCheckForLeapYear(int f_iYear)
{
    if (f_iYear < 0) {
        cout << "\nWrong value for year. It must be a positive integer.\n";
        return ERROR;
    }
    // In the Gregorian calendar there is a leap year every year divisible by four
    // except for years which are both divisible by 100 and not divisible by 400.
    if (f_iYear % 4 != 0) {
        return ERROR;
    }
    else {
        if (f_iYear % 100 != 0) {
            return SUCCESS; // Leap year
        }
        else {
            if (f_iYear % 400 != 0) {
                return ERROR;
            }
            else {
                return SUCCESS; // Leap year
            }
        }
    }
    return ERROR;
}
