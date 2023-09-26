#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "board.h"

using namespace std;

class Player{
    private:
        int player_number;
        string player_type;
        char symbol;

    public:
        Player();
        ~Player();
        virtual int get_move(Board*);

};

#endif