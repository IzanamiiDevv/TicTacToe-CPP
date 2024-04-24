//Global Header
#include <iostream>
#include <ctime>
#include <string>

//Local Header
#include "./includes/logic.h"

using column = char;

int main() {
    column spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player;

    do{
        std::cout << "Select a Character" << '\n';
        std::cin >> player;
    }while(!(player == 'X' || player == 'O'));

    char computer = player == 'X' ? 'O':'X';
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