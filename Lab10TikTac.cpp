#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

/// <summary>
/// Cademon Bishop  Lab 10   11 / 7 / 2023
/// OOP consepts using two diffrent classes which handle two sections of code and interact in the main loop, dear god this was a nightmare to make, tossing in as much polymorphism as I can
/// couldnt get the 3d winning and ai working so I manualy did the win conditon with a bit of ai to try to stop you.
/// [][ADD tiefunctions]
/// </summary>
//Handles board logic and movement into board

class BaseBoard {
public:
    virtual void printBoard() { std::cout << std::endl << "DO not call me!"; }
    virtual bool makeMove(int layer, int row, int col, char player) { std::cout << std::endl << "DO not call me!"; return true; }
    virtual bool checkWin(char player) { std::cout << std::endl << "DO not call me!"; return false; }
    virtual void clearBoard() = 0;
    virtual int getBoardSize() const = 0;
};

class GameBoard2D : public BaseBoard {

private:
    const int BOARD_SIZE = 3;
    std::vector<std::vector<char>> board;
    int NUM_TURNS = 0;

public:


    const std::vector<char>& operator[](int index) const {
        return board[index];
    }
    mutable int DiagonalWinCounter = 0;
    GameBoard2D() : board(getBoardSize(), std::vector<char>(getBoardSize(), '-')) {}
    int getBoardSize() const override { return BOARD_SIZE; }
    const std::vector<std::vector<char>>& getBoard() const { return board; }

