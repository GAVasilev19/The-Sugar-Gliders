#include <iostream>
#include <iomanip>
#include "menu.h"
#include "game.h"

using namespace std;

void title()
{
    cout << " ___    ___" << endl;
    cout << "|   |  |   |" << endl;
    cout << "|   |  |   |" << endl;
    cout << "|   |__|   |    _____ _    __ ____     ____ __     _  _______      _____ _    __ ____ " << endl;
    cout << "|    __    |   /  __ ` |  |  `    \\   /  __`  \\   | `/       \\    /  __ ` |  |  `    \\" << endl;
    cout << "|   |  |   |  |  /  \\  |  |  / \\  |  |  /  \\   |  |    \\   \\  |  |  /  \\  |  |  / \\  |" << endl;
    cout << "|   |  |   |  |  \\__/  |  |  | |  |  |  \\__/   |  |     |  |  |  |  \\__/  |  |  | |  |" << endl;
    cout << "|___|  |___|   \\_____,_|  |__| |__|   \\_____/| |  |__/__|__|__|   \\_____,_|  |__| |__|" << endl;
    cout << "                                             | |" << endl;
    cout << "                                             | |" << endl;
    cout << "                                       _     | |" << endl;
    cout << "                                      / \\____/ /" << endl;
    cout << "                                      \\_______/" << endl << endl;
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

}