
/*--------------------------------------------------------------------------------------+
|  1) Write a program that finds the greatest among three numbers     |
|                      |
|  Date : 10:Nov:2006                |
|  Angesh Vikram                 |
+--------------------------------------------------------------------------------------*/
#include <iostream>
#define SUCCESS 0
#define ERROR 1
#define TRUE 1
#define FALSE 0

using namespace std;

int main()
{
    int ione;
    int iTwo;
    int iThree;
    int iMax;
    while (TRUE) {
        cout << "\n\n=======================================================================\n\n";
        cout << "\nEnter 1st Number \n";
        cin >> ione;
        iMax = ione;
        cout << "\nEnter 2nd Number \n";
        cin >> iTwo;
        if (iTwo > iMax)
            iMax = iTwo;
        cout << "\nEnter 3rd Number \n";
        cin >> iThree;
        if (iThree > iMax)
            iMax = iThree;
        cout << "\n Your Number are : " << ione << " , " << iTwo << " , " << iThree;
        cout << "\n Greatest number is : " << iMax;
        cout << "\nEnter 0 if you want to check again \n";
        cin >> iMax;
        if (iMax == ERROR)
            break;
    }
    
    return SUCCESS;
}
