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
        string wordList[40];			// Array for the random words
        ifstream randomWord;			// This is used for reading input from a file
        randomWord.open("Words.txt");	// Reads the file (the word list)

        for (int i = 0; i < 40; i++)
        {
            randomWord >> wordList[i];	// Add the words from the list into the array
        }

        int randomNum = rand() % 40;	// Selects a random index from 0 to 40
        word = wordList[randomNum];		// The word at the random index gets saved into the variable

        randomWord.close();				// Stop reading the file so we don't waste memory
    }

    return word;
}