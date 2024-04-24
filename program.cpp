//Global Header
#include <iostream>
#include <ctime>

//Local Header
#include "./includes/logic.h"

using column = std::string;

int main() {
    column spaces[9] = {"","","","","","","","",""};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    Logic::drawBoard(spaces);

    while(running){
        Logic::playerMove(spaces, player);
        Logic::drawBoard(spaces);
        if(Logic::checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(Logic::checkTie(spaces)){
            running = false;
            break;
        }

        Logic::computerMove(spaces, computer);
        Logic::drawBoard(spaces);
        if(Logic::checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(Logic::checkTie(spaces)){
            running = false;
            break;
        }
    }
    std::cout << "Thanks for playing!\n";
    return 0;
}