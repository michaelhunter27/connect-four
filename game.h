#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "board.h"
#include "player.h"

using namespace std;

class Game{
    private:
        Board b;
        Player* players;
        int turn;

    public:
        Game();
        ~Game();
        void set_player(int);//????
        void play_game();
        void print_game();

};

#endif