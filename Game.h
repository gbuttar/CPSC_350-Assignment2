#include <iostream>
#ifndef GAME_H
#define GAME_H
#include "Grid.h"
using namespace std;

class Game{
public:
  //variables
  string gameMode;
  int userMode;
  int countNeighbor;
  Game(Grid*g, int userMode); //method
  Grid* gridCopy; //pointer to grid
  char** gridOne; 
  char** gridTwo;

};
#endif
