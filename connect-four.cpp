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

    Game G;
    G.play_game();

    return 0;
}