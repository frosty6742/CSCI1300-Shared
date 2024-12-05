#pragma once
#include "Tile.h"
#include <vector>

class Board {
private:
  static const int _BOARD_SIZE = 52;
  Tile _tiles[2][_BOARD_SIZE];
  static const int _MAX_PLAYERS = 5;
  vector<vector<int>> _playerDetails; // holds player id, player position
  int _player_count;
  int _player_position[_MAX_PLAYERS];
  void displayTile(int player_index, int pos);
  void initializeTiles(int player_index);
  bool isPlayerOnTile(int player_index, int pos);

public:
  Board();
  void setPlayerCount(int player_count);
  void displayTrack(int player_index);
  void initializeBoard();
  void displayBoard();
  int getPlayerPosition(int player_index);
  void setPlayerPosition(int player_index, int pos);
  void setPlayerTrack(int player_index, int);
};