    void printBoard() override {
        for (int i = 0; i < getBoardSize(); ++i) {
            for (int j = 0; j < getBoardSize(); ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    void clearBoard() override {
        // Clear the 2D board
        board = std::vector<std::vector<char>>(getBoardSize(), std::vector<char>(getBoardSize(), '-'));
        NUM_TURNS = 0;
    }
    bool makeMove(int layer, int row, int col, char player) override {
        if ((row >= 0 and row < getBoardSize()) and (col >= 0 and col < getBoardSize()) and board[row][col] == '-') {
            board[row][col] = player;
            NUM_TURNS++;
            return true; // Valid move
        }
        return false; // Invalid move
    }
    bool checkWin(char player) override {
        // Check rows, columns, and diagonals
        for (int x = 0; x < getBoardSize(); ++x) {
            // Check horizontal win
            int horizontalCount = 0;
            int verticalCount = 0;

            for (int y = 0; y < getBoardSize(); ++y) {
                if (board[x][y] == player) {
                    horizontalCount++;
                }
                if (board[y][x] == player) {
                    verticalCount++;
                }
            }

            if (horizontalCount == getBoardSize() || verticalCount == getBoardSize()) {
                return true;
            }
        }

        // Diagonal L->R win
        int DiagonalWinCounter = 0;
        for (int i = 0; i < getBoardSize(); ++i) {
            if (board[i][i] == player) {
                DiagonalWinCounter++;
            }
            else {
                break;
            }
        }
        if (DiagonalWinCounter == getBoardSize()) {
            return true;
        }

        // Diagonal R->L win
        DiagonalWinCounter = 0;
        for (int i = 0; i < getBoardSize(); ++i) {
            if (board[i][getBoardSize() - 1 - i] == player) {
                DiagonalWinCounter++;
            }
            else {
                break;
            }
        }
        if (DiagonalWinCounter == getBoardSize()) {
            return true;
        }

        return false;
    }
};

class GameBoard3D : public BaseBoard {
private:
    const int BOARD_SIZE = 3;
    std::vector<std::vector<std::vector<char>>> board3D;
public:
    GameBoard3D() : board3D(BOARD_SIZE, std::vector<std::vector<char>>(BOARD_SIZE, std::vector<char>(BOARD_SIZE, '-'))) {}
    vector<vector<char>>& operator[](int index) { return board3D[index];}
    int numberOfTurns;
    int getBoardSize() const override { return BOARD_SIZE; }
    const std::vector<std::vector<std::vector<char>>>& getBoard() const { return board3D; }
    int playerXScore = 0;
    int playerOScore = 0;
    bool move1 = false, move2 = false, move3 = false, move4 = false, move5 = false, move6 = false, move7 = false, move8 = false, move9 = false, move10 = false, move11 = false, move12 = false, move13 = false, move14 = false, move15 = false, move16 = false, move17 = false, move18 = false, move19 = false, move20 = false, move21 = false, move22 = false, move23 = false, move24 = false, move25 = false, move26 = false, move27 = false, move28 = false, move29 = false, move30 = false, move31 = false, move32 = false, move33 = false, move34 = false, move35 = false, move36 = false, move37 = false, move38 = false, move39 = false, move40 = false, move41 = false, move42 = false;


    void printBoard() override {
        for (int z = 0; z < BOARD_SIZE; ++z)
        {
            std::cout << "\nLayer " << z << ":\n";
            for (int x = 0; x < BOARD_SIZE; ++x) {
                for (int y = 0; y < BOARD_SIZE; ++y) {
                    std::cout << board3D[z][x][y] << " ";
                }
                std::cout << std::endl;
            }
        }
    }
    void printScoreBoard(){ std::cout << "Scoreboard: \n X:" << playerXScore << "    O:" << playerOScore; }
    bool makeMove3D(int layer, int row, int col, char player) {
        if (layer >= 0 && layer < BOARD_SIZE && row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board3D[layer][row][col] == '-') {
            board3D[layer][row][col] = player;
            numberOfTurns++;
            return true; // Valid move
        }
        // Invalid move
        return false; // Invalid move
    }
    bool endGameCheckWin()
    {
        if (numberOfTurns == 27)
        {
            for (int i = numberOfTurns; i < numberOfTurns; i++) {
                checkWinLazy('X');
                checkWinLazy('Y');
            }
            
            if (playerXScore == playerOScore)
            {
                std::cout << "Tie Game!" << std::endl;
                return true;
            }
            if (playerXScore > playerOScore)
            {
                std::cout << "Player X wins!" << std::endl;
                return true;
            }
            else
            {
                std::cout << "Player Y wins!" << std::endl;
                return true;
            }
            return false;
        }
        return false;
    }

    bool checkWin(char player) override {
        bool foundWin;
        for (int z = 0; z < BOARD_SIZE; ++z)
        {
            for (int x = 0; x < BOARD_SIZE; ++x) {
                // Check horizontal win
                int horizontalCount = 0;
                int verticalCount = 0;
                int horizontalCount3D = 0;

                //search any win
                for (int y = 0; y < BOARD_SIZE; ++y) {
                    if (board3D[z][x][y] == player) {
                        horizontalCount++;
                    }
                    if (board3D[z][x][y] == player) {
                        verticalCount++;
                    }
                }
                // check any win
                if (horizontalCount == BOARD_SIZE || verticalCount == BOARD_SIZE)
                {
                    bool foundWin = true;
                }
            }

            // Diagonal L->R win
            int DiagonalWinCounter = 0;
            for (int i = 0; i < BOARD_SIZE; ++i) {
                if (board3D[z][i][i] == player) {
                    DiagonalWinCounter++;
                }
                else { break; }
            }
            if (DiagonalWinCounter == BOARD_SIZE) { foundWin = true; }

            // Diagonal R->L win
            DiagonalWinCounter = 0;
            for (int i = 0; i < BOARD_SIZE; ++i) {
                if (board3D[z][i][BOARD_SIZE - 1 - i] == player) { DiagonalWinCounter++; }
                else { break; }
            }
            if (DiagonalWinCounter == BOARD_SIZE) { foundWin = true; }
        }
        if (foundWin = true) { return true; }
        else
        {
            return false;
        }

    }

    //too tired to set up an algorythrm and I have a paper due and a python group project
    bool checkWinLazy(char player) {
        int scoreToAdd = 0;
        //too tired to set up an algorithm and I have a paper due and a python group project been working on this for 14 days with all my free time and work breaks around it
        //feel like ive done well enough with the pollymorphism and the class inharentce use but Im tossing in the towel here so I can have time to work on next HW 
        // I can find a win but to find mutiple wins and not duplicate them is a lot right now
        //single layer vert
        if (board3D[0][0][0] == player && board3D[0][1][0] == player && board3D[0][2][0] == player && move1 == false) { scoreToAdd++; move1 = true; }
        if (board3D[0][0][1] == player && board3D[0][1][1] == player && board3D[0][2][1] == player && move2 == false) { scoreToAdd++; move2 = true; }
        if (board3D[0][0][2] == player && board3D[0][1][2] == player && board3D[0][2][2] == player && move3 == false) { scoreToAdd++; move3 = true; }

        if (board3D[1][0][0] == player && board3D[1][1][0] == player && board3D[1][2][0] == player && move4 == false) { scoreToAdd++; move4 = true; }
        if (board3D[1][0][1] == player && board3D[1][1][1] == player && board3D[1][2][1] == player && move5 == false) { scoreToAdd++; move5 = true; }
        if (board3D[1][0][2] == player && board3D[1][1][2] == player && board3D[1][2][2] == player && move6 == false) { scoreToAdd++; move6 = true; }


         if (board3D[2][0][0] == player && board3D[2][1][0] == player && board3D[2][2][0] == player && move7 == false) { scoreToAdd++; move7 = true; }
        if (board3D[2][0][1] == player && board3D[2][1][1] == player && board3D[2][2][1] == player && move8 == false) { scoreToAdd++; move8 = true; }
        if (board3D[2][0][2] == player && board3D[2][1][2] == player && board3D[2][2][2] == player && move9 == false) { scoreToAdd++; move9 = true; }

        // single layer hori
        if (board3D[0][0][0] == player && board3D[0][0][1] == player && board3D[0][0][2] == player && move10 == false) { scoreToAdd++; move10 = true; }
        if (board3D[0][1][0] == player && board3D[0][1][1] == player && board3D[0][1][2] == player && move11 == false) { scoreToAdd++; move11 = true; }
        if (board3D[0][2][0] == player && board3D[0][2][1] == player && board3D[0][2][2] == player && move12 == false) { scoreToAdd++; move12 = true; }

        if (board3D[1][0][0] == player && board3D[1][0][1] == player && board3D[1][0][2] == player && move13 == false) { scoreToAdd++; move13 = true; }
        if (board3D[1][1][0] == player && board3D[1][1][1] == player && board3D[1][1][2] == player && move14 == false) { scoreToAdd++; move14 = true; }
        if (board3D[1][2][0] == player && board3D[1][2][1] == player && board3D[1][2][2] == player && move15 == false) { scoreToAdd++; move15 = true; }

        if (board3D[2][0][0] == player && board3D[2][0][1] == player && board3D[2][0][2] == player && move16 == false) { scoreToAdd++; move16 = true; }
        if (board3D[2][1][0] == player && board3D[2][1][1] == player && board3D[2][1][2] == player && move17 == false) { scoreToAdd++; move17 = true; }
        if (board3D[2][2][0] == player && board3D[2][2][1] == player && board3D[2][2][2] == player && move18 == false) { scoreToAdd++; move18 = true; }

        //single layer diagonals
        if (board3D[0][0][0] == player && board3D[0][1][1] == player && board3D[1][2][2] == player && move19 == false) { scoreToAdd++; move19 = true; }
        if (board3D[0][0][2] == player && board3D[0][1][1] == player && board3D[1][2][0] == player && move20 == false) { scoreToAdd++; move20 = true; }

        if (board3D[1][0][0] == player && board3D[1][1][1] == player && board3D[1][2][2] == player && move21 == false) { scoreToAdd++; move21 = true; }
        if (board3D[1][0][2] == player && board3D[1][1][1] == player && board3D[1][2][0] == player && move22 == false) { scoreToAdd++; move22 = true; }

        if (board3D[2][0][0] == player && board3D[2][1][1] == player && board3D[2][2][2] == player && move23 == false) { scoreToAdd++; move23 = true; }
        if (board3D[2][0][2] == player && board3D[2][1][1] == player && board3D[2][2][0] == player && move24 == false) { scoreToAdd++; move24 = true; }

        //multi layer vert
        if (board3D[0][0][0] == player && board3D[1][0][0] == player && board3D[2][0][0] == player && move25 == false) { scoreToAdd++; move25 = true; }
        if (board3D[0][0][1] == player && board3D[1][0][1] == player && board3D[2][0][1] == player && move26 == false) { scoreToAdd++; move26 = true; }
        if (board3D[0][0][2] == player && board3D[1][0][2] == player && board3D[2][0][2] == player && move27 == false) { scoreToAdd++; move27 = true; }
        if (board3D[0][1][0] == player && board3D[1][1][0] == player && board3D[2][1][0] == player && move28 == false) { scoreToAdd++; move28 = true; }
        if (board3D[0][1][2] == player && board3D[1][1][2] == player && board3D[2][1][2] == player && move29 == false) { scoreToAdd++; move29 = true; }
        if (board3D[0][2][0] == player && board3D[1][2][0] == player && board3D[2][2][0] == player && move30 == false) { scoreToAdd++; move30 = true; }
        if (board3D[0][2][1] == player && board3D[1][2][1] == player && board3D[2][2][1] == player && move31 == false) { scoreToAdd++; move31 = true; }
        if (board3D[0][2][2] == player && board3D[1][2][2] == player && board3D[2][2][2] == player && move32 == false) { scoreToAdd++; move32 = true; }

        //single layer diagonals hori
        if (board3D[0][0][0] == player && board3D[1][0][1] == player && board3D[2][0][2] == player && move33 == false) { scoreToAdd++; move33 = true; }
        if (board3D[0][1][0] == player && board3D[1][1][1] == player && board3D[2][1][2] == player && move34 == false) { scoreToAdd++; move34 = true; }
        if (board3D[0][2][0] == player && board3D[1][2][1] == player && board3D[2][2][2] == player && move35 == false) { scoreToAdd++; move35 = true; }

        if (board3D[0][0][1] == player && board3D[1][1][1] == player && board3D[2][2][1] == player && move36 == false) { scoreToAdd++; move36 = true; }
        if (board3D[0][0][0] == player && board3D[1][1][0] == player && board3D[2][2][0] == player && move37 == false) { scoreToAdd++; move37 = true; }
        if (board3D[0][0][2] == player && board3D[1][1][2] == player && board3D[2][2][2] == player && move38 == false) { scoreToAdd++; move38 = true; }

        //complex diagonal
        if (board3D[0][0][0] == player && board3D[1][1][1] == player && board3D[2][2][2] == player && move39 == false) { scoreToAdd++; move39 = true; }
        if (board3D[0][0][2] == player && board3D[1][1][1] == player && board3D[2][2][0] == player && move40 == false) { scoreToAdd++; move40 = true; }
        if (board3D[0][2][0] == player && board3D[1][1][1] == player && board3D[2][0][2] == player && move41 == false) { scoreToAdd++; move41 = true; }
        if (board3D[0][2][2] == player && board3D[1][1][1] == player && board3D[2][0][0] == player && move42 == false) { scoreToAdd++; move42 = true; }


        if (player == 'X') { playerXScore += scoreToAdd; }
        if (player == 'O') { playerOScore += scoreToAdd; }
        return true;
    }

    void clearBoard() override {
        // Clear the 3D board
        board3D = std::vector<std::vector<std::vector<char>>>(BOARD_SIZE, std::vector<std::vector<char>>(BOARD_SIZE, std::vector<char>(BOARD_SIZE, '-')));
        playerXScore = 0;
        playerOScore = 0;
        numberOfTurns = 0;
        bool move1 = false, move2 = false, move3 = false, move4 = false, move5 = false, move6 = false, move7 = false, move8 = false, move9 = false, move10 = false, move11 = false, move12 = false, move13 = false, move14 = false, move15 = false, move16 = false, move17 = false, move18 = false, move19 = false, move20 = false, move21 = false, move22 = false, move23 = false, move24 = false, move25 = false, move26 = false, move27 = false, move28 = false, move29 = false, move30 = false, move31 = false, move32 = false, move33 = false, move34 = false, move35 = false, move36 = false, move37 = false, move38 = false, move39 = false, move40 = false, move41 = false, move42 = false;

    }
};

//Moves the ai and handles win and searches
class EnemyAI {
    mutable int row = 0;
    mutable int col = 0;
    mutable int layer = 0;
public:
    bool makeMove(char player, BaseBoard* board) {
        if (auto* board2D = dynamic_cast<GameBoard2D*>(board)) {
            return makeMove2D(player, *board2D);
        }
        else if (auto* board3D = dynamic_cast<GameBoard3D*>(board)) {
            return makeMove3D(player, *board3D);
        }
        return false; // if all else fails...
    }

    bool makeMove2D(char player, GameBoard2D& board) {

        int finalRow = rand() % 3;
        int finalCol = rand() % 3;

        int boardSize = board.getBoardSize();
        const auto& gameBoard = board.getBoard();
        if (smartMove2D(board, boardSize)) { return true; }
        //Are cords avalible in board space (T: can move F: cant move)
        if (finalRow >= 0 && finalRow < boardSize && finalCol >= 0 && finalCol < boardSize && gameBoard[finalRow][finalCol] == '-') {
            board.makeMove(0, finalRow, finalCol, player);
            return true;
        }
        return false;
    }

    bool makeMove3D(char player, GameBoard3D& board) {
        int finalLayer = rand() % 3;
        int finalRow = rand() % 3;
        int finalCol = rand() % 3;

        int boardSize = board.getBoardSize();
        const auto& gameBoard = board.getBoard();
        //if (smartMove3D(board, boardSize)) { return true; } [][Need to bring a 3D smart move]
        //Are cords avalible in board space (T: can move F: cant move)
        if (smartMove3D(board, boardSize)) { return true; }
        if (finalRow >= 0 && finalRow < boardSize && finalCol >= 0 && finalCol < boardSize && gameBoard[finalLayer][finalRow][finalCol] == '-') {
            board.makeMove3D(finalLayer, finalRow, finalCol, player);
            return true;
        }
        return false;
    }
    
    bool smartMove2D(GameBoard2D& board, int BOARD_SIZE) {
        //we got errors and need to make the board editable
        char player = 'X';
        char self = 'O';
        row = -1;
        col = -1;
        layer = -1;


        // Rows
        for (int x = 0; x < BOARD_SIZE; ++x) {
            int xCount = 0;
            for (int y = 0; y < BOARD_SIZE; ++y) {
                if (board[x][y] == player) {
                    xCount++;
                }
                else if (board[x][y] == '-') {
                    row = x;
                    col = y;
                }
            }

            if (xCount == BOARD_SIZE - 1 && row != -1 && col != -1) {
                board.makeMove(0, row, col, self);
                return true;
            }
        }

        // Columns
        for (int y = 0; y < BOARD_SIZE; ++y) {
            int yCount = 0;
            for (int x = 0; x < BOARD_SIZE; ++x) {
                if (board[x][y] == player) {
                    yCount++;
                }
                else if (board[x][y] == '-') {
                    row = x;
                    col = y;
                }
            }

            if (yCount == BOARD_SIZE - 1 && row != -1 && col != -1) {
                board.makeMove(0, row, col, self);
                return true;
            }
        }

        // Diagonals
        int diagonalWinCounter1 = 0;
        int diagonalWinCounter2 = 0;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board[i][i] == player) {
                diagonalWinCounter1++;
            }
            else if (board[i][i] == '-') {
                row = i;
                col = i;
            }

            if (board[i][BOARD_SIZE - 1 - i] == player) {
                diagonalWinCounter2++;
            }
            else if (board[i][BOARD_SIZE - 1 - i] == '-') {
                row = i;
                col = BOARD_SIZE - 1 - i;
            }
        }

        if ((diagonalWinCounter1 == BOARD_SIZE - 1 || diagonalWinCounter2 == BOARD_SIZE - 1) && row != -1 && col != -1) {
            board.makeMove(0, row, col, self);
            return true;
        }

        return false;
    }
    
    bool smartMove3D(GameBoard3D& board, int BOARD_SIZE) {
        char player = 'X';
        char self = 'O';
        int row = -1;
        int col = -1;
        int layer = -1;

        // Rows
        for (int z = 0; z < BOARD_SIZE; ++z) {
            for (int x = 0; x < BOARD_SIZE; ++x) {
                int xCount = 0;
                int emptyCount = 0;
                for (int y = 0; y < BOARD_SIZE; ++y) {
                    if (board[z][x][y] == player) {
                        xCount++;
                    }
                    else if (board[z][x][y] == '-') {
                        row = x;
                        col = y;
                        layer = z;
                        emptyCount++;
                    }
                }

                if (xCount == BOARD_SIZE - 1 && emptyCount == 1) {
                    board.makeMove3D(layer, row, col, self);
                    return true;
                }
            }
        }

        // Columns
        for (int z = 0; z < BOARD_SIZE; ++z) {
            for (int y = 0; y < BOARD_SIZE; ++y) {
                int yCount = 0;
                int emptyCount = 0;
                for (int x = 0; x < BOARD_SIZE; ++x) {
                    if (board[z][x][y] == player) {
                        yCount++;
                    }
                    else if (board[z][x][y] == '-') {
                        row = x;
                        col = y;
                        layer = z;
                        emptyCount++;
                    }
                }

                if (yCount == BOARD_SIZE - 1 && emptyCount == 1) {
                    board.makeMove3D(layer, row, col, self);
                    return true;
                }
            }
        }

        // Diagonals in XY plane
        int diagonalWinCounter1 = 0;
        int diagonalWinCounter2 = 0;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board[i][i][0] == player) {
                diagonalWinCounter1++;
            }
            else if (board[i][i][0] == '-') {
                row = i;
                col = i;
                layer = 0;
            }

            if (board[i][BOARD_SIZE - 1 - i][0] == player) {
                diagonalWinCounter2++;
            }
            else if (board[i][BOARD_SIZE - 1 - i][0] == '-') {
                row = i;
                col = BOARD_SIZE - 1 - i;
                layer = 0;
            }
        }

