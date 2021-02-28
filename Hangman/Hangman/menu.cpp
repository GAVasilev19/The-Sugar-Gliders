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
    printTitle();   // Displays title

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
    choice(inputChoice());
}

int inputChoice()   // Allows the user to input their operation of choice
{
    int user_choice;
    bool check_num = false;

    while (check_num == false)
    {
        if (cin >> user_choice)
        {
            if (user_choice > 4 || user_choice < 1) // Invalid input
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

    return user_choice;
}

void choice(int user_choice) // Takes user to the right page depending on their input
{
    system("CLS");  // Clear console

    switch (user_choice)
    {
        case 1:
        {
            gameMode();         // Takes user to game
            break;
        }
        case 2:
        {
            printRules();       // Takes user to the rules page
            break;
        }
        case 3:
        {
            printTeamInfo();    // Takes user to the team info page
            break;
        }
        case 4:
        {
            exit(0);            // Exits the program
            break;
        }
    }
}

void printRules()   // Displays rules
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

    cout << "       The rules of Hangman are simple:" << endl << endl;
    cout << "               1. Play individually or in groups." << endl;
    cout << "               2. Make guesses choosing letters of the alphabet (and in special cases numbers or signs)." << endl;
    cout << "               3. Make guesses untill you run out of turns or guess the word." << endl;
    cout << "               4. Play our game again!" << endl;
    cout << "               5. Have fun!" << endl << endl;

    cout << " Would you like to go back to the menu? - Y/N" << endl;
    cout << " Your choice: ";
    returnToMenu();
}

void printTeamInfo()    // Displays team information
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

    cout << "       Hello! Our team is TheSugarGliders!" << endl;
    cout << "       We are 9th graders from PGKPI." << endl << endl;
    cout << "       Here are our names and roles in this project:" << endl << endl;
    cout << "               Georgi Vasilev - 9A - Scrum Trainer" << endl;
    cout << "               Georgi Ivanov - 9B - QA Engineer" << endl;
    cout << "               Tereza Opanska - 9V - C++ Developer" << endl;
    cout << "               Ivailo Radev - 9G - Code Checker" << endl << endl;
    cout << "       Thank you for playing our game! We hope you like it!" << endl << endl;

    cout << " Would you like to go back to the menu? - Y/N" << endl;
    cout << " Your choice: ";
    returnToMenu();
}

void returnToMenu() // Asks the user if he wants to go back to the menu
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