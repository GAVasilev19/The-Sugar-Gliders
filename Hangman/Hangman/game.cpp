#include <iostream>
#include <iomanip>
#include <string>
#include "menu.h"
#include "game.h"

using namespace std;


void gameMode()	// Asks you to choose the game mode
{
	cout << setw(50) << "Choose your Game Mode" << endl;
	cout << setw(60) << "1) Enter word | 2) Use generated word" << endl;
	cout << setw(50) << "Enter your choice: ";

	int game_mode = chooseGameMode();

    if (game_mode == 1)	// If you choose to write your own word
    {
        cout << endl << "Please enter your word: ";
    }

    string word = getWord(game_mode);		// Receives the word that you're going to guess
    string hidden_word = hiddenWord(word);	// Makes the word "hidden"
    game(word, hidden_word);
}

int chooseGameMode()	// Allows the user to input their game mode of choice
{
    int game_mode;
    bool check_num = false;

    while (check_num == false)
    {
        if (cin >> game_mode)
        {
            if (game_mode > 2 || game_mode < 1) // Invalid input
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

    return game_mode;
}

string getWord(int game_mode)
{
    string word;

    if (game_mode == 1)	// If user chooses to write their own word
    {
        cin.clear();
        cin.ignore(1000, '\n');
        getline(cin, word);
    }

    if (game_mode == 2)	// The word that the user will have to guess will be randomly chosen from the 40 premade words
    {
        srand(time(NULL));

        string word_list[40] = { "computer", "programming", "algorithm", "education", "world", "algorithm", "array", "string", "integer", "flower", "confidence", "coffee", "shadow", "intelligent", "language", "number", "geography", "history", "literature", "birthday", "activity", "method", "education", "strategy", "baseball", "technology", "dolphin", "stranger", "president", "investment", "relationship", "disaster", "entertainment", "development", "discussion", "classroom", "magazine", "teacher", "product", "jazz" };			// Array with random words

        int random_num = rand() % 40;		// Selects a random index from 0 to 40
        word = word_list[random_num];		// The word at the random index gets saved into the variable
    }

    return word;
}

string hiddenWord(string word)	// This fuction makes the word hidden
{
    string hidden_word = word;

    for (size_t i = 0; i < word.size(); i++)
    {
        if (hidden_word[i] == ' ')	// if the phrase that the user will guess contains more that one word it separates them with a space
        {
            hidden_word[i] = ' ';
        }
        else
        {
            hidden_word[i] = '_';
        }
    }

    return hidden_word;
}

void game(string word, string hidden_word)	// Checks if the letter that the user entered is in the word
{
	char choice;
	int wrong_guess = 0;
	string used_letters = "";


	while (wrong_guess < 8 || hidden_word.find('_') == string::npos)
	{
		system("CLS");

		board(wrong_guess, hidden_word, used_letters);

		cout << "Enter your guess: ";
		cin >> choice;
		cin.ignore(1000, '\n');

		if (word.find(choice) != string::npos && used_letters.find(choice) == string::npos)	// The user made a correct guess
		{
			for (size_t i = 0; i < word.size(); i++)
			{
				if (word[i] == choice)
				{
					hidden_word[i] = choice;
				}
			}
		}

		else	// The user made a wrong guess
		{
			wrong_guess++;
		}

		if (used_letters.find(choice) == string::npos)	// Adds the letter to the used letters string
		{

			used_letters += choice;
			used_letters += " ";
		}

		if (hidden_word.find('_') == string::npos)		// The user guessed the word
		{
			system("CLS");
			board(wrong_guess, hidden_word, used_letters);
			win();
		}

		if (wrong_guess == 7)	// The user doesn't have more tries
		{
			system("CLS");
			board(wrong_guess, hidden_word, used_letters);
			loss(word);
		}
	}
}

void board(int wrong_guess, string hidden_word, string used_letters)	// Displays game board
{
	switch (wrong_guess)	// Shows the hangman depending on the wrong guesses
	{
		case 0:	// 0 wrong guesses
		{
			cout << "                    _________________________________________________" << endl;
			cout << "                    |                    HANGMAN                    |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                     WORD                      |" << endl;
			cout << setw(35);
			for (size_t i = 0; i < hidden_word.size(); i++)
			{
				cout << hidden_word[i] << " ";
			}
			cout << endl << "                    |_______________________________________________|" << endl;
			break;
		}

		case 1:	// 1 wrong guess
		{
			cout << "                    _________________________________________________" << endl;
			cout << "                    |                    HANGMAN                    |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |               / \\                             |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                     WORD                      |" << endl;
			cout << setw(35);
			for (size_t i = 0; i < hidden_word.size(); i++)
			{
				cout << hidden_word[i] << " ";
			}
			cout << endl << "                    |_______________________________________________|" << endl;

			break;
		}

		case 2:	// 2 wrong guesses
		{
			cout << "                    _________________________________________________" << endl;
			cout << "                    |                    HANGMAN                    |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                 _____________                 |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |               / \\                             |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                     WORD                      |" << endl;
			cout << setw(35);
			for (size_t i = 0; i < hidden_word.size(); i++)
			{
				cout << hidden_word[i] << " ";
			}
			cout << endl << "                    |_______________________________________________|" << endl;

			break;
		}

		case 3:	// 3 wrong guesses
		{
			cout << "                    _________________________________________________" << endl;
			cout << "                    |                    HANGMAN                    |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                 _____________                 |" << endl;
			cout << "                    |                |      |                       |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |               / \\                             |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                     WORD                      |" << endl;
			cout << setw(35);
			for (size_t i = 0; i < hidden_word.size(); i++)
			{
				cout << hidden_word[i] << " ";
			}
			cout << endl << "                    |_______________________________________________|" << endl;

			break;
		}

		case 4:	// 4 wrong guesses
		{
			cout << "                    _________________________________________________" << endl;
			cout << "                    |                    HANGMAN                    |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                 _____________                 |" << endl;
			cout << "                    |                |      |                       |" << endl;
			cout << "                    |                |      o                       |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |               / \\                             |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                     WORD                      |" << endl;
			cout << setw(35);
			for (size_t i = 0; i < hidden_word.size(); i++)
			{
				cout << hidden_word[i] << " ";
			}
			cout << endl << "                    |_______________________________________________|" << endl;

			break;
		}

		case 5:	// 5 wrong guesses
		{
			cout << "                    _________________________________________________" << endl;
			cout << "                    |                    HANGMAN                    |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                 _____________                 |" << endl;
			cout << "                    |                |      |                       |" << endl;
			cout << "                    |                |      o                       |" << endl;
			cout << "                    |                |      |                       |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |               / \\                             |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                     WORD                      |" << endl;
			cout << setw(35);
			for (size_t i = 0; i < hidden_word.size(); i++)
			{
				cout << hidden_word[i] << " ";
			}
			cout << endl << "                    |_______________________________________________|" << endl;

			break;
		}

		case 6:	// 6 wrong guesses
		{
			cout << "                    _________________________________________________" << endl;
			cout << "                    |                    HANGMAN                    |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |                 _____________                 |" << endl;
			cout << "                    |                |      |                       |" << endl;
			cout << "                    |                |      o                       |" << endl;
			cout << "                    |                |     /|\\                      |" << endl;
			cout << "                    |                |                              |" << endl;
			cout << "                    |               / \\                             |" << endl;
			cout << "                    |                                               |" << endl;
			cout << "                    |_______________________________________________|" << endl;
			cout << "                    |                     WORD                      |" << endl;
			cout << setw(35);
			for (size_t i = 0; i < hidden_word.size(); i++)
			{
				cout << hidden_word[i] << " ";
			}
			cout << endl << "                    |_______________________________________________|" << endl;

			break;
		}

		case 7:	// 7 wrong guesses
			{
				cout << "                    _________________________________________________" << endl;
				cout << "                    |                    HANGMAN                    |" << endl;
				cout << "                    |_______________________________________________|" << endl;
				cout << "                    |                                               |" << endl;
				cout << "                    |                 _____________                 |" << endl;
				cout << "                    |                |      |                       |" << endl;
				cout << "                    |                |      o                       |" << endl;
				cout << "                    |                |     /|\\                      |" << endl;
				cout << "                    |                |     / \\                      |" << endl;
				cout << "                    |               / \\                             |" << endl;
				cout << "                    |                                               |" << endl;
				cout << "                    |_______________________________________________|" << endl;
				cout << "                    |                     WORD                      |" << endl;
				cout << setw(35);
				for (size_t i = 0; i < hidden_word.size(); i++)
				{
					cout << hidden_word[i] << " ";
				}
				cout << endl << "                    |_______________________________________________|" << endl;

				break;
			}
	}

	cout << endl << "Used letters: " << used_letters << endl;
}

void win()	// Message when you win
{
	cout << endl << "Great job! You guessed the word!" << endl << endl;
	cout << "Would you like to go back to the menu? - Y/N" << endl;
	cout << "Your choice: ";
	returnToMenu();
}

void loss(string word)	// Message when you lose
{
	cout << endl << "You lose! Better luck next time!" << endl;
	cout << "The word was: " << word << endl << endl;
	cout << "Would you like to go back to the menu? - Y/N" << endl;
	cout << "Your choice: ";
	returnToMenu();
}