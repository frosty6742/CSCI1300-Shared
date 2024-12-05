#include "Board.h"
#include <iostream>

// example of the methods, should structure this to be inside your game loop

Board board;     // Instance of the Board class
int playerCount; // Number of players in the game

int main() {
  board.setPlayerCount(playerCount);

  cout << "Initial Board State:" << endl;
  board.initializeBoard();
  board.displayBoard();

  // set the track for each players
  int playerId = 1;
  board.setPlayerTrack(playerId, 0);

  // set the player to the new position
  int pos = 5;
  board.setPlayerPosition(playerId, pos);
  board.displayBoard();
}
