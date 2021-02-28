#pragma once

#include "menu.h"

using namespace std;

void gameMode();

int chooseGameMode();

string getWord(int game_mode);

string hiddenWord(string word);

void game(string word, string hidden_word);

void board(int wrong_guess, string hidden_word, string used_letters);

void win();

void loss(string word);