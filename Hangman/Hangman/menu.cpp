#include <iostream>
#include <iomanip>
#include "menu.h"
#include "game.h"

using namespace std;

void title()
{
    cout << "   ___    ___" << endl;
    cout << "  |   |  |   |" << endl;
    cout << "  |   |  |   |" << endl;
    cout << "  |   |__|   |    _____ _    __ ____     ____ __     _  _______      _____ _    __ ____ " << endl;
    cout << "  |    __    |   /  __ ` |  |  `    \\   /  __`  \\   | `/       \\    /  __ ` |  |  `    \\" << endl;
    cout << "  |   |  |   |  |  /  \\  |  |  / \\  |  |  /  \\   |  |    \\   \\  |  |  /  \\  |  |  / \\  |" << endl;
    cout << "  |   |  |   |  |  \\__/  |  |  | |  |  |  \\__/   |  |     |  |  |  |  \\__/  |  |  | |  |" << endl;
    cout << "  |___|  |___|   \\_____,_|  |__| |__|   \\_____/| |  |__/__|__|__|   \\_____,_|  |__| |__|" << endl;
    cout << "                                         _     | |" << endl;
    cout << "                                        / \\____/ /" << endl;
    cout << "                                        \\_______/" << endl << endl;
}

void menu()
{
    title();

    cout << setw(60) << "+--------------------------+" << endl;
    cout << setw(60) << "|           MENU           |" << endl;
    cout << setw(60) << "|__________________________|" << endl;
    cout << setw(60) << "|                          |" << endl;
    cout << setw(60) << "|    1 )    PLAY           |" << endl;
    cout << setw(60) << "|    2 )    RULES          |" << endl;
    cout << setw(60) << "|    3 )    TEAM           |" << endl;
    cout << setw(60) << "|    4 )    EXIT           |" << endl;
    cout << setw(60) << "+--------------------------+" << endl;

    cout << setw(58) << "Please enter your choice: ";
    choice(inputNumber());
}

int inputNumber()
{
    int number;
    bool checkNum = false;

    while (checkNum == false)
    {
        if (cin >> number)
        {
            if (number > 4 || number < 1) // Invalid input
            {
                cout << endl << "You entered an invalid statement. Please try again." << endl;
                cout << "Your choice: ";
                checkNum = false;
            }

            else    // Valid input
            {
                checkNum = true;
            }
        }

        else    // The user entered a character
        {
            cout << endl << "You entered an invalid statement. Please try again." << endl;
            cout << "Your choice: ";
            cin.clear();
            cin.ignore(1000, '\n');
            checkNum = false;
        }
    }

    return number;
}

void choice(int number)
{
    system("CLS");  // Clear console

    switch (number)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            rules();
            break;
        }
        case 3:
        {
            teamInfo();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
    }
}

void rules()
{
    cout << "                  _________                  __" << endl;
    cout << "                 |    __   \\                |  |" << endl;
    cout << "                 |   |   \\  |               |  |" << endl;
    cout << "                 |   |___| /     __    __   |  |    ______     _____" << endl;
    cout << "                 |        \\     |  |  |  |  |  |   /  __  \\   /  ___/" << endl;
    cout << "                 |   | \\   \\    |  |  |  |  |  |  |   _____|  \\  \\" << endl;
    cout << "                 |   |  \\   \\   |   \\/   |  |  |  |  |____   __\\  \\" << endl;
    cout << "                 |___|   \\___\\   \\______/   |__|   \\______/  \\_____/" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

    cout << "Would you like to go back to the menu? - Y/N" << endl;
    cout << "Your choice: ";
    returnToMenu();
}

void teamInfo()
{
    cout << "                    _____________" << endl;
    cout << "                   |             |" << endl;
    cout << "                   |____     ____|" << endl;
    cout << "                        |   |    ______      _____ _    _  _______" << endl;
    cout << "                        |   |   /  __  \\    /  __ ` |  | `/       \\" << endl;
    cout << "                        |   |  |   _____|  |  /  \\  |  |     \\  \\  |" << endl;
    cout << "                        |   |  |  |____    |  \\__/  |  |     |  |  |" << endl;
    cout << "                        |___|   \\______/    \\ ____,_|  |__/__|__|__|" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

    cout << "Would you like to go back to the menu? - Y/N" << endl;
    cout << "Your choice: ";
    returnToMenu();
}

void returnToMenu()
{
    char answer;
    bool flag = false;

    while (flag == false)
    {
        cin >> answer;

        if (answer == 'Y' || answer == 'y') // Go back to the menu
        {
            system("CLS");  // Clear the console
            menu();         // Print out game menu
        }

        else if (answer == 'N' || answer == 'n')    // Exit the programme
        {
            exit(0);
        }

        else   // Invalid user input
        {
            cin.ignore(1000, '\n');
            cout << endl << "You entered an invalid statement. Please try again." << endl;
            cout << "Your choice: ";
        }
    }
}