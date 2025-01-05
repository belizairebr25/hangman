#include <iostream>
#include <stdio.h>
using namespace std;

void draw(int stage) {
    switch (stage) {
        case 0:
            cout << " +---+\n";
            cout << " |   |\n";
            cout << "     |\n";
            cout << "     |\n";
            cout << "     |\n";
            cout << "     |\n";
            cout << "=========\n";
            break;
        case 1:
            cout << "+---+\n";
            cout << "|   |\n";
            cout << "O   |\n";
            cout << "    |\n";
            cout << "    |\n";
            cout << "    |\n";
            cout << "=========\n";
            break;
        case 2:
            cout << "+----+\n";
            cout << " |   |\n";
            cout << " O   |\n";
            cout << " |   |\n";
            cout << "     |\n";
            cout << "     |\n";
            cout << "=========\n";
            break;
        case 3:
            cout << " +---+\n";
            cout << " |   |\n";
            cout << " O   |\n";
            cout << "/|   |\n";
            cout << "     |\n";
            cout << "     |\n";
            cout << "=========\n";
            break;
        case 4:
            cout << " +---+\n";
            cout << " |   |\n";
            cout << " O   |\n";
            cout << "/|\\  |\n";
            cout << "     |\n";
            cout << "     |\n";
            cout << "=========\n";
            break;
        case 5:
            cout << " +---+\n";
            cout << " |   |\n";
            cout << " O   |\n";
            cout << "/|\\  |\n";
            cout << "/    |\n";
            cout << "     |\n";
            cout << "=========\n";
            break;
        case 6:
            cout << " +---+\n";
            cout << " |   |\n";
            cout << " O   |\n";
            cout << "/|\\  |\n";
            cout << "/ \\  |\n";
            cout << "     |\n";
            cout << "=========\n";
            break;
        case 7:
            cout << " +---+\n";
            cout << " |   |\n";
            cout << " O   |\n";
            cout << "/|\\  |\n";
            cout << "/ \\  |\n";
            cout << "     |\n";
            cout << "=========\n";
            cout << "  3:\n";
            break;
        default:
            cout << " +---+\n";
            cout << " |   |\n";
            cout << " O   |\n";
            cout << "/|\\  |\n";
            cout << "/ \\  |\n";
            cout << "     |\n";
            cout << "=========\n";
            cout << " He is asphyxiating\n";
            break;
    }
}
