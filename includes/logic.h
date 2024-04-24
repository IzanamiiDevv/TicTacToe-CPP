#pragma once

namespace Logic {
    void drawBoard(std::string *spaces);
    void playerMove(std::string *spaces, char player);
    void computerMove(std::string *spaces, char computer);
    bool checkWinner(std::string *spaces, char player,char computer);
    bool checkTie(std::string *spaces);
}