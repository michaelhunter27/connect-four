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
#include "game.h"

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
    set_player_name("Random AI");
}
Random_AI_Player::~Random_AI_Player(){}

//Random AI chooses a random valid move
//returns the column number of the move (0-6)
int Random_AI_Player::get_move(Board *b){
    int rand_col;
    do{
        rand_col = rand() % 7;
    } while (b->valid_column(rand_col) == 0);
    return rand_col;
}


//Easy_AI_Player class implementation
Easy_AI_Player::Easy_AI_Player(int p){
    set_number(p);
    set_player_name("Easy AI");
}
Easy_AI_Player::~Easy_AI_Player(){}


//Easy AI looks for a winning move and selects that if possible.  If there is no winning move,
//it looks next to see if its opponent has a winning move, and will select that.
//If neither exist, it selects a random valid move.
int Easy_AI_Player::get_move(Board *b){
    Board new_board;
    new_board.copy_board_from(*b);

    //look for winning move
    for(int i = 0; i < 7; i++){
        if (new_board.valid_column(i)){
            Board temp_board;
            temp_board.copy_board_from(new_board);
            temp_board.play_move(get_number(), i);
            if (temp_board.game_over() == get_number()){
                return i;
            }
        }
    }

    //note: Player and opponent numbers are assumed to be 1 and 2
    int opponent_num = (get_number() % 2) + 1;
    
    //look for opponent winning move
    for (int i = 0; i < 7; i++){
        if (new_board.valid_column(i)){
            Board temp_board;
            temp_board.copy_board_from(new_board);
            temp_board.play_move(opponent_num, i);
            if (temp_board.game_over() == opponent_num){
                return i;
            }
        }
    }

    //if no move has been found, returns a random valid move
    Random_AI_Player R(get_number());
    return R.get_move(b);
}


//Medium AI class implementation
Medium_AI_Player::Medium_AI_Player(int p){
    set_number(p);
    set_player_name("Medium AI");
}

Medium_AI_Player::~Medium_AI_Player(){}


//Medium AI simulates random games to see which move has the best chance of winning
int Medium_AI_Player::get_move(Board *b){
    int best_move = -1;
    int best_move_performance = -1;
    int result = -1;
    int move_performance;
    Board new_board;
    
    Game new_game;

    for (int i = 0; i < 7; i++){
        new_board.copy_board_from(*b);
        if (new_board.valid_column(i) == 1){
            new_board.play_move(get_number(), i);
            move_performance = 0;
            Random_AI_Player current_player(get_number());
            Random_AI_Player opponent_player((get_number()%2)+1);
            for(int n = 0; n < 20; n++){ 
                result = new_game.simulate_game(&opponent_player, &current_player, &new_board);
                if (result == get_number()){
                    move_performance += 5;
                }
                if (result == -1){
                    move_performance += 1;
                }
            }
        
            if (move_performance > best_move_performance){
                best_move = i;
                best_move_performance = move_performance;
            }
        }
    }
    return best_move;
}