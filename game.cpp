#include <iostream>
#include <cstdlib>


#include "player.h"
#include "board.h"
#include "game.h"

using namespace std;

Game::Game(){
    players = new Player*[2];
    players[0] = NULL;
    players[1] = NULL;
    turn = 0;
}


//cleans up allocated memory
Game::~Game(){
    if (players != NULL){
        if(players[0] != NULL){
            delete players[0];
        }
        if(players[1] != NULL){
            delete players[1];
        }
        delete [] players;
    }
}


//After the user selects players for the game, a game of connect four is played
void Game::play_game(){
    set_player_types();
    set_symbols('X', 'O');  
    
    turn = 1;

    //game loop
    while (game_board.game_over() == 0){
        //print board
        print_game();
        
        time_t t = clock();
        if (players[(turn-1)%2]->get_player_name().find("AI") != string::npos){
            cout << players[(turn-1)%2]->get_player_name() << " is thinking." << endl;
        }

        //get move
        int move_col = players[(turn-1)%2]->get_move(&game_board);
        
        //timer to ensure that the AI takes at least one second before playing
        while (clock() - t < 1000){}

        //add move to game board
        game_board.play_move(players[(turn-1)%2]->get_number(), move_col);
          
        turn++;
    }
    print_game();
    print_results();  
}


//promts the user to select a type of player
//returns a number 1-5 representing that choice
int Game::get_player_type(){
    cout << "select player type (1-5)" << endl;
    cout << "1: human" << endl;
    cout << "2: AI (random)" << endl;
    cout << "3: AI (easy)" << endl;
    cout << "4: AI (medium)" << endl;
    cout << "5: AI (hard)" << endl;
    int input = 0;
    while (input < 1 || input > 5){
        cin >> input;
        if (input < 1 || input > 5){
            cout << "please enter a number 1-5" << endl;
        }
    }
    return input;
}


//allows the user to select who will play as Player 1 and Player 2
//instantiates Player objects for those players
void Game::set_player_types(){
    for (int p = 1; p <= 2; p++){
        system("clear");
        cout << "Player " << p << ": ";
        int player_selection = get_player_type();

        //human player
        if (player_selection == 1){
            players[p-1] = new Human_Player(p);
            cout << "Name: ";
            string name;
            cin >> name;
            players[p-1]->set_player_name(name);
        }

        //random AI
        if (player_selection == 2){
            players[p-1] = new Random_AI_Player(p);
        }

        //Easy AI
        if (player_selection == 3){
            players[p-1] = new Easy_AI_Player(p);
        }

    }
}


//sets the symbols that will be displayed on the board for each player
void Game::set_symbols(char c1, char c2){
    players[0]->set_symbol(c1);
    players[1]->set_symbol(c2);
}


//prints the board to the terminal
void Game::print_game(){
    system("clear");
    for (int r = 0; r < 6; r++){
        
        for (int c = 0; c < 7; c++){
            cout << "|";
            if (game_board.get_cell(r, c) == 0){
                cout << " ";
                continue;
            }
            for (int n = 1; n <= 2; n++){
                if (game_board.get_cell(r, c) == players[n-1]->get_number()){
                    cout << players[n-1]->get_symbol();
                    break;
                }
            }
        }
        cout << "|" << endl;
    }
    cout << "---------------" << endl;
    cout << " 1 2 3 4 5 6 7 " << endl;
}


//prints the results of a completed game (i.e., who won, or if it was a tie)
void Game::print_results(){
    int result = game_board.game_over();
    if (result == -1){
        cout << "It's a tie!" << endl;
    }
    if (result == players[0]->get_number()){
        cout << players[0]->get_player_name();
        cout << " (" << players[0]->get_symbol() << ")" << " wins!";
    }
    if (result == players[1]->get_number()){
        cout << players[1]->get_player_name();
        cout << " (" << players[1]->get_symbol() << ")" << " wins!";
    }
}