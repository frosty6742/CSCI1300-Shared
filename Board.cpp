#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m"
#define GREY "\033[48;2;128;128;128m"
#define RESET "\033[0m"

#include "Board.h"
#include <iostream>
#include <vector>

using namespace std;

// Declare
Board::Board() { _player_count = 0; }

void Board::setPlayerCount(int player_count) {
  _player_count = player_count;
  _playerDetails.resize(
      player_count,
      vector<int>(3, 0)); // Initialize player positions, IDs, and tracks
  for (int i = 0; i < player_count; i++) {
    _playerDetails[i][0] = i; // Assign player ID
    _playerDetails[i][2] = 3; // Default track number to 0
  }
}

// Initialize
void Board::initializeBoard() {
  for (int i = 0; i < 2; i++) { // Initializes two rows of tiles
    initializeTiles(i);
  }
}

void Board::initializeTiles(int rowNum) {
  Tile temp;
  int green_count = 0;
  int total_tiles = _BOARD_SIZE;

  for (int i = 0; i < total_tiles; i++) {
    if (i == 0) {
      temp = Tile("start", 1, 'Y'); // Start tile
    } else if (i == total_tiles - 1) {
      temp = Tile("end", 1, 'O'); // End tile
    } else if (green_count < 30 &&
               (rand() % (total_tiles - i) < 30 - green_count)) {
      temp = Tile("green", 1, 'G'); // Green tile
      green_count++;
    } else {
      int color_choice = rand() % 5;
      switch (color_choice) {
      case 0:
        temp = Tile("blue", 1, 'B');
        break;
      case 1:
        temp = Tile("pink", 1, 'P');
        break;
      case 2:
        temp = Tile("brown", 1, 'N');
        break;
      case 3:
        temp = Tile("red", 1, 'R');
        break;
      case 4:
        temp = Tile("purple", 1, 'U');
        break;
      }
    }
    _tiles[rowNum][i] = temp; // Adds tiles to an array for each row
  }
}

// Display
void Board::displayBoard() {
  for (int i = 0; i < 2; i++) { // Displays two tracks
    displayTrack(i);
    if (i < 2 - 1) {
      cout << endl;
    }
  }
}

void Board::displayTrack(int trackNum) {
  for (int i = 0; i < _BOARD_SIZE; i++) {
    displayTile(trackNum, i);
  }
  cout << endl;
}

void Board::displayTile(int trackNum, int pos) {
  string color;
  switch (_tiles[trackNum][pos].color) {
  case 'R':
    color = RED;
    break;
  case 'G':
    color = GREEN;
    break;
  case 'B':
    color = BLUE;
    break;
  case 'P':
    color = PINK;
    break;
  case 'N':
    color = BROWN;
    break;
  case 'U':
    color = PURPLE;
    break;
  case 'O':
    color = ORANGE;
    break;
  case 'Y':
    color = GREY;
    break;
  default:
    color = GREY;
    break;
  }

  // Display Character Number on Tile
  bool playerPresent = false;
  std::string playersOnTile = "";

  for (int i = 0; i < _player_count; i++) {
    if (_playerDetails[i][2] == trackNum && _playerDetails[i][1] == pos) {
      if (!playersOnTile.empty()) {
        playersOnTile += " & ";
      }
      playersOnTile += std::to_string(i + 1);
      playerPresent = true;
    }
  }

  if (playerPresent) {
    cout << color << "|" << playersOnTile << "|" << RESET;
  } else {
    cout << color << "| |" << RESET;
  }
}

// Setters and Getters
void Board::setPlayerPosition(int player_index, int pos) {
  if (player_index >= 0 && player_index < _player_count) {
    _playerDetails[player_index][1] = pos;
  }
  // TODO: Handle over-position scenario, return if win condition is met.
}

int Board::getPlayerPosition(int player_index) {
  return _playerDetails[player_index][1];
}

void Board::setPlayerTrack(int player_index, int trackNum) {
  _playerDetails[player_index][2] = trackNum;
}

// Helper Functions
bool Board::isPlayerOnTile(int player_index, int pos) {
  return _playerDetails[player_index][1] == pos;
}
