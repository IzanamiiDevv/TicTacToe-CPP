//Global Header
#include <iostream>
#include <ctime>
#include <string>

//Local Header
#include "./../includes/logic.h"



namespace Logic {
    void drawBoard(char *spaces){
        std::cout << '\n';
        std::cout << "     |     |     " << '\n';
        std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
        std::cout << "_____|_____|_____" << '\n';
        std::cout << "     |     |     " << '\n';
        std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
        std::cout << "_____|_____|_____" << '\n';
        std::cout << "     |     |     " << '\n';
        std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
        std::cout << "     |     |     " << '\n';
        std::cout << '\n';
    };
    void playerMove(char *spaces, char player){
        int number;
        do{
            std::cout << "Enter a spot to place a marker (1-9): ";
            std::cin >> number;
            number--;
            if(spaces[number] == ' '){
            spaces[number] = player;
            break; 
            }
        }while(!number > 0 || !number < 8);
    };
    void computerMove(char *spaces, char computer){
        int number;
        srand(time(0));

        while(true){
            number = rand() % 9;
            if(spaces[number] == ' '){
                spaces[number] = computer;
                break;
            }
        }
    };
    bool checkWinner(char *spaces, char player,char computer){
        int possibleOutCome[8][3] = {
            //horizontal
            {0,1,2},
            {3,4,5},
            {6,7,8},

            //vertical
            {0,3,6},
            {1,4,7},
            {2,5,8},

            //diagonal
            {0,4,8},
            {2,4,6}
        };

        for (int i = 0; i < 8; i++) {
            int a = possibleOutCome[i][0];
            int b = possibleOutCome[i][1];
            int c = possibleOutCome[i][2];
            if (spaces[a] != ' ' && spaces[a] && spaces[a] == spaces[b] && spaces[a] == spaces[c]) {
                if(spaces[a] == player){
                    std::cout << "Player Won!" << std::endl;
                }else {
                    std::cout << "Computer Won!" << std::endl;
                }
                return true;
            }
        } 

        return false;
    };
    bool checkTie(char *spaces){
        for(int i = 0; i < 9; i++){
            if(spaces[i] == ' '){
                return false;
            }
        }
        std::cout << "IT'S A TIE!\n";
        return true;
    };
}