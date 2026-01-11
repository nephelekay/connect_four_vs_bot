#include "ConnectFour.h"
#include <cstdlib>
#include <ctime>

void ConnectFour :: initializeBoard(){  //creates board
    for(int i = 0; i < BOARD_ROWS; i++){ 
        for(int j = 0; j < BOARD_COLUMNS; j++){ 
            board[i][j] = EMPTY_SPACE; //fills board with - for R or Y to be placed in
        }
    }

}

void ConnectFour :: displayBoard(){ //prints board
    for(int i = 0; i < BOARD_ROWS; i++){
        for(int j = 0; j < BOARD_COLUMNS; j++){
            cout << board[i][j]; //prints each index
            cout << " ";
        }
        cout << endl;
    }
    //Final rows printed//
    cout << "=============" << endl; 
    cout << "1 2 3 4 5 6 7 " << endl;    
}

char ConnectFour :: chooseColor(){ //user chooses color
    char color_choice = ' ';
    cout << "Choose a color:" << endl;
    cout << "1. Red" << endl;
    cout << "2. Yellow" << endl;
    cout << "Enter 1 or 2: ";
    cin >> color_choice;
    while (color_choice != '1' && color_choice != '2'){ //input validation
        cout << "Invalid choice. Please enter 1 for Red or 2 for Yellow: ";
        cin >> color_choice;
    }
    if (color_choice == '1'){ //selected red
        color_choice = 'R';
    } else if (color_choice == '2'){ //selected yellow
        color_choice = 'Y';
    }
    return color_choice;
}

void ConnectFour :: placePiece(char letter, int column){ //places piece according to user's choice
    column = column - 1;
    for(int i = 5; i >= 0; i--){ //will search from bottom up
        if(board[i][column] == EMPTY_SPACE){ //searches for empty space
            board[i][column] = letter; //assigns space with letter
            break;
        }
        
    }

}
string ConnectFour :: checkVertical(char letter){ //checks vertically
    for(int i = 0; i < BOARD_ROWS - 3; i++){ //3 spaces from edge to not go out of range
        for(int j = 0; j < BOARD_COLUMNS; j++){
            if (board[i][j] == letter && 
                board[i+1][j] == letter && 
                board[i+2][j] == letter && 
                board[i+3][j] == letter){ 
                    return "end"; //if 4 in a row is found

            }
        }
    }
    return "play"; //if 4 in a row is not found
}

string ConnectFour :: checkHorizontal(char letter){ //checks horizontally
    for(int i = 0; i < BOARD_ROWS; i++){
        for(int j = 0; j < BOARD_COLUMNS - 3; j++){ //3 spaces from edge to not go out of range
            if (board[i][j] == letter && 
                board[i][j+1] == letter && 
                board[i][j+2] == letter && 
                board[i][j+3] == letter){
                    return "end"; //if 4 in a row is found
            }
        }
    }
    return "play"; //if 4 in a row is not found
}

string ConnectFour :: checkDiagonal(char letter){ //checks diagonally
    // "\" diagonal
    for(int i = 0; i <= BOARD_ROWS - 4; i++){ //4 spaces from edge to not go out of range
        for(int j = 0; j <= BOARD_COLUMNS - 4; j++){ //4 spaces from edge to not go out of range
            if (board[i][j] == letter &&
                board[i+1][j+1] == letter &&
                board[i+2][j+2] == letter &&
                board[i+3][j+3] == letter){
                    return "end"; //if 4 in a row is found 
            }
        }
    }
    // "/" diagonal
    for(int i = 3; i < BOARD_ROWS; i++){ //starts at row 3 to not go out of range
        for(int j = 0; j <= BOARD_COLUMNS - 4; j++){ //4 spaces from edge to not go out of range
            if (board[i][j] == letter &&
                board[i-1][j+1] == letter &&
                board[i-2][j+2] == letter &&
                board[i-3][j+3] == letter){
                    return "end"; //if 4 in a row is found
            }
        }
    }

    return "play"; //if 4 in a row is not found
}


