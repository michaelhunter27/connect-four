#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "board.h"
#include "player.h"

using namespace std;

class Game{
    private:
        Board game_board;
        Player** players;
        int turn;

    public:
        Game();
        ~Game();
        void play_game();

        int get_player_type();
        void set_player_types();
        void set_symbols(char, char);
        
        void print_game();
        void print_results();

};

#endif