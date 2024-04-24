#pragma once

namespace Logic {
    void drawBoard(char *spaces);
    void playerMove(char *spaces, char player);
    void computerMove(char *spaces, char computer);
    bool checkWinner(char *spaces, char player,char computer);
    bool checkTie(char *spaces);
}