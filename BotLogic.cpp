#include "ConnectFour.h"
#include <cstdlib>
#include <ctime>

bool ConnectFour :: offenseVertical(){ // builds vertically connect four
    for(int i = 5; i >= 0; i--){ //will search from bottom up
        for(int j = 6; j >= 0; j--){
            if (board[i][j] == botPlayer && 
                board[i-1][j] == EMPTY_SPACE && 
                fullColumn(j) != "full"){
                    placePiece(botPlayer, j+1); 1; // j+1 because placePiece uses 1-7 indexing
                    cout << "offenseVertical" << endl;
                    return true;
            } 
        }
    }
    return false;
}

bool ConnectFour :: offenseHorizontal() { // builds horizontally connect four
    for (int i = BOARD_ROWS - 1; i >= 0; i--) { //will search from bottom up
        for (int j = 0; j <= BOARD_COLUMNS - 4; j++) {

            // a space and three pieces
            if (board[i][j] == EMPTY_SPACE &&
                board[i][j+1] == botPlayer &&
                board[i][j+2] == botPlayer &&
                board[i][j+3] == botPlayer &&
                (i == BOARD_ROWS - 1 || board[i+1][j] != EMPTY_SPACE)) {
                    placePiece(botPlayer, j + 1); // j+1 because placePiece uses 1-7 indexing
                    cout << "offenseHorizontal 1" << endl;
                    return true;
            }

            // a piece, a space, and two pieces
            if (board[i][j] == botPlayer &&
                board[i][j+1] == EMPTY_SPACE &&
                board[i][j+2] == botPlayer &&
                board[i][j+3] == botPlayer &&
                (i == BOARD_ROWS - 1 || board[i+1][j+1] != EMPTY_SPACE)) {
                    placePiece(botPlayer, j + 2); // j+2 because placePiece uses 1-7 indexing
                    cout << "offenseHorizontal 2" << endl;
                    return true;
            }

            // two pieces, a space, and one piece
            if (board[i][j] == botPlayer &&
                board[i][j+1] == botPlayer &&
                board[i][j+2] == EMPTY_SPACE &&
                board[i][j+3] == botPlayer &&
                (i == BOARD_ROWS - 1 || board[i+1][j+2] != EMPTY_SPACE)) {
                    placePiece(botPlayer, j + 3); // j+3 because placePiece uses 1-7 indexing
                    cout << "offenseHorizontal 3" << endl;
                    return true;
            }

            // three pieces, and a space
            if (board[i][j] == botPlayer &&
                board[i][j+1] == botPlayer &&
                board[i][j+2] == botPlayer &&
                board[i][j+3] == EMPTY_SPACE &&
                (i == BOARD_ROWS - 1 || board[i+1][j+3] != EMPTY_SPACE)) {
                    placePiece(botPlayer, j + 4); // j+4 because placePiece uses 1-7 indexing
                    cout << "offenseHorizontal 4" << endl;
                    return true;
            }
            //two pieces, and two spaces
            if (board[i][j] == botPlayer &&
                board[i][j+1] == botPlayer &&
                board[i][j+2] == EMPTY_SPACE &&
                board[i][j+3] == EMPTY_SPACE &&
                (i == BOARD_ROWS - 1 || board[i+1][j+2] != EMPTY_SPACE)) {
                    placePiece(botPlayer, j + 3); // j+3 because placePiece uses 1-7 indexing
                    cout << "offenseHorizontal 5" << endl;
                    return true;
            }
            // a piece, and three spaces
            if (board[i][j] == botPlayer &&
                board[i][j+1] == EMPTY_SPACE &&
                board[i][j+2] == EMPTY_SPACE &&
                board[i][j+3] == EMPTY_SPACE &&
                (i == BOARD_ROWS - 1 || board[i+1][j+1] != EMPTY_SPACE)) {
                    placePiece(botPlayer, j + 2); // j+2 because placePiece uses 1-7 indexing
                    cout << "offenseHorizontal 6" << endl;
                    return true;
            }
            // 4 empty spaces
            if (board[i][j] == EMPTY_SPACE &&
                board[i][j+1] == EMPTY_SPACE &&
                board[i][j+2] == EMPTY_SPACE &&
                board[i][j+3] == EMPTY_SPACE &&
                (i == BOARD_ROWS - 1 || board[i+1][j] != EMPTY_SPACE)) {
                    placePiece(botPlayer, j + 1); // j+1 because placePiece uses 1-7 indexing
                    cout << "offenseHorizontal 7" << endl;
                    return true;
            }
        }
    }
    return false;
}


