#include <iostream>
#include <iomanip>
#include <string>
#include "menu.h"
#include "game.h"

using namespace std;

void gameMode()
{
	cout << setw(50) << "Chose your Game Mode" << endl;
	cout << setw(60) << "1) Enter word | 2) Use generated word" << endl;
	cout << setw(50) << "Enter your choice: ";

	int gameMode = chooseGameMode();
}

int chooseGameMode()
{
    int number;
    bool checkNum = false;

    while (checkNum == false)
    {
        if (cin >> number)
        {
            if (number > 2 || number < 1) // Invalid input
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