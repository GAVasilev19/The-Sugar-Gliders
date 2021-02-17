#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "menu.h"
#include "game.h"

using namespace std;

void gameMode()
{
	cout << setw(50) << "Chose your Game Mode" << endl;
	cout << setw(60) << "1) Enter word | 2) Use generated word" << endl;
	cout << setw(50) << "Enter your choice: ";

	int gameMode = chooseGameMode();

    if (gameMode == 1)
    {
        cout << endl << "Please enter your word: ";
    }

    string word = getWord(gameMode);

    cout << word;
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

string getWord(int number)
{
    string word;

    if (number == 1)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        getline(cin, word);
    }

    if (number == 2)
    {
        srand(time(NULL));

        string wordList[40] = { "computer", "programming", "algorithm", "education", "world", "algorithm", "array", "string", "integer", "flower", "confidence", "coffee", "shadow", "intelligent", "language", "number", "geography", "history", "literature", "birthday", "activity", "method", "education", "strategy", "baseball", "technology", "dolphin", "stranger", "president", "investment", "relationship", "disaster", "entertainment", "development", "discussion", "classroom", "magazine", "teacher", "product", "assistant" };			// Array with random words

        int randomNum = rand() % 40;	// Selects a random index from 0 to 40
        word = wordList[randomNum];		// The word at the random index gets saved into the variable
    }

    return word;
}