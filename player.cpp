/*
Each type of player is a different derived class from the prototype class Player.
These different types of player allow for different game modes (human vs human,
human vs AI, different AI strengths).
*/

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "player.h"
#include "board.h"

using namespace std;


Player::Player(){}
Player::~Player(){}


//Human_Player class implementation
//class for playing the game as a human inputing moves via command line.
Human_Player::Human_Player(int p){
    set_number(p);
}

Human_Player::~Human_Player(){}

// Gets a move from the user
// Returns the column of the move as an int 0-6
int Human_Player::get_move(Board *b){
    int input = 0;
    while (input < 1 || input > 7){
        cout << "input column (1-7):";
        cin >> input;
        if (input >= 1 && input <= 7){
            if (b->valid_column(input - 1)){
                return input - 1;
            }
            else{
                cout << "That column is full" << endl;
                input = 0;
            }
        }
    }
    return 0;
}


//Random_AI_Player class implementation
Random_AI_Player::Random_AI_Player(int p){
    set_number(p);
}
Random_AI_Player::~Random_AI_Player(){}

int Random_AI_Player::get_move(Board *b){
    clock_t t = clock();
    srand(time(NULL));
    int rand_col;
    do{
        rand_col = rand() % 7;
    } while (b->valid_column(rand_col) == 0);
    cout << "Player " << get_number() << " is thinking." << endl;
    while (clock() - t < 1000){}
    return rand_col;
}
