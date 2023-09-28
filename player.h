#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "board.h"

using namespace std;

//abstract class prototype for a player of a game of connect four
class Player{
    private:
        int player_number;
        string player_name;
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

        string get_player_name(){
            return player_name;
        }

        void set_player_name(string name){
            player_name = name;
        }

};

//class for playing the game as a human inputing moves via command line.
class Human_Player: public Player{
    private:
        string player_type = "human";

    public:
        Human_Player(int);
        ~Human_Player();

        //Gets a move from the user
        //Returns the column of the move as an int 0-6
        int get_move(Board *);

};

//class for a simple AI that chooses random moves
class Random_AI_Player: public Player{
    private:
        string player_name = "Random AI";

    public:
        Random_AI_Player(int);
        ~Random_AI_Player();

        int get_move(Board *);
};

//class for an AI that looks for winning moves
class Easy_AI_Player: public Player{
    private:
        string player_name = "Easy AI";

    public:
        Easy_AI_Player(int);
        ~Easy_AI_Player();

        int get_move(Board *);
};
#endif