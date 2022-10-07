#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int PassWord()
{
    int n = 3;
    int ind = 0;

    while (n--)
    {
        string user;
        string pass;

        system("cls");

        cout << "\t\t###################################     Verify YourSelf     ###################################" << endl;

        cout << "\n\nEnter Username : ";
        cin >> user;

        cout << "\n\nEnter PassWord : ";
        cin >> pass;

        if (user != "knockcat" || pass != "1234")
        {
            ++ind;
            cout << "\n\n\t\t!!! ################################   Invalid Credential   ################################ !!!\n"
                 << endl;

            continue;
        }

        if (user == "knockcat" && pass == "1234")
        {
            system("cls");
            cout << "\t\t\n\n******************************  Logged In Successfully  ******************************" << endl;
            break;
        }
    }

    if (ind == 3)
    {
        cout << "\t\t------------------------------------  Returning to Main Window ------------------------------------" << endl;
        // getch();
        return 1;
    }
    return 0;
}