bool ConnectFour :: offenseDiagonal(){ // builds diagonally connect four
    // "\" diagonal
    for(int i = 5; i >= 3; i--){ // will search from bottom up
        for(int j = 0; j <= 3; j++){
            if ((board[i][j] != EMPTY_SPACE || board[i][j] == EMPTY_SPACE)
            && (board[i-1][j+1] != EMPTY_SPACE || board[i-1][j+1] == EMPTY_SPACE)
            && (board[i-2][j+2] != EMPTY_SPACE || board[i-2][j+2] == EMPTY_SPACE)
            && (board[i-3][j+3] != EMPTY_SPACE || board[i-3][j+3] == EMPTY_SPACE)){
                // checks if there is empty space
                if (board[i][j] == EMPTY_SPACE &&
                   (i == 5 || board[i+1][j] != EMPTY_SPACE)){
                    placePiece(botPlayer, j+1); // j+1 because placePiece uses 1-7 indexing
                    cout << "offenseDiagonal 1" << endl;
                    return true;
                }
                else if (board[i-1][j+1] == EMPTY_SPACE &&
                        board[i][j+1] != EMPTY_SPACE){
                    placePiece(botPlayer, j+2); // j+2 because placePiece uses 1-7 indexing
                    cout << "offenseDiagonal 2" << endl;
                    return true;
                }
                else if (board[i-2][j+2] == EMPTY_SPACE &&
                        board[i-1][j+2] != EMPTY_SPACE){
                    placePiece(botPlayer, j+3); // j+3 because placePiece uses 1-7 indexing
                    cout << "offenseDiagonal 3" << endl;
                    return true;
                }
                else if (board[i-3][j+3] == EMPTY_SPACE &&
                        board[i-2][j+3] != EMPTY_SPACE){
                    placePiece(botPlayer, j+4); // j+4 because placePiece uses 1-7 indexing
                    cout << "offenseDiagonal 4" << endl;
                    return true;
                }
            }
        }
    }
    // "/" diagonal
    for(int i = 5; i >= 3; i--){ // will search from bottom up
        for(int j = 3; j <= 6; j++){
            if ((board[i][j] != EMPTY_SPACE || board[i][j] == EMPTY_SPACE)
            && (board[i-1][j-1] != EMPTY_SPACE || board[i-1][j-1] == EMPTY_SPACE)
            && (board[i-2][j-2] != EMPTY_SPACE || board[i-2][j-2] == EMPTY_SPACE)
            && (board[i-3][j-3] != EMPTY_SPACE || board[i-3][j-3] == EMPTY_SPACE)){

                if (board[i][j] == EMPTY_SPACE &&
                   (i == 5 || board[i+1][j] != EMPTY_SPACE)){
                    placePiece(botPlayer, j+1); // j+1 because placePiece uses 1-7 indexing
                    cout << "offenseDiagonal 5" << endl;
                    return true;
                }
                else if (board[i-1][j-1] == EMPTY_SPACE &&
                        board[i][j-1] != EMPTY_SPACE){
                    placePiece(botPlayer, j); // j because placePiece uses 1-7 indexing
                    cout << "offenseDiagonal 6" << endl;
                    return true;
                }
                else if (board[i-2][j-2] == EMPTY_SPACE &&
                        board[i-1][j-2] != EMPTY_SPACE){
                    placePiece(botPlayer, j-1); // j-1 because placePiece uses 1-7 indexing
                    cout << "offenseDiagonal 7" << endl;
                    return true;
                }
                else if (board[i-3][j-3] == EMPTY_SPACE &&
                        board[i-2][j-3] != EMPTY_SPACE){
                    placePiece(botPlayer, j-2); // j-2 because placePiece uses 1-7 indexing
                    cout << "offenseDiagonal 8" << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

bool ConnectFour :: defenseVertical(){ // blocks vertically connect four  
    for (int i = 0; i <= BOARD_ROWS - 4; i++) {
        for (int j = 0; j < BOARD_COLUMNS; j++) {
            if (board[i][j] == EMPTY_SPACE && fullColumn(j) != "full" &&
            board[i+1][j] == currentPlayer &&
            board[i+2][j] == currentPlayer &&
            board[i+3][j] == currentPlayer &&
            (i == BOARD_ROWS - 4 || board[i+4][j] != EMPTY_SPACE)) {
                placePiece(botPlayer, j+1); // j+1 because placePiece uses 1-7 indexing
                cout << "defenseVertical" << endl;
                return true;
            }
        }
    }
    return false;
}

bool ConnectFour :: defenseHorizontal(){ // blocks horizontally connect four
    for (int i = BOARD_ROWS - 1; i >= 0; i--) { 
        for (int j = 0; j <= BOARD_COLUMNS - 4; j++) {
            // one space, and 3 pieces
            if (board[i][j] == EMPTY_SPACE &&
                board[i][j+1] == currentPlayer &&
                board[i][j+2] == currentPlayer &&
                board[i][j+3] == currentPlayer &&
                (i == BOARD_ROWS - 1 || board[i+1][j] != EMPTY_SPACE)) {
                    placePiece(botPlayer, j + 1); // j+1 because placePiece uses 1-7 indexing
                    cout << "defenseHorizontal 1" << endl;
                    return true;
            }

            // 3 pieces, and space
            if (board[i][j] == currentPlayer && 
                board[i][j+1] == currentPlayer &&
                board[i][j+2] == currentPlayer &&
                board[i][j+3] == EMPTY_SPACE &&
                (i == BOARD_ROWS - 1 || board[i+1][j+3] != EMPTY_SPACE)) {
                    placePiece(botPlayer, j + 4); // j+4 because placePiece uses 1-7 indexing
                    cout << "defenseHorizontal 2" << endl;
                    return true;
            }

            // one piece, one space, and two pieces
            if (board[i][j] == currentPlayer &&
                board[i][j+1] == EMPTY_SPACE &&
                board[i][j+2] == currentPlayer &&
                board[i][j+3] == currentPlayer &&
                (i == BOARD_ROWS - 1 || board[i+1][j+1] != EMPTY_SPACE)) {
                    placePiece(botPlayer, j + 2); // j+2 because placePiece uses 1-7 indexing
                    cout << "defenseHorizontal 3" << endl;
                    return true;
            }

            // two pieces, one space, and one piece
            if (board[i][j] == currentPlayer &&
                board[i][j+1] == currentPlayer &&
                board[i][j+2] == EMPTY_SPACE &&
                board[i][j+3] == currentPlayer &&
                (i == BOARD_ROWS - 1 || board[i+1][j+2] != EMPTY_SPACE)) {
                    placePiece(botPlayer, j + 3); // j+3 because placePiece uses 1-7 indexing
                    cout << "defenseHorizontal 4" << endl;
                    return true;
            }
        }
    }

    return false;
}


bool ConnectFour :: defenseDiagonal() { // blocks diagonally connect four
    // "\" diagonal
    for (int i = BOARD_ROWS - 1; i >= 3; i--) { // will search from bottom up
        for (int j = 0; j <= BOARD_COLUMNS - 4; j++) {
            // a space and three pieces
            if (board[i][j] == EMPTY_SPACE && fullColumn(j) != "full" &&
                board[i-1][j+1] == currentPlayer &&
                board[i-2][j+2] == currentPlayer &&
                board[i-3][j+3] == currentPlayer &&
                (i == BOARD_ROWS - 1 || board[i+1][j] != EMPTY_SPACE)) {
                    placePiece(botPlayer, j + 1); // j+1 because placePiece uses 1-7 indexing
                    cout << "defenseDiagonal 1" << endl;
                    return true;
            }

            // one piece, a space, and two pieces
            if (board[i][j] == currentPlayer &&
                board[i-1][j+1] == EMPTY_SPACE &&
                board[i-2][j+2] == currentPlayer &&
                board[i-3][j+3] == currentPlayer &&
                board[i][j+1] != EMPTY_SPACE) {
                    placePiece(botPlayer, j + 2); // j+2 because placePiece uses 1-7 indexing
                    cout << "defenseDiagonal 2" << endl;
                    return true;
            }

            // two pieces, a space, and one piece
            if (board[i][j] == currentPlayer &&
                board[i-1][j+1] == currentPlayer &&
                board[i-2][j+2] == EMPTY_SPACE &&
                board[i-3][j+3] == currentPlayer &&
                board[i-1][j+2] != EMPTY_SPACE) {
                    placePiece(botPlayer, j + 3); // j+3 because placePiece uses 1-7 indexing
                    cout << "defenseDiagonal 3" << endl;
                    return true;
            }

            // three pieces, and a space
            if (board[i][j] == currentPlayer &&
                board[i-1][j+1] == currentPlayer &&
                board[i-2][j+2] == currentPlayer &&
                board[i-3][j+3] == EMPTY_SPACE &&
                board[i-2][j+3] != EMPTY_SPACE) {
                    placePiece(botPlayer, j + 4); // j+4 because placePiece uses 1-7 indexing
                    cout << "defenseDiagonal 4" << endl;
                    return true;
            }
        }
    }

    // "/" diagonal
    for (int i = BOARD_ROWS - 1; i >= 3; i--) { // will search from bottom up
        for (int j = 3; j < BOARD_COLUMNS; j++) {

            // a space and three pieces
            if (board[i][j] == EMPTY_SPACE && fullColumn(j) != "full" &&
                board[i-1][j-1] == currentPlayer &&
                board[i-2][j-2] == currentPlayer &&
                board[i-3][j-3] == currentPlayer &&
                (i == BOARD_ROWS - 1 || board[i+1][j] != EMPTY_SPACE)) {
                    placePiece(botPlayer, j + 1); // j+1 because placePiece uses 1-7 indexing
                    cout << "defenseDiagonal 5" << endl;
                    return true;
            }

            // one piece, a space, and two pieces
            if (board[i][j] == currentPlayer &&
                board[i-1][j-1] == EMPTY_SPACE &&
                board[i-2][j-2] == currentPlayer &&
                board[i-3][j-3] == currentPlayer &&
                board[i][j-1] != EMPTY_SPACE) {
                    placePiece(botPlayer, j); // j because placePiece uses 1-7 indexing
                    cout << "defenseDiagonal 6" << endl;
                    return true;
            }

            // two pieces, a space, and one piece
            if (board[i][j] == currentPlayer &&
                board[i-1][j-1] == currentPlayer &&
                board[i-2][j-2] == EMPTY_SPACE &&
                board[i-3][j-3] == currentPlayer &&
                board[i-1][j-2] != EMPTY_SPACE) {
                    placePiece(botPlayer, j - 1); // j-1 because placePiece uses 1-7 indexing
                    cout << "defenseDiagonal 7" << endl;
                    return true;
            }

            // three pieces, and a space
            if (board[i][j] == currentPlayer &&
                board[i-1][j-1] == currentPlayer &&
                board[i-2][j-2] == currentPlayer &&
                board[i-3][j-3] == EMPTY_SPACE &&
                board[i-2][j-3] != EMPTY_SPACE) {
                    placePiece(botPlayer, j - 2); // j-2 because placePiece uses 1-7 indexing
                    cout << "defenseDiagonal 8" << endl;
                    return true;
            }
        }
    }

    return false;
}

void ConnectFour :: botMove(int theLevel){ // Bot move based on difficulty level
    bool check = false; 

    // LEVEL 1–2: No building or blocking
    if (theLevel <= 2){
    }

    // LEVEL 3–4: Vertical blocking only
    else if (theLevel <= 4){
        check = defenseVertical();
    }

    // LEVEL 5–6: Vertical and horizontal blocking 
    else if (theLevel <= 6){
        if (check == false) check = defenseVertical();
        if (check == false) check = defenseHorizontal();
    }

    // LEVEL 7–8: Full blocking
    else if (theLevel <= 8){
        if (check == false) check = defenseVertical();
        if (check == false) check = defenseHorizontal();
        if (check == false) check = defenseDiagonal();
    }

    // LEVEL 9–10: Full blocking and vertical connect four building
    else if (theLevel <= 10){
        if (check == false) check = defenseVertical();
        if (check == false) check = defenseHorizontal();
        if (check == false) check = offenseVertical();
    }

    // LEVEL 11–12: Partial blocking and connect four building
    else if (theLevel <= 12){
        if (check == false) check = defenseVertical();
        if (check == false) check = defenseHorizontal();
        if (check == false) check = offenseHorizontal();
        if (check == false) check = offenseVertical();
    }

    //LEVEL 13–14: Full blocking and connect four building
    else if (theLevel <= 14){
        if (check == false) check = defenseVertical();
        if (check == false) check = defenseHorizontal();
        if (check == false) check = defenseDiagonal();
        if (check == false) check = offenseDiagonal();
        if (check == false) check = offenseHorizontal();
        if (check == false) check = offenseVertical();
    }

    //LEVEL 15–20: Optimal full blocking and connect four building
    //(reordering of checks for better strategy than levels 13-14)
    else{
        if (check == false) check = defenseVertical();
        if (check == false) check = defenseHorizontal();
        if (check == false) check = defenseDiagonal();
        if (check == false) check = offenseVertical();
        if (check == false) check = offenseHorizontal();
        if (check == false) check = offenseDiagonal();
    }

    // If no move was made, place piece in random column
    if (check == false){
        int r = -1;
        do{
            r = rand() % 7 + 1; //generates random column 1-7
        } while (fullColumn(r) == "full");
        placePiece(botPlayer, r);
    }
}
