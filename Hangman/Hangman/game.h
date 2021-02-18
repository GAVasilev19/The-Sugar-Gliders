#pragma once

#include "menu.h"

using namespace std;

void gameMode();

int chooseGameMode();

string getWord(int number);

string hiddenWord(string word);

void game(string word, string hidden_word);

void board(int wrong_guess, string hidden_wordm, string used_letters);

void win();

void loss(string word);