        if ((diagonalWinCounter1 == BOARD_SIZE - 1 || diagonalWinCounter2 == BOARD_SIZE - 1) && row != -1 && col != -1) {
            board.makeMove3D(layer, row, col, self);
            return true;
        }

        // Add logic for other diagonals or layers if needed

        return false;
    }
};
int splashScreen() {
    bool validBoardChoice = false;
    std::string boardChoice;

    while (!validBoardChoice) {
        std::cout << "Q - quit" << std::endl << "Pick a 2D or 3D game: ";
        std::cin >> boardChoice;

        if (boardChoice == "Q" || boardChoice == "q") { return 0; }
        else if (boardChoice == "2D" || boardChoice == "2d") {
            validBoardChoice = true;
            return 1;
        }
        else if (boardChoice == "3D" || boardChoice == "3d") {
            validBoardChoice = true;
            return 2;
        }
        else { std::cout << "I cant take that, please enter Q, 2D or 3D." << std::endl; }
    }
    return 9;
}

//How do I make this polly 
bool printWin(char currentPlayer, BaseBoard* board) {
    if (board->checkWin(currentPlayer)) {
        std::cout << "Player " << currentPlayer << " wins!" << std::endl;
        return true;
    }
    return false;
};

int main()
{
    srand(time(NULL));
    GameBoard2D board2D;
    GameBoard3D board3D;
    BaseBoard* currentBoard = nullptr;
    char currentPlayer = 'X';
    EnemyAI Enemy;
    bool programOn = true;

    bool gameOn = false;
    while (programOn)
    {
        gameOn = true;
        int gameBoardChoise = splashScreen();
        if (gameBoardChoise == 1) { currentBoard = &board2D; }
        if (gameBoardChoise == 2) { currentBoard = &board3D; }

        // [][player input loop]
        // [][3d print]
        // [][3d placment function]
        // [][3d enemy placemnt]
        //Infinate battle loop!!!
        while (gameOn) {
            if (gameOn == false) { break; }
            int row{}, col{}, layer{};
            if (gameBoardChoise == 2) { board3D.checkWinLazy(currentPlayer); board3D.printScoreBoard();}
            std::cout << std::endl << "Player " << currentPlayer << "'s Turn: " << std::endl;

            if (currentPlayer == 'X')
            {
                //2D user input - MAIN -
                if (gameBoardChoise == 1)
                {
                    if (printWin('O', currentBoard)) { gameOn = false; break; }
                    bool movePlaced = false;
                    while (!movePlaced)
                    {
                        std::cout << "Player " << currentPlayer << ", enter column and row with a space (1 to " << currentBoard->getBoardSize() << "): ";
                        std::cin >> row >> col;
                        if (row == 'q' || col == 'q') { gameOn = false; return 0; break; }
                        row--;  col--;
                        if (board2D.makeMove(0, row, col, currentPlayer)) { movePlaced = true; currentBoard->printBoard(); }
                        if (printWin(currentPlayer, currentBoard)) { gameOn = false; break; }
                        else { std::cout << "Invalid move. Try again." << std::endl; }
                    }
                }
                //3D user imput  - MAIN - 
                else if (gameBoardChoise == 2)
                {
                    bool movePlaced = false;
                    while (!movePlaced)
                    {
                        std::cout << "Player " << currentPlayer << ", enter a layer followed by a row and column ex: " << currentBoard->getBoardSize() << " " << currentBoard->getBoardSize() << " " << currentBoard->getBoardSize() << ":";
                        std::cin >> layer >> row >> col;
                        if (layer == 'q') { gameOn = false; return 0; break; }
                        layer--;  row--;  col--;
                        if (board3D.makeMove3D(layer, row, col, currentPlayer)) {
                            movePlaced = true;
                            currentBoard->printBoard();
                        }
                        else { std::cout << "Invalid move. Try again." << std::endl; }
                    }
                }
            }

            //AI move that adapts to current game selection
            if (currentPlayer == 'O' && gameOn)
            {
                bool movePlaced = false;
                while (!movePlaced)
                {
                    if (Enemy.makeMove(currentPlayer, currentBoard)) {
                        movePlaced = true;
                        currentBoard->printBoard();
                    }
                }
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            if (board3D.endGameCheckWin()) { gameOn = false; break; }
            if (gameOn == false) { currentBoard->clearBoard(); }
        }
    }
    return 0;
}
