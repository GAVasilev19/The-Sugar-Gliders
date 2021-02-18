#pragma once

#include "menu.h"

using namespace std;

void gameMode();

int chooseGameMode();

string getWord(int number);

string hiddenWord(string word);

void game(string word, string hiddenWord);

void board(int wrongGuess, string hidden_wordm, string used_letters);