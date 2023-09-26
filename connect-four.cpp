#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "board.h"
#include "player.h"
#include "game.h"

using namespace std;

int wmain(){

    srand(time(NULL));

    Board b;
    int player_num = 1;
    int counter = 0;

    for(int i = 0; i < 50; i++){
        int rand_col = rand() % 7;
        if (b.valid_column(rand_col) == 1){
            b.play_move(player_num, rand_col);
            player_num++;
            if (player_num == 3){
                player_num = 1;
            }
        }
        if (i % 5 == 0){
            b.print_board();
            cout << endl;
        }
    }

    return 0;
}