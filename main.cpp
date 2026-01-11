#include "ConnectFour.h"
#include <iostream>
using namespace std;

int main() 
{
    ConnectFour game; //object to call function
    int choice = 0; //menu choice
    while (choice != 2){
        cout << "Play Connect Four with a Bot!" << endl;
        cout << "1. Play now" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice (1-2): ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Play now selected." << endl;
                game.theReset();
                while(game.getLives() != 0){
                    game.playGame(); //connect four game;
                }
                break;
            case 2:
                break; //exits game
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }
    cout << "Exiting the game." << endl;

    return 0;

}


