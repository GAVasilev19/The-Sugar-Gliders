#include <iostream>
#include <iomanip>
#include "menu.h"
#include "game.h"

using namespace std;

void printTitle()   // Displays title
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

void printMenu()    // Displays menu
{
    printTitle();

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

int inputNumber()   // Takes user to the right page depending on their input
{
    int number;
    bool check_num = false;

    while (check_num == false)
    {
        if (cin >> number)
        {
            if (number > 4 || number < 1) // Invalid input
            {
                cout << endl << "You entered an invalid statement. Please try again." << endl;
                cout << "Your choice: ";
                check_num = false;
            }

            else    // Valid input
            {
                check_num = true;
            }
        }

        else    // The user entered a character
        {
            cout << endl << "You entered an invalid statement. Please try again." << endl;
            cout << "Your choice: ";
            cin.clear();
            cin.ignore(1000, '\n');
            check_num = false;
        }
    }

    return number;
}

void choice(int number) // Checks their input
{
    system("CLS");  // Clear console

    switch (number)
    {
        case 1:
        {
            gameMode();
            break;
        }
        case 2:
        {
            printRules();
            break;
        }
        case 3:
        {
            printTeamInfo();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
    }
}

void printRules()   // Displays title
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

void printTeamInfo()    // Displays title
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

void returnToMenu() // After the game has finished
{
    char answer;
    bool flag = false;

    while (flag == false)
    {
        cin >> answer;

        if (answer == 'Y' || answer == 'y') // Go back to the menu
        {
            system("CLS");  // Clear the console
            printMenu();         // Print out game menu
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