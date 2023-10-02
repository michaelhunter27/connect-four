# connect-four

A terminal application to play the game connect four written in c++.

## Compiling:
A Makefile is included for compiling the project.  Use the command `make connect-four`.  This should produce an executable file `connect-four.exe`. The command `make clean` can be used to clean up unnecessary object files produced by the build.

The compiler uses flag `-g` so that gdb can be used for debugging.  The flag `-municode` is passed to the compiler in conjunction with `wmain()` substituted for `main()` in `connect-four.cpp`.  Those are used just to get it to compile on my machine.  I honestly don't really completely understand why they are necessary.

## Running the Program
To play the game, run the executable `connect-four.exe`.  The program will prompt you to select Players 1 and 2.  Input a number to select either a human player or a computer AI.  If human is selected, it will prompt the user to input a name.  If an AI player is selected, no name is necessary.

The game supports human vs. human, human vs. AI, and AI vs. AI games.  The AI turns are timed, so that they do not play their move instantaneously.  Human moves are inputed as a column number (1-7) via commandline.

## About the AIs
Random AI selects a random valid move.

Easy AI looks for a winning move, and will play that move if found.  Failing that, it will look for a winning move for its opponent and play that move to take it away from its opponent.  If neither of those moves are found, it plays a random valid move.

Medium AI selects a move by running monte carlo game simulations between two random AIs.  It selets whichever initial move results in the most winning games.

Hard AI selects a move by running monte carlo game simulations between two Easy AIs.  It selets whichever initial move results in the most winning games.  These simulated games are more realistic because they account for the simulated players actively trying to win the game.  Hard AI also does significantly more simulated games than Medium AI.