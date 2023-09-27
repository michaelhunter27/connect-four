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
        virtual ~Player();
        virtual int get_move(Board*) = 0;

        void set_number(int num){
            if (num != 0){
                player_number = num;
            }
        }

        int get_number(){
            return player_number;
        }

        void set_symbol(char c){
            symbol = c;
        }

        char get_symbol(){
            return symbol;
        }

};

//class for playing the game as a human inputing moves via command line.
class Human_Player: public Player{
    private:
        string player_type = "human";

    public:
        Human_Player();

        ~Human_Player();

        //Gets a move from the user
        //Returns the column of the move as an int 0-6
        int get_move(Board *);

};



#endif