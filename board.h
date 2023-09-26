#ifndef BOARD_H
#define BOARD_H

#include<iostream>

using namespace std;

class Board{
    private:
        int grid[6][7];
        int num_moves;

        int check_win_vert();
        int check_win_horz();
        int check_win_diag();

    public:
        Board();
        ~Board();
        int game_over();
        int valid_column(int);
        void play_move(int, int);
        void copy_board_from(Board);
        void copy_board_to(Board *);
        void print_board();


};

#endif