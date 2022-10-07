// Introductory window

#include <iostream>
#include <conio.h>
#include <ctime>
#include "Password.h" // password details
using namespace std;

void TIME()
{
    time_t timetoday;
    time(&timetoday);
    cout << "\n\n\n\n\n \t\t\t\t Calendar date and time as per todays is : " << asctime(localtime(&timetoday)) << endl;
}

void intro()
{
    system("cls");
    system("color E9");

    cout << "\t\t\t####################################################################################";
    cout << "\n\t\t\t############                                                            ############";
    cout << "\n\t\t\t############      Banking Record management System Project in C++       ############";
    cout << "\n\t\t\t############                                                            ############";
    cout << "\n\t\t\t####################################################################################";
    cout << "\n\t\t\t---------------------------------------------------------------------------\n";
    cout << "\n\t\t\t----------------------------------------------------------------------------";

    TIME();

    cout << "\n\n";
    cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t\t        =                 WELCOME                   =";
    cout << "\n\t\t\t\t        =                   TO                      =";
    cout << "\n\t\t\t\t        =                                           =";
    cout << "\n\t\t\t\t        =            BANKING    RECORD              =";
    cout << "\n\t\t\t\t        =               MANAGEMENT                  =";
    cout << "\n\t\t\t\t        =                 SYSTEM                    =";
    cout << "\n\t\t\t\t        =                                           =";
    cout << "\n\t\t\t\t        =                                           =";
    cout << "\n\t\t\t\t        =                   BY                      =";
    cout << "\n\t\t\t\t        =              VISHAL JOSHI                  =";
    cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\n\n\t\t\t Enter any key to continue.....";
    getch();
}

void End()
{
    cout << "\n\n\n\n\n\n\n";
    cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t\t        =                 THANK YOU                 =";
    cout << "\n\t\t\t\t        =                   VISIT                   =";
    cout << "\n\t\t\t\t        =                   AGAIN                   =";
    cout << "\n\t\t\t\t        =                                           =";
    cout << "\n\t\t\t\t        =            BANKING    RECORD              =";
    cout << "\n\t\t\t\t        =               MANAGEMENT                  =";
    cout << "\n\t\t\t\t        =                 SYSTEM                    =";
    cout << "\n\t\t\t\t        =                                           =";
    cout << "\n\t\t\t\t        =                                           =";
    cout << "\n\t\t\t\t        =                   BY                      =";
    cout << "\n\t\t\t\t        =              VISHAL JOSHI                 =";
    cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\n\n\t\t\t Enter any key to continue.....";
    getch();
}