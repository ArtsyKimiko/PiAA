#include "game.hpp"

int main() 
{
    int size, winLength;
    cout << "Wielkosc planszy: ";
    cin >> size;
    cout << "Ile potrzeba aby wygrac?";
    cin >> winLength;

    Game game(size, winLength);
    game.playGame();

    return 0;
}