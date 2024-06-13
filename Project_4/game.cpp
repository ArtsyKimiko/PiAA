#include "game.hpp"

Game::Game(int size, int winLength) : size(size), winLength(winLength) 
{
    board.resize(size, vector<Player>(size, NONE));
}

void Game::playGame() 
{
    int turn;
    cout << "Czy chcesz zaczynac? (1 - tak, 0 - nie): ";
    cin >> turn;
    while (turn != 0 && turn != 1) 
    {
        cout << "Nieprawidlowy znak, wprowadz jeszcze raz." << endl;
        cin >> turn;
    }
    Player currentPlayer = turn == 1 ? HUMAN : BOT;

    while (true) 
    {
        printBoard();
        if (currentPlayer == HUMAN) 
        {
            playerMove();
            if (checkWin(HUMAN)) 
            {
                printBoard();
                cout << "Gratulacje! Wygrales!" << endl;
                break;
            }
        } 
        else 
        {
            botMove();
            if (checkWin(BOT)) 
            {
                printBoard();
                cout << "Zostales pokonany." << endl;
                break;
            }
        }
        if (isDraw()) 
        {
            printBoard();
            cout << "Remis!" << endl;
            break;
        }
        currentPlayer = (currentPlayer == HUMAN) ? BOT : HUMAN;
    }
}

void Game::printBoard() 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            if (board[i][j] == HUMAN)
                cout << 'X';
            else if (board[i][j] == BOT) 
                cout << 'O';
            else 
                cout << '.';
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool Game::isDraw()
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (board[i][j] == NONE)
                return false;
    return true;
}

void Game::playerMove() 
{
    int row, col;
    while (true) 
    {
        cout << "Wpisz swoj ruch w formacie: wiersz kolumna, np: 1 2\n";
        cin >> row >> col;
        row--; 
        col--;
        if (row >= 0 && row < size && col >= 0 && col < size && board[row][col] == NONE) 
        {
            board[row][col] = HUMAN;
            break;
        } 
        else 
            cout << "Zle miejsce. Wpisz jeszcze raz.\n";
    }
}

void Game::botMove() 
{
    Move bestMove = minMax(0, BOT, NEG_INF, INF, 6); 
    board[bestMove.row][bestMove.col] = BOT;
}

Move Game::minMax(int depth, Player player, int alpha, int beta, int maxDepth) 
{
    if (checkWin(BOT)) 
        return { -1, -1, 10 - depth };
    if (checkWin(HUMAN)) 
        return { -1, -1, depth - 10 };
    if (isDraw() || depth == maxDepth) 
        return { -1, -1, 0 };
    
    vector<Move> moves; 
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (board[i][j] == NONE) 
                moves.push_back({ i, j, 0 }); 

    Move bestMove;
    if (player == BOT) 
    {
        int bestVal = NEG_INF;
        for (auto& move : moves) 
        {
            board[move.row][move.col] = BOT;
            move.score = minMax(depth + 1, HUMAN, alpha, beta, maxDepth).score;
            board[move.row][move.col] = NONE;
            if (move.score > bestVal) 
            {
                bestVal = move.score;
                bestMove = move;
            }
            alpha = max(alpha, bestVal);
            if (beta <= alpha) 
                break;
        }
    } 
    else 
    {
        int bestVal = INF;
        for (auto& move : moves) 
        {
            board[move.row][move.col] = HUMAN;
            move.score = minMax(depth + 1, BOT, alpha, beta, maxDepth).score;
            board[move.row][move.col] = NONE;
            if (move.score < bestVal) 
            {
                bestVal = move.score;
                bestMove = move;
            }
            beta = min(beta, bestVal);
            if (beta <= alpha) 
                break;
        }
    }
    return bestMove;
}

bool Game::checkWin(Player player) 
{
    for (int i = 0; i < size; ++i)
        if (checkLine(i, 0, 0, 1, player)) 
            return true;
    for (int i = 0; i < size; ++i)
        if (checkLine(0, i, 1, 0, player)) 
            return true;
    for (int i = 0; i <= size - winLength; ++i) 
    {
        if (checkLine(i, 0, 1, 1, player)) 
            return true;
        if (checkLine(0, i, 1, 1, player)) 
            return true;
        if (checkLine(i, size - 1, 1, -1, player)) 
            return true;
        if (checkLine(0, size - 1 - i, 1, -1, player)) 
            return true;
    }
    return false;
}

bool Game::checkLine(int startRow, int startCol, int stepRow, int stepCol, Player player) 
{
    int count = 0;
    for (int i = 0; i < size; ++i) 
    {
        int row = startRow + i * stepRow;
        int col = startCol + i * stepCol;
        if (row >= size || col >= size || col < 0) 
            break;
        if (board[row][col] == player) 
        {
            count++;
            if (count == winLength) 
                return true;
        } 
        else 
            count = 0;
    }
    return false;
}