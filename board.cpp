
#include <iostream>
#include <string>

#include "board.h"

using namespace std;


//checks for four in a row vertically.
//returns the value of the four in a row if found
//returns 0 if no win is found
int Board::check_win_vert(){
    for (int r = 0; r < 3; r++){
        for (int c = 0; c < 7; c++){
            int val = grid[r][c];
            if (val != 0){
                if ( (grid[r+1][c] == val) &&
                     (grid[r+2][c] == val) &&
                     (grid[r+3][c] == val)){
                    return val;
                }
            }
        }
    }
    return 0;
}

//checks for four in a row horizontally.
//returns the value of the four in a row if found
//returns 0 if no win is found
int Board::check_win_horz(){
    for (int r = 0; r < 6; r++){
        for (int c = 0; c < 4; c++){
            int val = grid[r][c];
            if (val != 0){
                if ( (grid[r][c+1] == val) &&
                     (grid[r][c+2] == val) &&
                     (grid[r][c+3] == val)){
                    return val;
                }
            }
        }
    }
    return 0;
}


//checks for four in a row diagonally (both ways)
//returns the value of the four in a row if found
//returns 0 if no win is found
int Board::check_win_diag(){
    for (int r = 0; r < 3; r++){
        for (int c = 0; c < 4; c++){
            int val = grid[r][c];
            if (val != 0){
                if ( (grid[r+1][c+1] == val) &&
                     (grid[r+2][c+2] == val) &&
                     (grid[r+3][c+3] == val)){
                    return val;
                }
            }
        }
    }
    
    for (int r = 0; r < 3; r++){
        for (int c = 3; c < 7; c++){
            int val = grid[r][c];
            if (val != 0){
                if ( (grid[r+1][c-1] == val) &&
                     (grid[r+2][c-2] == val) &&
                     (grid[r+3][c-3] == val)){
                    return val;
                }
            }
        }
    }
    return 0;
}


//Contructor.  Initializes grid, etc.
Board::Board(){
    for (int r = 0; r < 6; r++){
        for (int c = 0; c < 7; c++){
            grid[r][c] = 0;
        }
    }
    num_moves = 0;
}


//destructor
Board::~Board(){

}



//returns player value of winner if there is a four in a row
//returns -1 if the board is full with no four in a row (tie)
//returns 0 otherwise
int Board::game_over(){
    int result = 0;
    if ((result = check_win_diag()) != 0){
        return result;
    }
    if ((result = check_win_vert()) != 0){
        return result;
    }
    if ((result = check_win_horz()) != 0){
        return result;
    }
    if (num_moves == 42){
        return -1;
    }
    return 0;
}


//returns 1 if there is space in the column for a piece to be placed
//returns 0 if the column is full
int Board::valid_column(int col){
    if (grid[0][col] == 0){
        return 1;
    }
    else{
        return 0;
    }
}


//sets the bottom-most empty cell of column col to player_value
//increments num_moves to reflect the newly placed piece
void Board::play_move(int player_value, int col){
    for (int r = 5; r >= 0; r--){
        if (grid[r][col] == 0){
            grid[r][col] = player_value;
            num_moves++;
            break;
        }
    }
}


void Board::copy_board_from(Board){

}


void Board::copy_board_to(Board *){

}


//prints numerical values of each cell in grid
//NOTE: not formatted for gameplay.  Use Game::print_game() instead
void Board::print_board(){
    for (int r = 0; r < 6; r++){
        for (int c = 0; c < 7; c++){
            cout << grid[r][c];
        }
        cout << endl;
    }
}