string ConnectFour :: fullBoard(){ //checks if board is full
    int count = 0; //keeps count of spaces filled
    for(int i = 0; i < BOARD_ROWS; i++){ //SECOND / side
        for(int j = 0; j < BOARD_COLUMNS; j++){
            if (board[i][j] != EMPTY_SPACE){ //searches for for spaces filled
                count += 1; //increments if space is filled
            }
        }
    }
    if (count == 42){ //total filled spaces
        cout << endl << "Tie game."; 
        return "end";  //no more spaces to play 
    }
    return "play"; //there is still space
}

string ConnectFour :: fullColumn(int column){ //checks if column is full
    column -= 1; //note column indexes start at 0
    int count = 0;
    for(int i = 0; i < BOARD_ROWS; i++){ 
        if (board[i][column] != EMPTY_SPACE){ //searches for space that is not empty
            count += 1; //increments count

        }
    }
    if (count == 6){ //column is full
        
        return "full";
    }

    return "not full"; //column is not full
}

void ConnectFour :: playGame(){ //called in main()

    int userColumn = -1; //column indexes start at 0
    currentPlayer = chooseColor(); //red starts game
    string user_string = ""; //used to inform player whose turn it is
    string bot_string = ""; //used to inform player whose turn it is
    if (currentPlayer == RED_PIECE){ //user is red
        user_string = "Red's";
        bot_string = "Yellow's";
        botPlayer = YELLOW_PIECE;
    } 
    else if (currentPlayer == YELLOW_PIECE){ //user is yellow
        user_string = "Yellow's";
        bot_string = "Red's";
        botPlayer = RED_PIECE;
    }

    string end_game = "play"; //used to end game

    initializeBoard(); //creates board
    displayBoard(); //prints board

    while (end_game == "play"){
        cout << endl << "Level: " << level << "    " << "Lives: " << lives << endl;
        cout << endl << "It is " << user_string << " turn." << endl;
        cout << "In which column would you like to move (-1 to exit)? ";
        cin >> userColumn; //user chooses column
        cout << endl;
        if (userColumn == -1){ //breaks out of loop
            theReset();
            break;
        }
        //untill input is valid
        //will loop if column is full also
        while(userColumn < 1 || userColumn > 7|| (fullColumn(userColumn) == "full")){ 
            cout << endl << "Invalid move, try again." << endl;
            cout << endl << "It is " << user_string << " turn." << endl;
            cout << "In which column would you like to move (-1 to exit)? ";
            cin >> userColumn; //user choses column
            cout << endl;
            if (userColumn == -1){ //breaks out of loop
                theReset();
                break;
            }
        }

        if (userColumn == -1){ //breaks out of loop
            theReset();
            break;
        }
        
        placePiece(currentPlayer, userColumn); //places piece
        // displayBoard(); //prints board
        if (fullBoard() == "end"){ //checks if board is full
            break; //breaks out of loop if full
        }
        end_game = checkVertical(currentPlayer); //checks vertical win
        if (end_game == "play") end_game = checkHorizontal(currentPlayer); //checks horizontal win
        if (end_game == "play") end_game = checkDiagonal(currentPlayer); //checks diagonal win
        if (end_game == "end") winner = currentPlayer; //stores winner
        if (end_game == "play"){
            botMove(level); // bot makes move
            displayBoard(); //prints board
            if (fullBoard() == "end"){ //checks if board is full
                break; //breaks out of loop if full
            }
            end_game = checkVertical(botPlayer); //checks vertical win
            if (end_game == "play") end_game = checkHorizontal(botPlayer); //checks horizontal win
            if (end_game == "play") end_game = checkDiagonal(botPlayer); //checks diagonal win
            if (end_game == "end") winner = botPlayer; //stores winner
            }
        else{
            displayBoard(); //prints board
        }


        string user_color = ""; //used to create string for win

        if (winner == RED_PIECE){ //win for red
            user_color = "Red";
        }
        else{
            user_color = "Yellow"; //win for yellow
        }
        if (end_game == "end"){ //game over
            cout << endl << user_color << " wins!" << endl; //informs user who won
            if (winner != botPlayer){ //user won
                level += 1; //increases level
                cout << "You advanced to level " << level << "!" << endl;
            }
            else{ //bot won
                lives -= 1; //decreases lives
                if (lives > 0){
                    cout << "You have " << lives << " lives remaining." << endl;
                }
                else{
                    cout << "You have no lives remaining. Game over." << endl;
                    break; //ends game if no lives left
                }
            }
        }

    }
}