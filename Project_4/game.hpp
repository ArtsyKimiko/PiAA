#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int NEG_INF = numeric_limits<int>::min(); 

enum Player { HUMAN, COMPUTER, NONE };

struct Move 
{
    int row, col, score;
};

class Game 
{
private:
    int size;
    int winLength;
    std::vector<std::vector<Player>> board;
    void printBoard();
    bool isDraw();
    void playerMove();
    void computerMove();
    Move minMax(int depth, Player player, int alpha, int beta, int maxDepth);
    bool checkWin(Player player);
    bool checkLine(int startRow, int startCol, int stepRow, int stepCol, Player player);

public:
    Game(int size, int winLength);
    void playGame();
};
