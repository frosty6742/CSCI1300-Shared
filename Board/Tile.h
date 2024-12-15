//Owen C, Tristan H
#pragma once
#include <iostream>

using namespace std;

struct Tile {
    string type; 
    int _NumTiles;
    char color;       
    
  Tile () {
      type = "empty";
      _NumTiles = 0;
      color = ' ';
    }

  Tile(string t, int num, char c) {
    type = t;
    _NumTiles = num;
    color = c;
  }
};


