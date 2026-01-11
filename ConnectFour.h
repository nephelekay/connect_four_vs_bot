#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H
#include <iostream>

#include <string>

using namespace std;

class ConnectFour   {
    private: //Consists of variables used several times within program.
        static const int BOARD_ROWS = 6; //number of rows
        static const int BOARD_COLUMNS = 7; //number of columns
        static const char EMPTY_SPACE = '-'; //empty spot on board
        static const char RED_PIECE = 'R'; //red piece on board
        static const char YELLOW_PIECE = 'Y'; //yellow piece on board
        char board[BOARD_ROWS][BOARD_COLUMNS]; //connect-four board
        char currentPlayer = ' '; //assigned either RED_PIECE or YELLOW_PIECE
        char botPlayer = ' '; //assigned either RED_PIECE or YELLOW_PIECE
        char winner = ' '; //stores winner
        int level = 1; //difficulty level
        int lives = 3; //number of lives
        void initializeBoard(); //creates board
        void placePiece(char letter, int column); //changes board; places red or yellow piece
        //Checking for win//
        string checkVertical(char letter); 
        string checkHorizontal(char letter);
        string checkDiagonal(char letter);
        //Checking for empty spots on board//
        string fullBoard();
        string fullColumn(int column);
        //User chooses color//
        char chooseColor();
        //Bot moves//
        void botMove(int theLevel);
            //Bot building moves
        bool offenseVertical();
        bool offenseHorizontal();
        bool offenseDiagonal();
            //Bot blocking moves
        bool defenseVertical();
        bool defenseHorizontal();
        bool defenseDiagonal();
        //Resets lives and level//
        void reset() {
            lives = 3;
            level = 1;
        }


    public:
        void displayBoard(); //couts board
        void playGame(); //contains all functions
        int getLives() const { return lives; } //getter for lives
        void theReset() { reset(); } //getter for reset function

};

#endif // CONNECTFOUR_H